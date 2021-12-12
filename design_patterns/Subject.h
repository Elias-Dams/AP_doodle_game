
#ifndef AP_DOODLE_GAME_SUBJECT_H
#define AP_DOODLE_GAME_SUBJECT_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "Observer.h"


class Subject {

public:
    virtual ~Subject(){};
    virtual void Attach(std::shared_ptr<Observer> observer) = 0;
    virtual void Detach(std::shared_ptr<Observer> observer) = 0;
    virtual void Notify(float xpos, float ypos, bool reset) = 0;
};




#endif //AP_DOODLE_GAME_SUBJECT_H
