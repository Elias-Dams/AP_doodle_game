
#include "EM_Platform.h"

EM_Platform::EM_Platform(float platformWidth, float platformHeight) : platform_width(platformWidth), platform_height(platformHeight) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &EM_Platform::getPosition() const {
    return position;
}

void EM_Platform::setPosition(const float &x, const float &y) {
    EM_Platform::position = make_pair(x, y);
    //Notify(position.first, position.second);
}

void EM_Platform::update(){
    Notify(position.first, position.second);
}

float EM_Platform::getPlatformWidth() const {
    return platform_width;
}

float EM_Platform::getPlatformHeight() const {
    return platform_height;
}
