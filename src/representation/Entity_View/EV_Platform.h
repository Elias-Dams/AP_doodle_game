
#ifndef AP_DOODLE_GAME_EV_PLATFORM_H
#define AP_DOODLE_GAME_EV_PLATFORM_H

#include "Entity_View.h"

class EV_Platform : public Entity_View{
public:

    EV_Platform(Subject &subject);

    virtual void UpdatePosition (float xpos, float ypos) = 0;

    virtual sf::Sprite getPlatform() const = 0;

};

#endif //AP_DOODLE_GAME_EV_PLATFORM_H
