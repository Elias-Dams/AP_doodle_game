
#ifndef AP_DOODLE_GAME_EM_GREEN_PLATFORM_H
#define AP_DOODLE_GAME_EM_GREEN_PLATFORM_H

#include "../EM_Platform.h"

class EM_Green_Platform : public EM_Platform{

public:

    EM_Green_Platform(float platformWidth, float platformHeight);

    const pair<float, float> &getPosition() const;

    void setPosition(const float &x, const float &y);

    void update(float dt, int world_Width);

    float getWidth() const;

    float getHeight() const;

    const string &getColor() const;

    virtual ~EM_Green_Platform();


private:
    pair<float, float> position;
    float platform_width;
    float platform_height;
    string color;
};


#endif //AP_DOODLE_GAME_EM_GREEN_PLATFORM_H
