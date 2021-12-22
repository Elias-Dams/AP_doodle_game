
#include "Entity_View.h"
Entity_View::Entity_View(Subject &subject) : Observer(subject) {
}

Entity_View::~Entity_View() {
    cout << "destructor of Entity_View" << endl;
}

void Entity_View::UpdatePosition(float xpos, float ypos) {
    //cout << "i updated" << endl;
}

