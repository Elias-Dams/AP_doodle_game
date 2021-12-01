
#ifndef AP_DOODLE_GAME_IOBSERVER_H
#define AP_DOODLE_GAME_IOBSERVER_H

#include <iostream>
#include <list>
#include <string>
#include <memory>

class Observer{
public:
    virtual ~Observer(){};
    virtual void Update(float xpos, float ypos) = 0;
};


#endif //AP_DOODLE_GAME_IOBSERVER_H
