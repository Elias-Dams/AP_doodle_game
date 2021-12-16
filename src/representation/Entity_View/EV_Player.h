
#ifndef AP_DOODLE_GAME_EV_PLAYER_H
#define AP_DOODLE_GAME_EV_PLAYER_H

#include "Entity_View.h"
#include "../../logic/Entity_Model/Entity_Model.h"

class EV_Player : public Entity_View{

public:

    EV_Player(Entity_Model &subject, float playerWidth, float playerHeight, shared_ptr<Camera> camera);

    sf::Sprite getPlayer() const;

    void UpdatePosition(float xpos, float ypos) override;

    void UpdateSpringCollected() override;

    void UpdateJetpackCollected() override;

    void ResetTexture() override;

    virtual ~EV_Player();

private:
    void setTexture();

    sf::Sprite player;

    sf::Texture left_texture;
    sf::Texture right_texture;

    sf::Texture left_spring_texture;
    sf::Texture right_spring_texture;

    sf::Texture left_jetpack_texture;
    sf::Texture right_jetpack_texture;

    sf::Texture current_right_texture;
    sf::Texture current_left_texture;

    shared_ptr<Camera> camera;

    bool left;
    bool right;
    float playerWidth;
    float playerHeight;
};


#endif //AP_DOODLE_GAME_EM_PLAYER_H
