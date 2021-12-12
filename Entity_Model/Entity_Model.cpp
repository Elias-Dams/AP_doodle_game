
#include <algorithm>
#include "Entity_Model.h"

Entity_Model::~Entity_Model() {
    list_observer_.clear();
    cout << "Goodbye, I was the Subject.\n";
}

void Entity_Model::Attach(shared_ptr<Observer> observer) {
    list_observer_.push_back(observer);
}

void Entity_Model::Detach(shared_ptr<Observer> observer) {
    //list_observer_.remove(observer);
}

void Entity_Model::Notify(float xpos, float ypos, bool reset) {

    for(const auto& observer : list_observer_){
        observer->Update(xpos, ypos, reset);
        //observer.lock()->Update(xpos, ypos);
    }

}
