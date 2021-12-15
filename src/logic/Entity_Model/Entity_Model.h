
#ifndef AP_DOODLE_GAME_ENTITY_MODEL_H
#define AP_DOODLE_GAME_ENTITY_MODEL_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "../design_patterns/Subject.h"

using namespace std;

class Entity_Model : public Subject{
public:
    Entity_Model();

    virtual float getWidth() const = 0;

    virtual float getHeight() const = 0;

    virtual const pair<float, float> &getPosition() const = 0;

    virtual void setPosition(const float &x, const float &y) = 0;
};


#endif //AP_DOODLE_GAME_ENTITY_MODEL_H
