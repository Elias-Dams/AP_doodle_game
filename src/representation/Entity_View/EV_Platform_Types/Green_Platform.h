
#ifndef AP_DOODLE_GAME_V_GREEN_PLATFORM_H
#define AP_DOODLE_GAME_V_GREEN_PLATFORM_H

#include "../../../logic/Entity_Model/Entity_Model.h"
#include "../Platform.h"

class View::Green_Platform : public View::Platform {
public:
    Green_Platform(Entity_Model &subject, float platformWidth, float platformHeight, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getPlatform() const override;

    ~Green_Platform() override;

private:
    unique_ptr<sf::Sprite> platform;
    unique_ptr<sf::Texture> texture;
    shared_ptr<Camera> camera;
    float platformWidth;
    float platformHeight;
};


#endif//AP_DOODLE_GAME_GREEN_PLATFORM_H
