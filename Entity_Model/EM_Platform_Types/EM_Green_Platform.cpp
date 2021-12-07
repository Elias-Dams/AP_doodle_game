
#include "EM_Green_Platform.h"

EM_Green_Platform::EM_Green_Platform(float platformWidth, float platformHeight) : platform_width(platformWidth), platform_height(platformHeight) {
    position.first = 0;
    position.second = 0;
    color = "Green";
}

const pair<float, float> &EM_Green_Platform::getPosition() const {
    return position;
}

void EM_Green_Platform::setPosition(const float &x, const float &y, shared_ptr<Camera> camera) {
    EM_Green_Platform::position = make_pair(x, y);
    Notify(position.first, camera->toGameheight(position.second, platform_height));
}

void EM_Green_Platform::update(float dt, int world_Width, shared_ptr<Camera> camera){
    // the platform doesn't move
    Notify(position.first, camera->toGameheight(position.second, platform_height));
}

float EM_Green_Platform::getPlatformWidth() const {
    return platform_width;
}

float EM_Green_Platform::getPlatformHeight() const {
    return platform_height;
}

const string &EM_Green_Platform::getColor() const {
    return color;
}
