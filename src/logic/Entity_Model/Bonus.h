
#ifndef AP_DOODLE_GAME_M_BONUS_H
#define AP_DOODLE_GAME_M_BONUS_H

#include "Entity_Model.h"
#include "Namespaces.cpp"

class Model::Bonus : public Entity_Model{
public:
    virtual const pair<float, float> &getPosition() const = 0;

    virtual void update(float x, float y) = 0;

    virtual float getWidth() const = 0;

    virtual float getHeight() const = 0;

    virtual void setPosition(const float &x, const float &y) = 0;

    virtual string getType() const = 0;

    virtual ~Bonus();
};


#endif //AP_DOODLE_GAME_BONUS_H
