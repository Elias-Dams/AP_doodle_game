
#ifndef AP_DOODLE_GAME_V_PLATFORM_H
#define AP_DOODLE_GAME_V_PLATFORM_H

#include "../../logic/Namespaces.cpp"
#include "Entity_View.h"

/**
 * @class Platform
 *
 * This is the view part of the Platform.
 * It handles the textures.
 */
class View::Platform : public Entity_View {
public:
    /**
     * Platform constructor.
     * Constructs the platform.
     */
    Platform();

    /**
    * @brief gets the sfml sprite
    *
    * This function gets the sfml sprite of the platform
    *
    * @return the sfml sprite of the platform
    */
    virtual sf::Sprite getPlatform() const = 0;

    virtual void UpdatePosition(const float &xpos, const float &ypos) = 0;

    virtual ~Platform();
};

#endif//AP_DOODLE_GAME_PLATFORM_H
