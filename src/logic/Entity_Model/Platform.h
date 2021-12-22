
#ifndef AP_DOODLE_GAME_M_PLATFORM_H
#define AP_DOODLE_GAME_M_PLATFORM_H

#include "Entity_Model.h"
#include "Namespaces.cpp"

class Model::Platform : public Entity_Model{

public:
    virtual const pair<float, float> &getPosition() const = 0;

    virtual void update(float dt, int world_Width) = 0;

    virtual float getWidth() const = 0;

    virtual float getHeight() const = 0;

    virtual void setPosition(const float &x, const float &y) = 0;

    virtual const string &getColor() const = 0;

    virtual ~Platform();
};


#endif //AP_DOODLE_GAME_PLATFORM_H
