
#include "Observer.h"

Observer::Observer(Subject &subject) : subject_(subject) {

    //this->subject_.Attach(this);

}

Observer::~Observer() {
    std::cout << "Goodbye.\n";
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

void Observer::UpdateSpringCollected() {
    // do nothing
}

void Observer::UpdateJetpackCollected() {
    // do nothing
}

void Observer::RemoveMeFromTheList() {
    //subject_.Detach(this);
    std::cout << "Observer removed from the list.\n";
}

