
#ifndef AP_DOODLE_GAME_ENTITY_VIEW_H
#define AP_DOODLE_GAME_ENTITY_VIEW_H

#include <iostream>
#include <list>
#include <string>
#include <SFML/Graphics.hpp>
#include "../design_patterns/Observer.h"
#include "../Entity_Model/Entity_Model.h"
#include "../Camera.h"


using namespace std;

class Entity_View : public Observer{
public:

    Entity_View(Subject &subject);

    virtual ~Entity_View();

    virtual void UpdatePosition(float xpos, float ypos) override;

};


#endif //AP_DOODLE_GAME_ENTITY_VIEW_H
