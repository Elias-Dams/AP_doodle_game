
#ifndef AP_DOODLE_GAME_ENTITY_VIEW_H
#define AP_DOODLE_GAME_ENTITY_VIEW_H

#include <iostream>
#include <list>
#include <string>
#include "../design_patterns/Observer.h"
#include "../Entity_Model/Entity_Model.h"

using namespace std;

class Entity_View : public Observer{
public:

    Entity_View(Entity_Model &subject);

    virtual ~Entity_View();

    virtual void Update(float xpos, float ypos ) override;
    void RemoveMeFromTheList();


private:
    Entity_Model &subject_;
};


#endif //AP_DOODLE_GAME_ENTITY_VIEW_H
