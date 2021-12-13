
#ifndef AP_DOODLE_GAME_SCORE_H
#define AP_DOODLE_GAME_SCORE_H

#include <iostream>
#include <list>
#include <string>
#include "design_patterns/Observer.h"
#include "Entity_Model/Entity_Model.h"


using namespace std;

class Score : public Observer{
public:
    Score(Entity_Model &subject);
    virtual ~Score();

    /// updates the score
    void NewMaxheightReached(float ypos) override;

    void Resetscore() override;

    int getscore() const;

private:
    int score;
};


#endif //AP_DOODLE_GAME_SCORE_H
