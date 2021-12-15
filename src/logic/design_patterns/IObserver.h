
#ifndef AP_DOODLE_GAME_IOBSERVER_H
#define AP_DOODLE_GAME_IOBSERVER_H

#include <iostream>
#include <list>
#include <string>
#include <memory>

class IObserver {
public:
    virtual ~IObserver(){};
    virtual void UpdatePosition(float xpos, float ypos) = 0;
    virtual void NewMaxheightReached(float ypos) = 0;
    virtual void Resetscore() = 0;
};


#endif //AP_DOODLE_GAME_IOBSERVER_H
