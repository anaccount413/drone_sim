#include "ISubject.h"

ISubject::~ISubject() {
  for (IObserver *observer : observers) {
    delete observer;
  }
}
