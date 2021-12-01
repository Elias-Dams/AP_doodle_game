
#include "EM_Platform.h"

EM_Platform::EM_Platform(float platformWidht, float platformHeight) : platform_widht(platformWidht), platform_height(platformHeight) {
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

float EM_Platform::getPlatformWidht() const {
    return platform_widht;
}

float EM_Platform::getPlatformHeight() const {
    return platform_height;
}
