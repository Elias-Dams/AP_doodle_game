
#include "Score.h"
#include "Entity_Model/Player.h"

Score::Score(Entity_Model &subject) :
    Observer(subject) {

    score = 0;
}

Score::~Score() {

}

void Score::NewMaxheightReached(float y) {
    score = y;
}

void Score::Resetscore() {
    score = 0;
}

int Score::getscore() const {
    return score;
}
