#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IObserver.h"
#include "ISubject.h"

class Robot;

/**
 * @class Package
 * @brief Represents a package in a physical system.
 */
class Package : public IEntity, public ISubject {
 public:
  /**
   * @brief Constructor
   * @param obj JSON object containing the package's information
   */
  Package(JsonObject &obj);

  /**
   * @brief Destructor
   */
  ~Package();

  /**
   * @brief Gets the Package's destination
   * @return The Package's destination
   */
  Vector3 getDestination() const;

  /**
   * @brief Returns the name of the strategy for this package
   * 
   * @returns String name of strategy
  */
  std::string getStrategyName() const;

  /**
   * @brief Set the Strategy Name
   *
   * @param strategyName_ Strategy name
   */
  void setStrategyName(std::string strategyName_);

  /**
   * @brief Updates the Package
   * 
   * @param dt difference in time since last update
  */
  void update(double dt);

  /**
   * @brief Sets the attributes for delivery
   * 
   * @param owner Robot for the package to be delivered to
  */
  void initDelivery(Robot *owner);

  /**
   * @brief Gives the robot/owner this package
  */
  void handOff();

  bool requiresDelivery = true;

  /**
    * @brief Attaches the specified observer to the package.
    *
    * @details In other words, makes the specified observer subscribe to the package.
    *
    * @param observer The observer to be attached.
    */
  void attach(IObserver *observer) override;

  /**
    * @brief Detaches the specified observer from the package.
    *
    * @details In other words, makes the specified observer unsubscribe from the package.
    *
    * @param observer The observer to be detached.
    */
  void detach(IObserver *observer) override;

  /**
   * @brief Notifies the observers about the package.
   * 
   * @param message The message to notify the observers with.
   */
  void notify(const std::string &message) override;

 private:
  Vector3 destination;
  std::string strategyName;
  Robot *owner = nullptr;
};

#endif  // PACKAGE_H
