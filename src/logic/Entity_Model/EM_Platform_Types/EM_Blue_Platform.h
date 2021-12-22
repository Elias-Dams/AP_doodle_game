
#ifndef AP_DOODLE_GAME_EM_BLUE_PLATFORM_H
#define AP_DOODLE_GAME_EM_BLUE_PLATFORM_H

#include "../EM_Platform.h"

class Model::EM_Blue_Platform : public Model::EM_Platform{

public:

    EM_Blue_Platform(float platformWidth, float platformHeight);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(float dt, int world_Width) override;

    float getWidth() const override;

    float getHeight() const override;

    const string &getColor() const override;

    ~EM_Blue_Platform() override;


private:
    pair<float, float> position;
    float platform_width;
    float platform_height;
    bool left;
    string color;
};


#endif //AP_DOODLE_GAME_EM_BLUE_PLATFORM_H
