
#ifndef AP_DOODLE_GAME_EV_PLATFORM_H
#define AP_DOODLE_GAME_EV_PLATFORM_H

#include "Entity_View.h"
#include <SFML/Graphics.hpp>

class EV_Platform : public Entity_View{
public:

    EV_Platform(Entity_Model &subject);

    virtual void Update(float xpos, float ypos, bool reset) = 0;

    virtual sf::Sprite getPlatform() const = 0;

};

#endif //AP_DOODLE_GAME_EV_PLATFORM_H
