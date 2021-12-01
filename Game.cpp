
#include "Game.h"

Game::Game() {
    world = make_shared<World>();
    window = make_shared<sf::RenderWindow>(sf::VideoMode(world->getWidth(), world->getHeight()),"doodle jump");
    ConcreteFactory = make_shared<Concrete_Factory>();

    PlayerView = ConcreteFactory->createPlayerView(world->getPlayer(), world->getPlayer()->getPlayerWidht(), world->getPlayer()->getPlayerHeight());
    for(shared_ptr<EM_Platform> platform : world->getPlatforms()){
        PlatformsView.push_back(ConcreteFactory->createPlatformView(platform, platform->getPlatformWidht(), platform->getPlatformHeight()));
    }

    clock = Stopwatch::GetInstance();

    view = make_shared<sf::View>(sf::FloatRect(0, 0, world->getWidth(), world->getHeight()));

    auto image = sf::Image{};

    try {
        if (!image.loadFromFile("../Textures/Doodle_Jump_icon.png")){
            string error = "Loading icon failed";
            throw error;
        }
        else{
            // we give the window a icon
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
        for(shared_ptr<EV_Platform> platform : PlatformsView){
            window->draw(platform->getPlatform());
        }
        window->draw(PlayerView->getPlayer());
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
    world->update(dt, key);
    //cout << world->getCamera()->getHeightdiff() << endl;
    view->move(0.0f, -world->getCamera()->getHeightdiff());

    // update platforms;
    for(shared_ptr<EM_Platform> platform : world->getPlatforms()){
        shared_ptr<EV_Platform> platform_ = ConcreteFactory->createPlatformView(platform, platform->getPlatformWidht(), platform->getPlatformHeight());
        PlatformsView.push_back(platform_);
    }
}

Game::~Game() {
}
