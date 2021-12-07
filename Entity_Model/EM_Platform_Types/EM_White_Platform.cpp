
#include "EM_White_Platform.h"

EM_White_Platform::EM_White_Platform(float platformWidth, float platformHeight) : platform_width(platformWidth),
                                                                                  platform_height(platformHeight) {
    position.first = 0;
    position.second = 0;
    color = "White";
}

const pair<float, float> &EM_White_Platform::getPosition() const {
    return position;
}

void EM_White_Platform::setPosition(const float &x, const float &y) {
    EM_White_Platform::position = make_pair(x, y);
    Notify(position.first, position.second);
}

void EM_White_Platform::update(float dt, int world_Width){
    // the platform doesn't move
    Notify(position.first, position.second);
}

float EM_White_Platform::getPlatformWidth() const {
    return platform_width;
}

float EM_White_Platform::getPlatformHeight() const {
    return platform_height;
}

const string &EM_White_Platform::getColor() const {
    return color;
}
