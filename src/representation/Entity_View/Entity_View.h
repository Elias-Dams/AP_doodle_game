
#ifndef AP_DOODLE_GAME_ENTITY_VIEW_H
#define AP_DOODLE_GAME_ENTITY_VIEW_H

#include "../../logic/Camera.h"
#include "../../logic/design_patterns/Observer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <string>


using namespace std;

class Entity_View : public Observer {
public:
    Entity_View(Subject &subject);

    virtual ~Entity_View();

    virtual void UpdatePosition(float xpos, float ypos) override;
};


#endif//AP_DOODLE_GAME_ENTITY_VIEW_H
