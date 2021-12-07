
#ifndef AP_DOODLE_GAME_EM_PLATFORM_H
#define AP_DOODLE_GAME_EM_PLATFORM_H

#include "Entity_Model.h"

class EM_Platform : public Entity_Model{

public:
    virtual const pair<float, float> &getPosition() const = 0;

    virtual void update(float dt, int world_Width) = 0;

    virtual float getPlatformWidth() const = 0;

    virtual float getPlatformHeight() const = 0;

    virtual void setPosition(const float &x, const float &y) = 0;

    virtual const string &getColor() const = 0;
};


#endif //AP_DOODLE_GAME_EM_PLATFORM_H
