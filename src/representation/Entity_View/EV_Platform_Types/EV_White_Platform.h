
#ifndef AP_DOODLE_GAME_EV_WHITE_PLATFORM_H
#define AP_DOODLE_GAME_EV_WHITE_PLATFORM_H

#include "../EV_Platform.h"
#include "../../../logic/Entity_Model/Entity_Model.h"

class EV_White_Platform : public EV_Platform{
public:
    EV_White_Platform(Entity_Model &subject, float platformWidth, float platformHeight, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;


    sf::Sprite getPlatform() const;

    ~EV_White_Platform();

private:
    unique_ptr<sf::Sprite> platform;
    unique_ptr<sf::Texture> texture;
    shared_ptr<Camera> camera;
    float platformWidth;
    float platformHeight;
};


#endif //AP_DOODLE_GAME_EV_WHITE_PLATFORM_H
