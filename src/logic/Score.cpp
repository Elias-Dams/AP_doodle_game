
#include "Score.h"
#include "Entity_Model/EM_Player.h"

Score::Score(Entity_Model &subject) : Observer(subject) {

    score = 0;
}

Score::~Score() {
    std::cout << "Goodbye\n";
}

void Score::NewMaxheightReached(float ypos) {
    score = ypos;
}

void Score::Resetscore(){
    score = 0;
}

int Score::getscore() const {
    return score;
}