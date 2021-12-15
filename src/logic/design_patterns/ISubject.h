
#ifndef AP_DOODLE_GAME_ISUBJECT_H
#define AP_DOODLE_GAME_ISUBJECT_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "IObserver.h"

class ISubject {
public:
    virtual ~ISubject(){};
    virtual void Attach(std::shared_ptr<IObserver> observer) = 0;
    virtual void Detach(std::shared_ptr<IObserver> observer) = 0;
    virtual void NotifyPosition(float xpos, float ypos) = 0;
    virtual void NewMaxHeigh(float ypos) = 0;
    virtual void NotifyReset() = 0;
};


#endif //AP_DOODLE_GAME_ISUBJECT_H
