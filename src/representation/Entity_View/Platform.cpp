
#include "Platform.h"

View::Platform::Platform(Subject &subject) : Entity_View(subject) {}

View::Platform::~Platform() {
    cout << "destructor of Platform" << endl;
}
