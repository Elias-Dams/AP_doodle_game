
#include "EM_Blue_Platform.h"

EM_Blue_Platform::EM_Blue_Platform(float platformWidth, float platformHeight) : platform_width(platformWidth),
                                                                                platform_height(platformHeight) {
    position.first = 0;
    position.second = 0;
    left = true;
    color = "Blue";
}

const pair<float, float> &EM_Blue_Platform::getPosition() const {
    return position;
}

void EM_Blue_Platform::setPosition(const float &x, const float &y) {
    EM_Blue_Platform::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void EM_Blue_Platform::update(float dt, int world_Width){
    if(left and position.first >= world_Width - platform_width){
        left = false;
    }
    else if(!left and position.first <= 0){
        left = true;
    }

    if(left){
        position.first += (2.0f * dt * 60.0f);
    }
    else if(!left){
        position.first -= (2.0f * dt * 60.0f);
    }
    NotifyPosition(position.first, position.second);
}

float EM_Blue_Platform::getWidth() const {
    return platform_width;
}

float EM_Blue_Platform::getHeight() const {
    return platform_height;
}

const string &EM_Blue_Platform::getColor() const {
    return color;
}

EM_Blue_Platform::~EM_Blue_Platform() {
    cout << "destructor of EM_Blue_Platform" << endl;
}

