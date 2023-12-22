#ifndef PACKAGE_OBSERVER_H
#define PACKAGE_OBSERVER_H

#include "IObserver.h"
#include "SimulationModel.h"
#include "IController.h"
#include "Package.h"

/**
 * @class PackageObserver
 * @brief Represents a package observer that outputs notifications about a package.
 */
class PackageObserver : public IObserver {
 public:
  /**
   * @brief Constructs a package observer
   *
   * @param package The package that will be observed.
   */
  PackageObserver(Package &package);

  /**
   * @brief A destructor for PackageObserver.
   */
  ~PackageObserver();

  /**
   * @brief Sends an update/notification about the package
   *
   * @details Notifications are sent when the observed package is received by the robot.
   *
   * @param message: A message about what the package has done
   */
  void update(const std::string &message) override;

 private:
  Package &package;
};

#endif
