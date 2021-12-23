
#ifndef AP_DOODLE_GAME_V_PLAYER_H
#define AP_DOODLE_GAME_V_PLAYER_H

#include "../../logic/Entity_Model/Entity_Model.h"
#include "../../logic/Namespaces.cpp"
#include "Entity_View.h"

/**
 * @class Player
 *
 * This is the view part of the player.
 * It handles the textures.
 */
class View::Player : public Entity_View {

public:
    /**
     * Player constructor.
     * constructs the Player whit given Entity model (this wil act as the subject whereby this player will observere)
     */
    Player(Entity_Model &subject, float playerWidth, float playerHeight, shared_ptr<Camera> camera);

    /**
    * @brief gets the sfml sprite
    *
    * This function gets the sfml sprite of the player
    *
    * @return the sfml sprite of the player
    */
    sf::Sprite getPlayer() const;

    void UpdatePosition(float xpos, float ypos) override;

    void UpdateSpringCollected() override;

    void UpdateJetpackCollected() override;

    void ResetTexture() override;

    ~Player() override;

private:
    void setTexture();

    sf::Sprite player; ///< sfml sprite of the player

    sf::Texture left_texture; ///< sfml standard jump left texture
    sf::Texture right_texture; ///< sfml standard jump right texture

    sf::Texture left_spring_texture;  ///< sfml medium jump left texture
    sf::Texture right_spring_texture;  ///< sfml medium jump right texture

    sf::Texture left_jetpack_texture; ///< sfml high jump left texture
    sf::Texture right_jetpack_texture; ///< sfml high jump right texture

    sf::Texture current_right_texture; ///< sfml current right texture of the player
    sf::Texture current_left_texture; ///<  sfml current left texture of the player

    shared_ptr<Camera> camera; ///< the camera to convert the coordinates to sfml coordinates

    bool left; ///< check if the player is going left
    bool right; ///< check if the player is going right
    float playerWidth; ///< width of the player
    float playerHeight; ///< height of the player
};


#endif//AP_DOODLE_GAME_PLAYER_H
