
#include "EV_Player.h"

#include <utility>

EV_Player::EV_Player(Entity_Model &subject, float playerWidth_ , float playerHeight_ , shared_ptr<Camera> camera_) : Entity_View(subject),camera(camera_),playerWidth(playerWidth_),playerHeight(playerHeight_){
    // we initiaize a new player

    try {
        if (!left_texture.loadFromFile("../Textures/doodle-left.png")){
            string error = "Loading player failed";
            throw error;
        }
        if (!right_texture.loadFromFile("../Textures/doodle-right.png")){
            string error = "Loading player failed";
            throw error;
        }
        else{
            // we give the player a texture
            player.setTexture(right_texture);
        }
    }
    catch(string& a){
        cerr << a << endl;
    }

    player.setScale( playerWidth / right_texture.getSize().x , playerHeight / right_texture.getSize().y );
}

void EV_Player::Update(float xpos, float ypos, bool reset){
    sf::Vector2f prev_coordiantes = player.getPosition();
    if(prev_coordiantes.x > xpos){
        player.setTexture(left_texture);
    }
    else if(prev_coordiantes.x < xpos){
        player.setTexture(right_texture);
    }
    //cout << "we are getting updates" << endl;

    player.setPosition(camera->toGamewidth(xpos, playerWidth),camera->toGameheight(ypos, playerHeight));
}

sf::Sprite EV_Player::getPlayer() const {
    return player;
}



