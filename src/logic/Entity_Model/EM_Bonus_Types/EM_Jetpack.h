
#ifndef AP_DOODLE_GAME_EM_JETPACK_H
#define AP_DOODLE_GAME_EM_JETPACK_H

#include "../EM_Bonus.h"

class EM_Jetpack : public EM_Bonus{
public:

    EM_Jetpack(float Width, float Height);

    const pair<float, float> &getPosition() const;

    void setPosition(const float &x, const float &y);

    void update(float x, float y);

    float getWidth() const;

    float getHeight() const;

private:
    pair<float, float> position;
    float jetpack_width;
    float jetpack_height;
};


#endif //AP_DOODLE_GAME_EM_JETPACK_H
