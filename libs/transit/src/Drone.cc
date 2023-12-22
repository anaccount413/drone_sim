#define _USE_MATH_DEFINES

#include "Drone.h"
#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "BfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "SpinDecorator.h"
#include "Package.h"
#include "DroneObserver.h"

Drone::Drone(JsonObject &obj) : IEntity(obj) {
  // Add drone observer by default
  new DroneObserver(*this);
  sent = false;
  available = true;
}

Drone::~Drone() {
  if (toPackage) delete toPackage;
  if (toFinalDestination) delete toFinalDestination;
}

void Drone::getNextDelivery() {
  if (model && model->scheduledDeliveries.size() > 0) {
    package = model->scheduledDeliveries.front();
    model->scheduledDeliveries.pop_front();

    if (package) {
      available = false;
      pickedUp = false;

      Vector3 packagePosition = package->getPosition();
      Vector3 finalDestination = package->getDestination();

      toPackage = new BeelineStrategy(position, packagePosition);

      std::string strat = package->getStrategyName();
      if (strat == "astar") {
        toFinalDestination =
            new JumpDecorator(
                new AstarStrategy(
                    packagePosition,
                    finalDestination,
                    model->getGraph()));
      } else if (strat == "dfs") {
        toFinalDestination =
            new SpinDecorator(
                new JumpDecorator(
                    new DfsStrategy(
                        packagePosition,
                        finalDestination,
                        model->getGraph())));
      } else if (strat == "bfs") {
        toFinalDestination =
            new SpinDecorator(
                new SpinDecorator(
                    new BfsStrategy(
                        packagePosition,
                        finalDestination,
                        model->getGraph())));
      } else if (strat == "dijkstra") {
        toFinalDestination =
            new JumpDecorator(
                new SpinDecorator(
                    new DijkstraStrategy(
                        packagePosition,
                        finalDestination,
                        model->getGraph())));
      } else {
        toFinalDestination = new BeelineStrategy(
            packagePosition,
            finalDestination);
      }
    }
  }
}

void Drone::update(double dt) {
  if (available)
    getNextDelivery();

  if (toPackage) {
    toPackage->move(this, dt);

    if (toPackage->isCompleted()) {
      notify("picked");
      delete toPackage;
      toPackage = nullptr;
      pickedUp = true;
    }
  } else if (toFinalDestination) {
    toFinalDestination->move(this, dt);

    if (package && pickedUp) {
      // makes sure it only says delivering once
      if (!sent) {
        notify("sending");
        sent = true;
      }

      package->setPosition(position);
      package->setDirection(direction);
    }

    if (toFinalDestination->isCompleted()) {
      sent = false;
      notify("received");

      delete toFinalDestination;
      toFinalDestination = nullptr;
      package->handOff();
      package = nullptr;
      available = true;
      pickedUp = false;
    }
  }
}

void Drone::attach(IObserver *observer) {
  observers.push_back(observer);
}

void Drone::detach(IObserver *observer) {
  observers.remove(observer);
}

void Drone::notify(const std::string &message) {
  for (IObserver *observer : observers) {
    observer->update(message);
  }
}
