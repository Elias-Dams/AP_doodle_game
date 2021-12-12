
#ifndef AP_DOODLE_GAME_EV_GREEN_PLATFORM_H
#define AP_DOODLE_GAME_EV_GREEN_PLATFORM_H

#include "../EV_Platform.h"

class EV_Green_Platform : public EV_Platform{
public:
    EV_Green_Platform(Entity_Model &subject, float platformWidth, float platformHeight, shared_ptr<Camera> camera);

    void Update(float xpos, float ypos, bool reset) override;

    sf::Sprite getPlatform() const;

    virtual ~EV_Green_Platform();

private:
    unique_ptr<sf::Sprite> platform;
    unique_ptr<sf::Texture> texture;
    shared_ptr<Camera> camera;
    float platformWidth;
    float platformHeight;
};


#endif //AP_DOODLE_GAME_EV_GREEN_PLATFORM_H
