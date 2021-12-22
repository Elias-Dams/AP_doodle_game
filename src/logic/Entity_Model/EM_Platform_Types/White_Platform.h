
#ifndef AP_DOODLE_GAME_M_WHITE_PLATFORM_H
#define AP_DOODLE_GAME_M_WHITE_PLATFORM_H

#include "../Platform.h"

class Model::White_Platform : public Model::Platform{

public:

    White_Platform(float platformWidth, float platformHeight);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(float dt, int world_Width) override;

    float getWidth() const override;

    float getHeight() const override;

    const string &getColor() const override;

    ~White_Platform() override;

private:
    pair<float, float> position;
    float platform_width;
    float platform_height;
    string color;
};


#endif //AP_DOODLE_GAME_WHITE_PLATFORM_H
