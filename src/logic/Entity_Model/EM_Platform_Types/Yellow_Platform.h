
#ifndef AP_DOODLE_GAME_M_YELLOW_PLATFORM_H
#define AP_DOODLE_GAME_M_YELLOW_PLATFORM_H

#include "../Platform.h"

class Model::Yellow_Platform : public Model::Platform{

public:

    Yellow_Platform(float platformWidth, float platformHeight, float moveheight);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(float dt, int world_Width) override;

    float getWidth() const override;

    float getHeight() const override;

    const string &getColor() const override;

    ~Yellow_Platform() override;


private:
    pair<float, float> position;
    float platform_width;
    float platform_height;
    float virtual_pos;
    float min;
    float max;
    bool up;
    string color;
};


#endif //AP_DOODLE_GAME_YELLOW_PLATFORM_H
