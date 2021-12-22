
#include "EV_Spring.h"

View::EV_Spring::EV_Spring(Entity_Model &subject, float Width, float Height, shared_ptr<Camera> camera_) : EV_Bonus(subject), camera(camera_), spring_Width(Width), spring_Height(Height){
    // we initiaize a new platform

    spring = unique_ptr<sf::Sprite>(new sf::Sprite);
    texture = unique_ptr<sf::Texture>(new sf::Texture);

    try {
        if (!texture->loadFromFile("../Textures/Doodle/spring.png")){
            string error = "Loading spring failed";
            throw error;
        }
        else{
            // we give the spring a texture
            spring->setTexture(*texture);
        }
    }
    catch(string& a){
        cerr << a << endl;
    }

    spring->setScale( Width / texture->getSize().x , Height / texture->getSize().y );
    spring->setColor(sf::Color(82, 170, 228));
}

void View::EV_Spring::UpdatePosition(float xpos, float ypos){

    //cout << "jeej we get updates" << endl;

    spring->setPosition(camera->toGamewidth(xpos, spring_Width), camera->toGameheight(ypos, spring_Height));

}

sf::Sprite View::EV_Spring::getBonus() const {
    return *spring;
}

View::EV_Spring::~EV_Spring() {
    cout << "destructor of EV_Spring" << endl;
}

