
#include "Green_Platform.h"

Model::Green_Platform::Green_Platform(float platformWidth, float platformHeight) :
    platform_width(platformWidth), platform_height(platformHeight) {
    position.first = 0;
    position.second = 0;
    color = "Green";
}

const pair<float, float> &Model::Green_Platform::getPosition() const {
    return position;
}

void Model::Green_Platform::setPosition(const float &x, const float &y) {
    Green_Platform::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::Green_Platform::update(float dt) {
    // the platform doesn't move
    NotifyPosition(position.first, position.second);
}

float Model::Green_Platform::getWidth() const {
    return platform_width;
}

float Model::Green_Platform::getHeight() const {
    return platform_height;
}

const string &Model::Green_Platform::getColor() const {
    return color;
}

Model::Green_Platform::~Green_Platform() {
    cout << "destructor of Green_Platform" << endl;
}
