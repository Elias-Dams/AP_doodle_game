
#ifndef AP_DOODLE_GAME_EV_PLAYER_H
#define AP_DOODLE_GAME_EV_PLAYER_H

#include "Entity_View.h"
#include <SFML/Graphics.hpp>

class EV_Player : public Entity_View{

public:

    EV_Player(Entity_Model &subject, float playerWidth, float playerHeight);

    void Update(float xpos, float ypos) override;

    sf::Sprite getPlayer() const;

private:
    sf::Sprite player;
    sf::Texture left_texture;
    sf::Texture right_texture;
};


#endif //AP_DOODLE_GAME_EM_PLAYER_H
