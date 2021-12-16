
#include "EV_Platform.h"

EV_Platform::EV_Platform(Subject &subject) : Entity_View(subject) {}

EV_Platform::~EV_Platform() {
    cout << "destructor of EV_Platform" << endl;
}
