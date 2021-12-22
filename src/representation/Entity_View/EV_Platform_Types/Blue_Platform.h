

#ifndef AP_DOODLE_GAME_V_BLUE_PLATFORM_H
#define AP_DOODLE_GAME_V_BLUE_PLATFORM_H

#include "../Platform.h"
#include "../../../logic/Entity_Model/Entity_Model.h"

class View::Blue_Platform : public View::Platform{
public:
    Blue_Platform(Entity_Model &subject, float platformWidth, float platformHeight, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getPlatform() const override;

    ~Blue_Platform() override;

private:
    unique_ptr<sf::Sprite> platform;
    unique_ptr<sf::Texture> texture;
    shared_ptr<Camera> camera;
    float platformWidth;
    float platformHeight;
};


#endif //AP_DOODLE_GAME_BLUE_PLATFORM_H
