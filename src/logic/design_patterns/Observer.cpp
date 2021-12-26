
#include "Observer.h"

Observer::Observer(Subject &subject) : subject_(subject) {

}

Observer::~Observer() {

}

void Observer::UpdatePosition(float xpos, float ypos) {
    // do nothing
}

void Observer::Resetscore() {
    // do nothing
}

void Observer::ResetTexture() {
    // do nothing
}

void Observer::NewMaxheightReached(float ypos){
    // do nothing
}

void Observer::UpdateMediumJump() {
    // do nothing
}

void Observer::UpdateHighJump() {
    // do nothing
}

void Observer::RemoveMeFromTheList() {
    //subject_.Detach(this);
    std::cout << "Observer removed from the list.\n";
}

