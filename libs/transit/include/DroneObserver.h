#ifndef DRONE_OBSERVER_H
#define DRONE_OBSERVER_H

#include "IObserver.h"
#include "IController.h"
#include "ISubject.h"
#include "SimulationModel.h"
#include "Drone.h"

/**
 * @class DroneObserver
 * @brief Represents a drone observer that outputs notifications about a drone.
 */
class DroneObserver : public IObserver {
 public:
  /**
   * @brief Constructs a drone observer
   *
   * @param drone The drone that will be observed.
   */
  DroneObserver(Drone &drone);

  /**
   * @brief A destructor for DroneObserver.
   */
  ~DroneObserver();

  /**
   * @brief Sends an update/notification about the drone
   *
   * @param message: a message about what the drone has done
  */
  void update(const std::string &message) override;

 private:
  Drone &drone;
};

#endif
