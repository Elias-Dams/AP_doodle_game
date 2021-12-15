
#ifndef AP_DOODLE_GAME_EM_SPRING_H
#define AP_DOODLE_GAME_EM_SPRING_H

#include "../EM_Bonus.h"

class EM_Spring : public EM_Bonus{
public:

    EM_Spring(float Width, float Height);

    const pair<float, float> &getPosition() const;

    void setPosition(const float &x, const float &y);

    void update(float x, float y);

    float getWidth() const;

    float getHeight() const;

private:
    pair<float, float> position;
    float spring_width;
    float spring_height;
};


#endif //AP_DOODLE_GAME_EM_SPRING_H
