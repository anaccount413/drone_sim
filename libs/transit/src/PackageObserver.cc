#include "PackageObserver.h"

PackageObserver::PackageObserver(Package &package) : package(package) {
  package.attach(this);
}

PackageObserver::~PackageObserver() {}

void PackageObserver::update(const std::string &message) {
  JsonObject details;

  if (message == "scheduled") {
    details["message"] = package.getName() + " has been scheduled\n";
  } else if (message == "received") {
    details["message"] = package.getName() + " has been delivered\n";
  }

  package.getModel()->getController().sendEventToView("Notify", details);
}
