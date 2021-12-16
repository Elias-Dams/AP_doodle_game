
#include "Subject.h"

Subject::~Subject() {
    list_observer_.clear();
    std::cout << "Goodbye, I was the Subject.\n";
}

void Subject::Attach(std::shared_ptr<IObserver> observer) {
    list_observer_.push_back(observer);
}

void Subject::Detach(std::shared_ptr<IObserver> observer) {
    //list_Subject_.remove(Observer);
}

void Subject::NotifyPosition(float xpos, float ypos) {

    for(const auto& Subject : list_observer_){
        Subject->UpdatePosition(xpos, ypos);

    }

}

void Subject::NotifySpting() {
    for(const auto& Subject : list_observer_){
        Subject->UpdateSpringCollected();

    }
}


void Subject::NotifyJetpack() {
    for(const auto& Subject : list_observer_){
        Subject->UpdateJetpackCollected();

    }
}

void Subject::NewMaxHeigh(float ypos) {
    for(const auto& Subject : list_observer_){

        Subject->NewMaxheightReached(ypos);
    }
}

void Subject::NotifyNormal(){
    for(const auto& Subject : list_observer_){

        Subject->ResetTexture();

    }
}

void Subject::NotifyReset() {
    for(const auto& Subject : list_observer_){

        Subject->Resetscore();

    }
}