
#include "Score.h"

Score::Score(Entity_Model &subject) : subject_(subject) {

    height = 0;
}

Score::~Score() {
    std::cout << "Goodbye\n";
}

void Score::Update(float xpos, float ypos) {
    if(height < ypos){
        height = ypos;
    }
}

void Score::RemoveMeFromTheList() {

    std::cout << "Observer removed from the list.\n";
}

int Score::getscore() const {
    return height;
}
