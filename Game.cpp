
#include "Game.h"

Game::Game() {

    ConcreteFactory = make_shared<Concrete_Factory>();
    world = std::make_unique<World>(ConcreteFactory);
    window = make_shared<sf::RenderWindow>(sf::VideoMode(world->getWidth(), world->getHeight()),"doodle jump");

    clock = Stopwatch::GetInstance();

    view = make_shared<sf::View>(sf::FloatRect(0, 0, world->getWidth(), world->getHeight()));

    GameOver = false;
    highscore = 0;

    /// Load the menu textures
    this->LoadTextures();

    /// make score_text
    score_text.setFont(font);
    score_text.setCharacterSize(50);
    score_text.setString(to_string(ConcreteFactory->get_score()->getscore()));
    score_text.setFillColor(sf::Color::Black);

    /// make highscore
    highscore_text.setFont(font);
    highscore_text.setCharacterSize(50);
    highscore_text.setFillColor(sf::Color::Black);

    /// make button

    Button.setTexture(ButtonTexture);
    Button.setPosition(world->getWidth()/2 - Button.getLocalBounds().width/2, world->getHeight()/2 -Button.getLocalBounds().height/2);

}

void Game::LoadTextures(){
    auto image = sf::Image{};

    try {
        if (!image.loadFromFile("../Textures/Doodle_Jump_icon.png")){
            string error = "Loading icon failed";
            throw error;
        }
        if(!font.loadFromFile("../Textures/AmaticSC-Regular.ttf")){
            string error = "Loading font failed";
            throw error;
        }
        if(!ButtonTexture.loadFromFile("../Textures/button_newgame.png")){
            string error = "Loading buttontexture failed";
            throw error;
        }
        if(!ButtonTexture_pressed.loadFromFile("../Textures/button_newgame_active.png")){
            string error = "Loading buttontexture failed";
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

        this->drawGame();

        //cout << "dt: " << dt << "  " << "fps: " << 1 / dt << endl;
    }

}

void Game::update(const float& dt){

    sf::Event event;

    while (window->pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window->close();
        }
        if(GameOver){
            if (event.type == sf::Event::MouseMoved && MouseOnButton(Button)){
                Button.setTexture(ButtonTexture_pressed);

            }
            else{
                Button.setTexture(ButtonTexture);
            }

            if (event.type == sf::Event::MouseButtonPressed && MouseOnButton(Button)){
                cout << "true" << endl;
                GameOver = false;
            }
        }
    }

    /// update the pressed key
    char key = 'X';
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        key = 'Q';
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        key = 'D';
    }

    /// if gameover we don't update the game
    if(!GameOver){

        /// update the world
        world->update(dt, key);

        /// check if game is over
        if(world->isGameOver()){
            this->gameOver();
            GameOver = true;
            return;
        }

        /// update the view according to the player in the world

        view->setCenter(world->getWidth()/2, world->getCamera()->getConvertedHeight());

        /// update the position/value of the score
        score_text.setPosition(0, world->getCamera()->getConvertedHeight()-(world->getHeight()/2));
        score_text.setString(to_string(ConcreteFactory->get_score()->getscore()));

    }


}

void Game::drawGame(){
    window->clear(sf::Color::White);

    if(!GameOver){
        for(shared_ptr<EM_Platform> platform : world->getPlatforms()){
            window->draw(ConcreteFactory->get_platform(platform)->getPlatform());
        }

        window->draw(ConcreteFactory->get_player(world->getPlayer())->getPlayer());

        window->draw(score_text);

    }
    else{
        window->draw(score_text);
        window->draw(highscore_text);
        window->draw(Button);
    }


    window->display();
}

void Game::gameOver(){
    /// set the score for the endgame screen;
    score_text.setString("Score : " + to_string(ConcreteFactory->get_score()->getscore()));
    score_text.setPosition(world->getWidth()/2 - score_text.getGlobalBounds().width/2,
                           world->getHeight()/2 - score_text.getGlobalBounds().height/2-70);

    /// update the highscore
    if (highscore <= ConcreteFactory->get_score()->getscore()){
        highscore = ConcreteFactory->get_score()->getscore();
    }

    /// set the highscore for the endgame screen;
    highscore_text.setString("highscore : " + to_string(highscore));
    highscore_text.setPosition(world->getWidth()/2 - highscore_text.getGlobalBounds().width/2,
                               world->getHeight()/2 - highscore_text.getGlobalBounds().height/2-130);

    /// resetting the world
    world->Reset();
    view->setCenter(world->getWidth()/2, world->getCamera()->getConvertedHeight());
}

bool Game::MouseOnButton(sf::Sprite _button) {

    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

    bool mouseInButton =    mousePosition.x >= _button.getPosition().x
                            && mousePosition.x <= _button.getPosition().x + _button.getGlobalBounds().width
                            && mousePosition.y >= _button.getPosition().y
                            && mousePosition.y <= _button.getPosition().y + _button.getGlobalBounds().height;
    return mouseInButton;
}

Game::~Game() {

}
