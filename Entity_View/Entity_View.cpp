
#include "Entity_View.h"
Entity_View::Entity_View(Entity_Model &subject) : subject_(subject) {

    //this->subject_.Attach(this);

}

Entity_View::~Entity_View() {
    cout << "Goodbye.\n";
}

void Entity_View::Update(float xpos, float ypos) {
    cout << "i updated" << endl;
}

void Entity_View::RemoveMeFromTheList() {
    //subject_.Detach(this);
    cout << "Observer removed from the list.\n";
}