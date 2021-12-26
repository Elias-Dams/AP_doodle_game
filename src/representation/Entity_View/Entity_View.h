
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
    /**
     * Entity_View constructor.
     * constructs the entity_view
     */
    Entity_View();

    virtual ~Entity_View();

    /**
    * @brief updates the position of the entity views
    *
    * This function updates the position of the view when the player has moved
    *
    * @param x: position of the entity in the game
    * @param y: position of the entity in the game
    */
    virtual void UpdatePosition(float xpos, float ypos);
};


#endif//AP_DOODLE_GAME_ENTITY_VIEW_H
