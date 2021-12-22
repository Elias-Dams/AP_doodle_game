
#include "EM_Green_Platform.h"

Model::EM_Green_Platform::EM_Green_Platform(float platformWidth, float platformHeight) : platform_width(platformWidth), platform_height(platformHeight) {
    position.first = 0;
    position.second = 0;
    color = "Green";
}

const pair<float, float> &Model::EM_Green_Platform::getPosition() const {
    return position;
}

void Model::EM_Green_Platform::setPosition(const float &x, const float &y) {
    EM_Green_Platform::position = make_pair(x, y);
    NotifyPosition(position.first,position.second);
}

void Model::EM_Green_Platform::update(float dt, int world_Width){
    // the platform doesn't move
    NotifyPosition(position.first,position.second);
}

float Model::EM_Green_Platform::getWidth() const {
    return platform_width;
}

float Model::EM_Green_Platform::getHeight() const {
    return platform_height;
}

const string &Model::EM_Green_Platform::getColor() const {
    return color;
}

Model::EM_Green_Platform::~EM_Green_Platform() {
    cout << "destructor of EM_Green_Platform" << endl;
}
