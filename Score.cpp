
#include "Score.h"

Score::Score(Entity_Model &subject) : subject_(subject) {

    height = 0;
}

Score::~Score() {
    std::cout << "Goodbye\n";
}

void Score::Update(float xpos, float ypos, bool reset) {

    if(!reset){
        if(height < ypos){
            height = ypos;
        }
    }
    else{
        height = 0;
    }
}

void Score::RemoveMeFromTheList() {

    std::cout << "Observer removed from the list.\n";
}

int Score::getscore() const {
    return height;
}
