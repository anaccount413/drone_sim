#include "Package.h"
#include "Robot.h"
#include "PackageObserver.h"

Package::Package(JsonObject &obj) : IEntity(obj) {
  // Add package observer by default
  new PackageObserver(*this);
}

Package::~Package() {}

Vector3 Package::getDestination() const {
  return destination;
}

std::string Package::getStrategyName() const {
  return strategyName;
}

void Package::setStrategyName(std::string strategyName_) {
  strategyName = strategyName_;
}

void Package::update(double dt) {}

void Package::initDelivery(Robot* owner) {
  this->owner = owner;
  owner->requestedDelivery = false;
  requiresDelivery = false;
  destination = owner->getPosition();
  notify("scheduled");
}

void Package::handOff() {
  if (owner) {
    owner->receive(this);
    notify("received");
  }
}

void Package::attach(IObserver *observer) {
  observers.push_back(observer);
}

void Package::detach(IObserver *observer) {
  observers.remove(observer);
}

void Package::notify(const std::string& message) {
  for (IObserver *observer : observers) {
    observer->update(message);
  }
}
