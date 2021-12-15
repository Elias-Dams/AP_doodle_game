
#include "EM_Jetpack.h"

EM_Jetpack::EM_Jetpack(float Width, float Height) : jetpack_width(Width), jetpack_height(Height) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &EM_Jetpack::getPosition() const {
    return position;
}

void EM_Jetpack::setPosition(const float &x, const float &y) {
    EM_Jetpack::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void EM_Jetpack::update(float x, float y){
    position.first = x;
    position.second = y;
    NotifyPosition(position.first, position.second);
}

float EM_Jetpack::getWidth() const {
    return jetpack_width;
}

float EM_Jetpack::getHeight() const {
    return jetpack_height;
}