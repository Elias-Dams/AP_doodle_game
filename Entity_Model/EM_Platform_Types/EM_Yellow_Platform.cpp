
#include "EM_Yellow_Platform.h"

EM_Yellow_Platform::EM_Yellow_Platform(float platformWidth, float platformHeight, float moveheight) : platform_width(platformWidth),
                                                                                    platform_height(platformHeight), move_height(moveheight){
    position.first = 0;
    position.second = 0;
    virtual_pos = 0;
    up = true;
    color = "Yellow";
}

const pair<float, float> &EM_Yellow_Platform::getPosition() const {
    return position;
}

void EM_Yellow_Platform::setPosition(const float &x, const float &y) {
    EM_Yellow_Platform::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void EM_Yellow_Platform::update(float dt, int world_Width){
    if(up and virtual_pos >= move_height){
        up = false;
    }
    else if(!up and virtual_pos <= 0){
        up = true;
    }

    if(up){
        position.second += (2.0f * dt * 60.0f);
        virtual_pos += (2.0f * dt * 60.0f);
    }
    else if(!up){
        position.second -= (2.0f * dt * 60.0f);
        virtual_pos -= (2.0f * dt * 60.0f);
    }

    NotifyPosition(position.first, position.second);
}

float EM_Yellow_Platform::getPlatformWidth() const {
    return platform_width;
}

float EM_Yellow_Platform::getPlatformHeight() const {
    return platform_height;
}

const string &EM_Yellow_Platform::getColor() const {
    return color;
}

