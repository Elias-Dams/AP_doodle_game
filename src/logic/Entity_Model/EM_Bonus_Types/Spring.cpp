
#include "Spring.h"

Model::Spring::Spring(float Width, float Height) :
    spring_width(Width), spring_height(Height) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &Model::Spring::getPosition() const {
    return position;
}

void Model::Spring::setPosition(const float &x, const float &y) {
    Spring::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::Spring::update(float x, float y) {
    position.first = x;
    position.second = y;
    NotifyPosition(position.first, position.second);
}

float Model::Spring::getWidth() const {
    return spring_width;
}

float Model::Spring::getHeight() const {
    return spring_height;
}

string Model::Spring::getType() const {
    return "spring";
}

Model::Spring::~Spring() {
    cout << "destructor of Spring" << endl;
}
