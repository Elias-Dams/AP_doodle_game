
#include "Score.h"
#include "Entity_Model/M_Player.h"

Score::Score() {
    score = 0;
}

Score::~Score() {

}

void Score::NewMaxheightReached(const float &y) {
    score += (int)y;
}

void Score::UpdateBonusScore(const int &points) {
    score += points;
}

void Score::UpdateReduceScore(const int &points) {
    score -= points;
}

void Score::Resetscore() {
    score = 0;
}

int Score::getscore() const {
    return score;
}

