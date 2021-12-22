
#include "EV_Jetpack.h"

View::EV_Jetpack::EV_Jetpack(Entity_Model &subject, float Width, float Height, shared_ptr<Camera> camera_) : EV_Bonus(subject), camera(camera_), jetpack_Width(Width), jetpack_Height(Height){
    // we initiaize a new platform

    jetpack = unique_ptr<sf::Sprite>(new sf::Sprite);
    texture = unique_ptr<sf::Texture>(new sf::Texture);

    try {
        if (!texture->loadFromFile("../Textures/Doodle/raketa_on_panel.png")){
            string error = "Loading jetpack failed";
            throw error;
        }
        else{
            // we give the jetpack a texture
            jetpack->setTexture(*texture);
        }
    }
    catch(string& a){
        cerr << a << endl;
    }

    jetpack->setScale( Width / texture->getSize().x , Height / texture->getSize().y );
    jetpack->setColor(sf::Color(82, 170, 228));
}

void View::EV_Jetpack::UpdatePosition(float xpos, float ypos){
    //cout << "jeej we get updates" << endl;

    jetpack->setPosition(camera->toGamewidth(xpos, jetpack_Width), camera->toGameheight(ypos, jetpack_Height));
}

sf::Sprite View::EV_Jetpack::getBonus() const {
    return *jetpack;
}

View::EV_Jetpack::~EV_Jetpack() {
    cout << "destructor of EV_Jetpack" << endl;
}
