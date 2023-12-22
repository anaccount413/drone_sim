#include "DroneObserver.h"

DroneObserver::DroneObserver(Drone &drone) : drone(drone) {
  this->drone.attach(this);
}

DroneObserver::~DroneObserver() {}

void DroneObserver::update(const std::string &message) {
  JsonObject details;

  if (message == "received") {
    std::cout << this->drone.getName()
      << " has delivered a package" << std::endl;
    details["message"] = this->drone.getName() + " has delivered a package\n";
    std::cout << details << std::endl;
  } else if (message == "picked") {
    std::cout << this->drone.getName()
    << " has picked up a package" << std::endl;
    details["message"] = this->drone.getName() + " has picked up a package\n";
  } else if (message == "sending") {
    std::cout << this->drone.getName() << " is sending a package" << std::endl;
    details["message"] = this->drone.getName() + " is sending a package\n";
  } else {
    std::cout << "Drone: Unknown message" << std::endl;
    details["message"] = "Drone: Unknown Message\n";
  }
  drone.getModel()->getController().sendEventToView("Notify", details);
}
