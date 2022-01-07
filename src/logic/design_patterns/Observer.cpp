
#include "Observer.h"

Observer::Observer()  {

}

Observer::~Observer() {

}

void Observer::UpdatePosition(const float xpos, const float ypos) {
    // do nothing
}

void Observer::Resetscore() {
    // do nothing
}

void Observer::ResetTexture() {
    // do nothing
}

void Observer::NewMaxheightReached(const float ypos){
    // do nothing
}

void Observer::UpdateBonusScore(const int points) {
    // do nothing
}

void Observer::UpdateReduceScore(const int points) {
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

