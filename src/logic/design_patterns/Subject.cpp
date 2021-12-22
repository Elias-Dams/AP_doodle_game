
#include "Subject.h"

Subject::~Subject() {
    std::cout << "destructor of Subject" << std::endl;

    for(std::shared_ptr<IObserver> Subject_ : list_observer_){
        Subject_.reset();
    }
    list_observer_.clear();

}

void Subject::Attach(std::shared_ptr<IObserver> observer) {
    list_observer_.push_back(observer);
}

void Subject::Detach(std::shared_ptr<IObserver> observer) {
    list_observer_.remove(observer);
}

void Subject::NotifyPosition(float xpos, float ypos) {

    for(const std::shared_ptr<IObserver>& Subject_ : list_observer_){
        Subject_->UpdatePosition(xpos, ypos);

    }

}

void Subject::NotifySpting() {
    for(std::shared_ptr<IObserver> Subject_ : list_observer_){
        Subject_->UpdateSpringCollected();

    }
}


void Subject::NotifyJetpack() {
    for(std::shared_ptr<IObserver> Subject_ : list_observer_){
        Subject_->UpdateJetpackCollected();

    }
}

void Subject::NewMaxHeigh(float ypos) {
    for(std::shared_ptr<IObserver> Subject_ : list_observer_){

        Subject_->NewMaxheightReached(ypos);
    }
}

void Subject::NotifyNormal(){
    for(std::shared_ptr<IObserver> Subject_ : list_observer_){

        Subject_->ResetTexture();

    }
}

void Subject::NotifyReset() {
    for(std::shared_ptr<IObserver> Subject_ : list_observer_){

        Subject_->Resetscore();

    }
}