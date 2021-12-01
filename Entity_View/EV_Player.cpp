
#include "EV_Player.h"

EV_Player::EV_Player(Entity_Model &subject, float playerWidth , float playerHeight) : Entity_View(subject) {
    // we initiaize a new player

    player = new sf::Sprite;
    texture = new sf::Texture;

    try {
        if (!texture->loadFromFile("../Textures/doodle-left.png")){
            string error = "Loading player failed";
            throw error;
        }
        else{
            // we give the player a texture
            player->setTexture(*texture);
        }
    }
    catch(string& a){
        cerr << a << endl;
    }

    player->setScale( playerWidth / texture->getSize().x , playerHeight / texture->getSize().y );
}

void EV_Player::Update(float xpos, float ypos){
    //cout << "we are getting updates" << endl;
    ypos = 500-ypos;
    player->setPosition(xpos, ypos);
}

sf::Sprite EV_Player::getPlayer() const {
    return *player;
}



