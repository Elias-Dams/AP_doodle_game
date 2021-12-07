
#ifndef AP_DOODLE_GAME_ENTITY_MODEL_H
#define AP_DOODLE_GAME_ENTITY_MODEL_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "../design_patterns/Subject.h"
#include "../Camera.h"

using namespace std;

class Entity_Model : public Subject{
public:
    virtual ~Entity_Model();

    /**
     * The subscription management methods.
     */
    void Attach(shared_ptr<Observer> observer) override;
    void Detach(shared_ptr<Observer> observer) override;
    void Notify(float xpos, float ypos) override;


private:
    list<shared_ptr<Observer>> list_observer_;
};


#endif //AP_DOODLE_GAME_ENTITY_MODEL_H
