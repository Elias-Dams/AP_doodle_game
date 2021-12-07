

#ifndef AP_DOODLE_GAME_EV_YELLOW_PLATFORM_H
#define AP_DOODLE_GAME_EV_YELLOW_PLATFORM_H

#include "../EV_Platform.h"

class EV_Yellow_Platform : public EV_Platform{
public:
    EV_Yellow_Platform(Entity_Model &subject, float platformWidth, float platformHeight);

    void Update(float xpos, float ypos) override;

    sf::Sprite getPlatform() const;

    virtual ~EV_Yellow_Platform();

private:
    unique_ptr<sf::Sprite> platform;
    unique_ptr<sf::Texture> texture;
};

#endif //AP_DOODLE_GAME_EV_YELLOW_PLATFORM_H
