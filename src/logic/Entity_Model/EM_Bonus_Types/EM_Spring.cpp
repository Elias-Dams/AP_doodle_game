
#include "EM_Spring.h"

EM_Spring::EM_Spring(float Width, float Height) : spring_width(Width), spring_height(Height) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &EM_Spring::getPosition() const {
    return position;
}

void EM_Spring::setPosition(const float &x, const float &y) {
    EM_Spring::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void EM_Spring::update(float x, float y){
    position.first = x;
    position.second = y;
    NotifyPosition(position.first, position.second);
}

float EM_Spring::getWidth() const {
    return spring_width;
}

float EM_Spring::getHeight() const {
    return spring_height;
}

string EM_Spring::getType() const{
    return "spring";
}