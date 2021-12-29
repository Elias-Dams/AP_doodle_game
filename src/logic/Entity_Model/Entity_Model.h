
#ifndef AP_DOODLE_GAME_ENTITY_MODEL_H
#define AP_DOODLE_GAME_ENTITY_MODEL_H

#include "../design_patterns/Subject.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

/**
 * @class Entity_Model
 *
 * @brief This class encapsulates all entities.
 */
class Entity_Model : public Subject {
public:
    /**
     * Entity_Model constructor.
     * constructs an Entity_Model.
     */
    Entity_Model();

    /**
    * @brief gives the width of the entity.
    *
    * This function gives the width of the entity.
    *
    * @return width of the entity.
    */
    virtual float getWidth() const = 0;

    /**
    * @brief gives the height of the entity.
    *
    * This function gives the height of the entity.
    *
    * @return height of the entity.
    */
    virtual float getHeight() const = 0;

    /**
    * @brief gives the x and y coordinate of the entity.
    *
    * This function gives the position  of the entity in a normalised world.
    *
    * @return a pair consisting of the x and y coordinates  of the entity.
    */
    virtual const pair<float, float> &getPosition() const = 0;

    /**
    * @brief sets the position of the entity.
    *
    * This function updates the position of the entity with the given coordinates.
    *
    * @param x: a position on the x axis.
    * @param y: a position on the y axis.
    */
    virtual void setPosition(const float &x, const float &y) = 0;

    virtual ~Entity_Model();
};


#endif//AP_DOODLE_GAME_ENTITY_MODEL_H
