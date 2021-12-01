
#ifndef AP_DOODLE_GAME_EV_PLATFORM_H
#define AP_DOODLE_GAME_EV_PLATFORM_H

#include "Entity_View.h"
#include <SFML/Graphics.hpp>

class EV_Platform : public Entity_View{
public:
    EV_Platform(Entity_Model &subject, float platformWidth, float platformHeight);

    void Update(float xpos, float ypos) override;

    sf::Sprite getPlatform() const;

private:
    sf::Sprite *platform;
    sf::Texture *texture;
};

#endif //AP_DOODLE_GAME_EV_PLATFORM_H
