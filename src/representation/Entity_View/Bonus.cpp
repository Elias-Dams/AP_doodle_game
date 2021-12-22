
#include "Bonus.h"

View::Bonus::Bonus(Subject &subject) : Entity_View(subject) {}

View::Bonus::~Bonus() {
    cout << "destructor of Bonus" << endl;
}
