#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "IObserver.h"
#include "ISubject.h"

class Package;

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/**
 * @class Drone
 * @brief Represents a drone in a physical system. Drones move using euler
 * integration based on a specified velocity and direction.
 */
class Drone : public IEntity, public ISubject {
 public:
  /**
   * @brief Drones are created with a name
   * @param obj JSON object containing the drone's information
   */
  Drone(JsonObject &obj);

  /**
   * @brief Destructor
   */
  ~Drone();

  /**
   * @brief Gets the next delivery in the scheduler
   */
  void getNextDelivery();

  /**
   * @brief Updates the drone's position
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief Removing the copy constructor operator
   * so that drones cannot be copied.
   */
  Drone(const Drone &drone) = delete;

  /**
   * @brief Removing the assignment operator
   * so that drones cannot be copied.
   */
  Drone &operator=(const Drone &drone) = delete;

  /**
    * @brief Attaches the specified observer to the drone.
    *
    * @details In other words, makes the specified observer subscribe to the drone.
    *
    * @param observer The observer to be attached.
    */
  void attach(IObserver *observer) override;

  /**
    * @brief Detaches the specified observer from the drone.
    *
    * @details In other words, makes the specified observer unsubscribe from the drone.
    *
    * @param observer The observer to be detached.
    */
  void detach(IObserver *observer) override;

  /**
   * @brief Notifies the observers about the drone.
   * 
   * @param message The message to notify the observers with.
   */
  void notify(const std::string &message) override;

 private:
  bool available = false;
  bool pickedUp = false;
  Package *package = nullptr;
  IStrategy *toPackage = nullptr;
  IStrategy *toFinalDestination = nullptr;

  bool sent;
};

#endif
