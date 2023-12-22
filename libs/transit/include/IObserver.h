#ifndef IOBSERVER_H_
#define IOBSERVER_H_

#include <vector>
#include "IEntity.h"

/**
 * @class IObserver
 * @brief Represents an observer for an entity
 *
 * An observer has an update method which outputs some notification about the entity it is tracking
 */
class IObserver {
 public:
  /**
   * @brief A virtual destructor for IObserver.
   */
  virtual ~IObserver() {}

  /**
  * @brief Sends an update/notification about the subject
  *
  * @param message a message about what the subject has done
  */
  virtual void update(const std::string &message) = 0;
};

#endif
