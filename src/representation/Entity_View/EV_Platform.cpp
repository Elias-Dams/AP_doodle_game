
#include "EV_Platform.h"

View::EV_Platform::EV_Platform(Subject &subject) : Entity_View(subject) {}

View::EV_Platform::~EV_Platform() {
    cout << "destructor of EV_Platform" << endl;
}
