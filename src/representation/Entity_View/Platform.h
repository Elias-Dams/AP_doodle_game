
#ifndef AP_DOODLE_GAME_V_PLATFORM_H
#define AP_DOODLE_GAME_V_PLATFORM_H

#include "../../logic/Namespaces.cpp"
#include "Entity_View.h"

class View::Platform : public Entity_View {
public:
    Platform(Subject &subject);

    virtual void UpdatePosition(float xpos, float ypos) = 0;

    virtual sf::Sprite getPlatform() const = 0;

    virtual ~Platform();
};

#endif//AP_DOODLE_GAME_PLATFORM_H
