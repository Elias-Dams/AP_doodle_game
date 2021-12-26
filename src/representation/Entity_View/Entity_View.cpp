
#include "Entity_View.h"
Entity_View::Entity_View(Subject &subject) :
    Observer(subject) {
}

Entity_View::~Entity_View() {

}

void Entity_View::UpdatePosition(float xpos, float ypos) {
    //cout << "i updated" << endl;
}
