
#ifndef AP_DOODLE_GAME_EM_PLATFORM_H
#define AP_DOODLE_GAME_EM_PLATFORM_H

#include "Entity_Model.h"

class EM_Platform : public Entity_Model{

public:
    EM_Platform(float platformWidth, float platformHeight);

    const pair<float, float> &getPosition() const;

    void setPosition(const float &x, const float &y);

    void update();

    float getPlatformWidth() const;

    float getPlatformHeight() const;


private:
    pair<float, float> position;
    float platform_width;
    float platform_height;
};


#endif //AP_DOODLE_GAME_EM_PLATFORM_H
