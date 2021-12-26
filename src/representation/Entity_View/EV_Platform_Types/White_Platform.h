
#ifndef AP_DOODLE_GAME_V_WHITE_PLATFORM_H
#define AP_DOODLE_GAME_V_WHITE_PLATFORM_H

#include "../../../logic/Entity_Model/Entity_Model.h"
#include "../Platform.h"

class View::White_Platform : public View::Platform {
public:
    /**
     * White_Platform constructor.
     * constructs the white_Platform whit
     * a given width and height and the camera to convert the coordinates to sfml coordinates
     */
    White_Platform(float platformWidth, float platformHeight, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getPlatform() const override;

    ~White_Platform() override;

private:
    unique_ptr<sf::Sprite> platform; ///< sfml sprite of the platform
    unique_ptr<sf::Texture> texture; ///< sfml texture of the platform
    shared_ptr<Camera> camera; ///< the camera to convert the coordinates to sfml coordinates
    float platformWidth;  ///< width of the platform
    float platformHeight; ///< height of the platform
};


#endif//AP_DOODLE_GAME_WHITE_PLATFORM_H
