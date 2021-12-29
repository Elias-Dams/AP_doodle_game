
#ifndef AP_DOODLE_GAME_V_BLUE_PLATFORM_H
#define AP_DOODLE_GAME_V_BLUE_PLATFORM_H

#include "../../../logic/Entity_Model/Entity_Model.h"
#include "../V_Platform.h"

class View::Blue_Platform : public View::Platform {
public:
    /**
     * Blue_Platform constructor.
     * constructs the blue_Platform whit
     * a given width and height and the camera to convert the coordinates to sfml coordinates
     */
    Blue_Platform(float platformWidth, float platformHeight, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getPlatform() const override;

    ~Blue_Platform() override;

private:
    unique_ptr<sf::Sprite> platform; ///< sfml sprite of the platform
    unique_ptr<sf::Texture> texture; ///< sfml texture of the platform
    shared_ptr<Camera> camera; ///< the camera to convert the coordinates to sfml coordinates
    float platformWidth;  ///< width of the platform
    float platformHeight; ///< height of the platform
};


#endif//AP_DOODLE_GAME_BLUE_PLATFORM_H
