
#include "EV_Bonus.h"

View::EV_Bonus::EV_Bonus(Subject &subject) : Entity_View(subject) {}

View::EV_Bonus::~EV_Bonus() {
    cout << "destructor of EV_Bonus" << endl;
}
