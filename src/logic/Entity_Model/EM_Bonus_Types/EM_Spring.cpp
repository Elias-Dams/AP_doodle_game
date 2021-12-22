
#include "EM_Spring.h"

Model::EM_Spring::EM_Spring(float Width, float Height) : spring_width(Width), spring_height(Height) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &Model::EM_Spring::getPosition() const {
    return position;
}

void Model::EM_Spring::setPosition(const float &x, const float &y) {
    EM_Spring::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::EM_Spring::update(float x, float y){
    position.first = x;
    position.second = y;
    NotifyPosition(position.first, position.second);
}

float Model::EM_Spring::getWidth() const {
    return spring_width;
}

float Model::EM_Spring::getHeight() const {
    return spring_height;
}

string Model::EM_Spring::getType() const{
    return "spring";
}

Model::EM_Spring::~EM_Spring() {
    cout << "destructor of EM_Spring" << endl;
}
