
#ifndef AP_DOODLE_GAME_SCORE_H
#define AP_DOODLE_GAME_SCORE_H

#include <iostream>
#include <list>
#include <string>
#include "design_patterns/Subject.h"
#include "Entity_Model/Entity_Model.h"


using namespace std;

class Score : public Observer{
public:
    Score(Entity_Model &subject);
    virtual ~Score();

    void Update(float xpos, float ypos, bool reset) override;
    void RemoveMeFromTheList();

    int getscore() const;

private:
    Entity_Model &subject_;
    int height;
};


#endif //AP_DOODLE_GAME_SCORE_H
