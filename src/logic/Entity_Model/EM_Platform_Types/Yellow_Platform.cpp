
#include "Yellow_Platform.h"

Model::Yellow_Platform::Yellow_Platform(float platformWidth, float platformHeight, float moveheight) : platform_width(platformWidth),
                                                                                                             platform_height(platformHeight){
    position.first = 0;
    position.second = 0;
    virtual_pos = 0;
    min = -moveheight/2;
    max = moveheight/2;
    up = true;
    color = "Yellow";
}

const pair<float, float> &Model::Yellow_Platform::getPosition() const {
    return position;
}

void Model::Yellow_Platform::setPosition(const float &x, const float &y) {
    Yellow_Platform::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::Yellow_Platform::update(float dt, int world_Width){
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

float Model::Yellow_Platform::getWidth() const {
    return platform_width;
}

float Model::Yellow_Platform::getHeight() const {
    return platform_height;
}

const string &Model::Yellow_Platform::getColor() const {
    return color;
}

Model::Yellow_Platform::~Yellow_Platform() {
    cout << "destructor of Yellow_Platform" << endl;
}

