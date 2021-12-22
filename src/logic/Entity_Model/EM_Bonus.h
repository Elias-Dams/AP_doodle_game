
#ifndef AP_DOODLE_GAME_EM_BONUS_H
#define AP_DOODLE_GAME_EM_BONUS_H

#include "Entity_Model.h"
#include "namespaces.cpp"

class Model::EM_Bonus : public Entity_Model{
public:
    virtual const pair<float, float> &getPosition() const = 0;

    virtual void update(float x, float y) = 0;

    virtual float getWidth() const = 0;

    virtual float getHeight() const = 0;

    virtual void setPosition(const float &x, const float &y) = 0;

    virtual string getType() const = 0;

    virtual ~EM_Bonus();
};


#endif //AP_DOODLE_GAME_EM_BONUS_H
