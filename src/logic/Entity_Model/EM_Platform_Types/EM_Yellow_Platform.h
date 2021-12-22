
#ifndef AP_DOODLE_GAME_EM_YELLOW_PLATFORM_H
#define AP_DOODLE_GAME_EM_YELLOW_PLATFORM_H

#include "../EM_Platform.h"

class Model::EM_Yellow_Platform : public Model::EM_Platform{

public:

    EM_Yellow_Platform(float platformWidth, float platformHeight, float moveheight);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(float dt, int world_Width) override;

    float getWidth() const override;

    float getHeight() const override;

    const string &getColor() const override;

    ~EM_Yellow_Platform() override;


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


#endif //AP_DOODLE_GAME_EM_YELLOW_PLATFORM_H
