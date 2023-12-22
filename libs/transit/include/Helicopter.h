#ifndef Helicopter_H_
#define Helicopter_H_

#include "IEntity.h"
#include "IStrategy.h"

/**
 * @class Helicopter
 * @brief Represents a helicopter.
 */
class Helicopter : public IEntity {
 public:
  /**
   * @brief Helicopter are created with a name
   * @param obj JSON object containing the drone's information
   */
  Helicopter(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Helicopter();

  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
