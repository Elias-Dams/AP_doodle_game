
#include "Entity_View.h"
Entity_View::Entity_View(Subject &subject) : Observer(subject) {

    //this->subject_.Attach(this);

}

Entity_View::~Entity_View() {
    //cout << "Goodbye.\n";
}

void Entity_View::UpdatePosition(float xpos, float ypos) {
    //cout << "i updated" << endl;
}
