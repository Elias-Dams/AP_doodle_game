
#ifndef AP_DOODLE_GAME_V_PLAYER_H
#define AP_DOODLE_GAME_V_PLAYER_H

#include "../../logic/Entity_Model/Entity_Model.h"
#include "../../logic/Namespaces.cpp"
#include "Entity_View.h"

class View::Player : public Entity_View {

public:
    Player(Entity_Model &subject, float playerWidth, float playerHeight, shared_ptr<Camera> camera);

    sf::Sprite getPlayer() const;

    void UpdatePosition(float xpos, float ypos) override;

    void UpdateSpringCollected() override;

    void UpdateJetpackCollected() override;

    void ResetTexture() override;

    ~Player() override;

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


#endif//AP_DOODLE_GAME_PLAYER_H
