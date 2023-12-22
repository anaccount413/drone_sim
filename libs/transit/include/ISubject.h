#ifndef ISUBJECT_H_
#define ISUBJECT_H_

#include "IObserver.h"
#include "IEntity.h"

#include <list>

/**
 * @class ISubject
 * @brief Represents an observer's subject
 */
class ISubject {
 public:
  /**
   * @brief A virtual destructor for ISubject.
   */
  virtual ~ISubject();

  /**
   * @brief Attaches the specified observer to this subject.
   *
   * @details In other words, makes the specified observer subscribe to this subject.
   *
   * @param observer The observer to be attached.
   */
  virtual void attach(IObserver *observer) = 0;

  /**
   * @brief Detaches the specified observer from this subject.
   *
   * @details In other words, makes the specified observer unsubscribe from this subject.
   *
   * @param observer The observer to be detached.
   */
  virtual void detach(IObserver *observer) = 0;

  /**
   * @brief Notifies all attached observers with the specified message.
   *
   * @param message The message to be sent to all attached observers.
   */
  virtual void notify(const std::string &message) = 0;

 protected:
  std::list<IObserver *> observers;
};

#endif
