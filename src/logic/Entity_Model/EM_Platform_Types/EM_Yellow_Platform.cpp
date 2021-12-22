
#include "EM_Yellow_Platform.h"

Model::EM_Yellow_Platform::EM_Yellow_Platform(float platformWidth, float platformHeight, float moveheight) : platform_width(platformWidth),
                                                                                                             platform_height(platformHeight){
    position.first = 0;
    position.second = 0;
    virtual_pos = 0;
    min = -moveheight/2;
    max = moveheight/2;
    up = true;
    color = "Yellow";
}

const pair<float, float> &Model::EM_Yellow_Platform::getPosition() const {
    return position;
}

void Model::EM_Yellow_Platform::setPosition(const float &x, const float &y) {
    EM_Yellow_Platform::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::EM_Yellow_Platform::update(float dt, int world_Width){
    if(up and virtual_pos >= max){
        up = false;
    }
    else if(!up and virtual_pos <= min){
        up = true;
    }

    if(up){
        position.second += (2.0f * dt * 60.0f);
        virtual_pos += (2.0f * dt * 60.0f);
    }
    else {
        position.second -= (2.0f * dt * 60.0f);
        virtual_pos -= (2.0f * dt * 60.0f);
    }

    NotifyPosition(position.first, position.second);
}

float Model::EM_Yellow_Platform::getWidth() const {
    return platform_width;
}

float Model::EM_Yellow_Platform::getHeight() const {
    return platform_height;
}

const string &Model::EM_Yellow_Platform::getColor() const {
    return color;
}

Model::EM_Yellow_Platform::~EM_Yellow_Platform() {
    cout << "destructor of EM_Yellow_Platform" << endl;
}

