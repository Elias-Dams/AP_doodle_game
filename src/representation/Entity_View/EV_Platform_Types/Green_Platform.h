
#ifndef AP_DOODLE_GAME_V_GREEN_PLATFORM_H
#define AP_DOODLE_GAME_V_GREEN_PLATFORM_H

#include "../../../logic/Entity_Model/Entity_Model.h"
#include "../Platform.h"

class View::Green_Platform : public View::Platform {
public:
    /**
     * Green_Platform constructor.
     * constructs the green_Platform  whit given Entity model (this wil act as the subject whereby this green_Platform will observere)
     * a given width and height and the camera to convert the coordinates to sfml coordinates
     */
    Green_Platform(Entity_Model &subject, float platformWidth, float platformHeight, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getPlatform() const override;

    ~Green_Platform() override;

private:
    unique_ptr<sf::Sprite> platform; ///< sfml sprite of the platform
    unique_ptr<sf::Texture> texture; ///< sfml texture of the platform
    shared_ptr<Camera> camera; ///< the camera to convert the coordinates to sfml coordinates
    float platformWidth;  ///< width of the platform
    float platformHeight; ///< height of the platform
};


#endif//AP_DOODLE_GAME_GREEN_PLATFORM_H
