
#include "Game.h"

Game::Game() {

    /// make the game
    ConcreteFactory = make_shared<Concrete_Factory>();
    world = std::make_unique<World>(ConcreteFactory);
    window = make_unique<sf::RenderWindow>(sf::VideoMode(world->getWidth(), world->getHeight()), "doodle jump");

    clock = Stopwatch::GetInstance();

    view = make_shared<sf::View>(sf::FloatRect(0, 0, world->getWidth(), world->getHeight()));

    highscore = 0;

    for (shared_ptr<EM_Platform> platform: world->getPlatforms()) {
        window->draw(ConcreteFactory->get_platform(platform).lock()->getPlatform());
    }


    /// when the game starts the game state is start

    GameState = start;

    /// Load the menu textures
    this->LoadTextures();

    /// make score_text
    score_text.setFont(font);
    score_text.setCharacterSize(50);
    score_text.setString(to_string(ConcreteFactory->get_score().lock()->getscore()));
    score_text.setFillColor(sf::Color::Black);

    /// make highscore
    highscore_text.setFont(font);
    highscore_text.setCharacterSize(50);
    highscore_text.setFillColor(sf::Color::Black);

    /// make button

    Button.setTexture(ButtonTexture);
    Button.setPosition(world->getWidth() / 2 - Button.getLocalBounds().width / 2,
                       world->getHeight() / 2 - Button.getLocalBounds().height / 2);

}

void Game::LoadTextures() {
    auto image = sf::Image{};

    try {
        if (!image.loadFromFile("../Textures/Doodle/Doodle_Jump_icon.png")) {
            string error = "Loading icon failed";
            throw error;
        }
        if (!font.loadFromFile("../Textures/AmaticSC-Regular.ttf")) {
            string error = "Loading font failed";
            throw error;
        }
        if (!ButtonTexture.loadFromFile("../Textures/Doodle/button_newgame.png")) {
            string error = "Loading buttontexture failed";
            throw error;
        }
        if (!ButtonTexture_pressed.loadFromFile("../Textures/Doodle/button_newgame_active.png")) {
            string error = "Loading buttontexture failed";
            throw error;
        } else {
            // we give the window an icon
            window->setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
        }
    }
    catch (string &a) {
        cerr << a << endl;
    }
}

void Game::run() {
    float dt;
    window->setFramerateLimit(120);

    while (window->isOpen()) {
        dt = clock->mark_time();

        this->update(dt);

        window->setView(*view);

        this->drawGame();

        //cout << "dt: " << dt << "  " << "fps: " << 1 / dt << endl;
    }

}



void Game::update(const float &dt) {

    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window->close();
        }
        if (GameState == gameover || GameState == start) {
            if (event.type == sf::Event::MouseMoved && MouseOnButton(Button)) {
                Button.setTexture(ButtonTexture_pressed);

            } else {
                Button.setTexture(ButtonTexture);
            }
            /// when the restart button is clicked the game starts
            if (event.type == sf::Event::MouseButtonPressed && MouseOnButton(Button)) {
                GameState = gameloop;
                world->getPlayer()->resetmaxheight();
            }
        }
    }

    if (GameState == start) {

        this->gameStart(dt);

    } else if (GameState == gameloop) {

        this->gameLoop(dt);

    } else if (GameState == gameover) {

        this->gameOver(dt);

    }

}

void Game::gameStart(const float &dt) {
    world->startstate(dt);
}

void Game::gameLoop(const float &dt) {
    /// update the pressed key
    char key = 'X';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        key = 'Q';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        key = 'D';
    }

    /// update the world
    world->update(dt, key);

    /// update the view according to the player in the world
    view->setCenter(world->getWidth() / 2, world->getCamera()->getConvertedHeight());

    /// update the position/value of the score
    score_text.setPosition(0, world->getCamera()->getConvertedHeight() - (world->getHeight() / 2));
    score_text.setString(to_string(ConcreteFactory->get_score().lock()->getscore()));

    /// check if game is over
    if (world->isGameOver()) {
        GameState = gameover;
        can_reset = true;
    }
}

void Game::gameOver(const float &dt) {

    /// resetting the world
    if (can_reset) {
        /// set the score for the endgame screen;
        score_text.setString("Score : " + to_string(ConcreteFactory->get_score().lock()->getscore()));
        score_text.setPosition(world->getWidth() / 2 - score_text.getGlobalBounds().width / 2,
                               world->getHeight() / 2 - score_text.getGlobalBounds().height / 2 - 70);

        /// update the highscore
        if (highscore <= ConcreteFactory->get_score().lock()->getscore()) {
            highscore = ConcreteFactory->get_score().lock()->getscore();
        }

        /// set the highscore for the endgame screen;
        highscore_text.setString("highscore : " + to_string(highscore));
        highscore_text.setPosition(world->getWidth() / 2 - highscore_text.getGlobalBounds().width / 2,
                                   world->getHeight() / 2 - highscore_text.getGlobalBounds().height / 2 - 130);

        world->Reset();
        can_reset = false;
    }
    view->setCenter(world->getWidth() / 2, world->getCamera()->getConvertedHeight());
    world->startstate(dt);
}

void Game::drawGame() {
    window->clear(sf::Color::White);

    /// start draws
    if (GameState == start) {
        for (weak_ptr<View::EV_BG_Tile> background: ConcreteFactory->getBackgrounds()) {
            window->draw(background.lock()->getBackground());
        }

        for (shared_ptr<EM_Platform> platform: world->getPlatforms()) {
            window->draw(ConcreteFactory->get_platform(platform).lock()->getPlatform());
        }

        window->draw(ConcreteFactory->get_player(world->getPlayer()).lock()->getPlayer());

        window->draw(Button);
    }
        /// game loop draws
    else if (GameState == gameloop) {

        for (weak_ptr<View::EV_BG_Tile> background: ConcreteFactory->getBackgrounds()) {
            window->draw(background.lock()->getBackground());
        }

        for (shared_ptr<EM_Platform> platform: world->getPlatforms()) {
            window->draw(ConcreteFactory->get_platform(platform).lock()->getPlatform());
        }

        map<shared_ptr<EM_Platform>, shared_ptr<EM_Bonus>> bonus = world->getBonusses();
        for (std::map<shared_ptr<EM_Platform>, shared_ptr<EM_Bonus>>::iterator it = bonus.begin();
             it != bonus.end(); it++) {
            window->draw(ConcreteFactory->get_bonus(it->second).lock()->getBonus());
        }

        window->draw(ConcreteFactory->get_player(world->getPlayer()).lock()->getPlayer());

        window->draw(score_text);

    }
        /// game over draws
    else if (GameState == gameover) {
        for (weak_ptr<View::EV_BG_Tile> background: ConcreteFactory->getBackgrounds()) {
            window->draw(background.lock()->getBackground());
        }

        for (shared_ptr<EM_Platform> platform: world->getPlatforms()) {
            window->draw(ConcreteFactory->get_platform(platform).lock()->getPlatform());
        }

        window->draw(ConcreteFactory->get_player(world->getPlayer()).lock()->getPlayer());
        window->draw(score_text);
        window->draw(highscore_text);
        window->draw(Button);
    }

    window->display();
}

bool Game::MouseOnButton(sf::Sprite _button) {

    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

    bool mouseInButton = mousePosition.x >= _button.getPosition().x
                         && mousePosition.x <= _button.getPosition().x + _button.getGlobalBounds().width
                         && mousePosition.y >= _button.getPosition().y
                         && mousePosition.y <= _button.getPosition().y + _button.getGlobalBounds().height;
    return mouseInButton;
}

Game::~Game() {
    cout << "---destructor of game---" << endl;
    cout << "--WORLD--" << endl;
    world.reset();
    cout << "-----------" << endl;
    cout << "--FACTORY--" << endl;
    ConcreteFactory.reset();
    cout << "-----------" << endl;
    cout << "--CLOCK--" << endl;
    clock.reset();
    cout << "-----------" << endl;
    cout << "--VIEW--" << endl;
    view.reset();
    cout << "-----------" << endl;
    cout << "--WINDOW--" << endl;
    window.reset();
    cout << "-----------" << endl;

    cout << "-------end-game---------" << endl;
}
