
#include "Game.h"

Game::Game() {

    ConcreteFactory = make_shared<Concrete_Factory>();
    world = make_shared<World>(ConcreteFactory);
    window = make_shared<sf::RenderWindow>(sf::VideoMode(world->getWidth(), world->getHeight()),"doodle jump");

    clock = Stopwatch::GetInstance();

    view = make_shared<sf::View>(sf::FloatRect(0, 0, world->getWidth(), world->getHeight()));

    auto image = sf::Image{};

    try {
        if (!image.loadFromFile("../Textures/Doodle_Jump_icon.png")){
            string error = "Loading icon failed";
            throw error;
        }
        else{
            // we give the window an icon
            window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
        }
    }
    catch(string& a){
        cerr << a << endl;
    }

}

void Game::run(){
    float dt;
    window->setFramerateLimit(60);

    while (window->isOpen())
    {
        dt = clock->mark_time();

        this->update(dt);

        window->setView(*view);
        window->clear(sf::Color::White);

        for(shared_ptr<EM_Platform> platform : world->getPlatforms()){
            window->draw(ConcreteFactory->get_platform(platform)->getPlatform());
        }

        window->draw(ConcreteFactory->get_player(world->getPlayer())->getPlayer());
        window->display();

        //cout << "dt: " << dt << "  " << "fps: " << 1 / dt << endl;
    }

}

void Game::update(const float& dt){

    sf::Event event;

    while (window->pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window->close();
    }

    // update
    char key;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        key = 'Q';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        key = 'D';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        key = 'Q';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        key = 'D';
    }
    world->update(dt, key);
    //cout << world->getCamera()->getHeightdiff() << endl;
    //view->move(0.0f, -world->getCamera()->getHeightdiff());
    view->setCenter(world->getWidth()/2, -world->getCamera()->getHeight()+world->getHeight());

}

Game::~Game() {
}
