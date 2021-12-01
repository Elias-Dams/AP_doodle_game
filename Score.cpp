
#include "Score.h"

Score::Score(Entity_Model &subject) : subject_(subject) {
    //this->subject_.Attach(this->getSharedPtr());

}

Score::~Score() {
    std::cout << "Goodbye\n";
}

void Score::Update(float xpos, float ypos) {
    cout << "i updated" << endl;
}

void Score::RemoveMeFromTheList() {
    //subject_.Detach(this->getSharedPtr());
    std::cout << "Observer removed from the list.\n";
}