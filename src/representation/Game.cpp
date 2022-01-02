
#include "Game.h"

Game::Game() {

    // make the game
    ConcreteFactory = make_shared<Concrete_Factory>();
    world = std::make_unique<World>(ConcreteFactory);
    window = make_unique<sf::RenderWindow>(sf::VideoMode(world->getWidth(), world->getHeight()), "doodle jump");

    weak_ptr<Stopwatch>clock = Stopwatch::GetInstance(); // initialise the singleton

    view = make_shared<sf::View>(sf::FloatRect(0, 0, world->getWidth(), world->getHeight()));

    highscore = 0;

    // when the game starts the game state is start
    GameState = start;

    // Load the menu textures
    this->LoadTextures();

    // make score_text
    score_text.setFont(font);
    score_text.setCharacterSize(50);
    score_text.setString(to_string(ConcreteFactory->get_score().lock()->getscore()));
    score_text.setFillColor(sf::Color::Black);

    // make highscore
    highscore_text.setFont(font);
    highscore_text.setCharacterSize(50);
    highscore_text.setFillColor(sf::Color::Black);

    // make button
    Button.setTexture(ButtonTexture);
    Button.setPosition(world->getWidth() / 2 - Button.getLocalBounds().width / 2,
                       world->getHeight() / 2 - Button.getLocalBounds().height / 2);

    can_reset = false;
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
    } catch (string &a) {
        cerr << a << endl;
    }
}

void Game::run() {
    float dt;
    double accumulator = 0.0;
    window->setFramerateLimit(120);
    weak_ptr<Stopwatch> clock = Stopwatch::GetInstance();

    while (window->isOpen()) {
        dt = clock.lock()->mark_time();

        if ( dt > 0.25 )
            dt = 0.25;

        accumulator += dt;

        while ( accumulator >= 0.01 )
        {
            this->update(dt);

            window->setView(*view);

            accumulator -= dt;

        }

        this->drawGame();

        //cout << "dt: " << dt << "  " << "fps: " << 1 / dt << endl;
    }
}


void Game::update(const float &dt) {

    sf::Event event;

    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::Resized:
                sf::Vector2<float> visibleArea(((float)event.size.width/(float)event.size.height) * (float)world->getHeight(), world->getHeight());
                view->setSize(visibleArea);
                break;
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
            // when the restart button is clicked the game starts
            if (event.type == sf::Event::MouseButtonPressed && MouseOnButton(Button)) {
                GameState = gameloop;
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
    // update the pressed key
    char key = 'X';
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        key = 'Q';
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        key = 'D';
    }

    // update the world
    world->update(dt, key);

    // update the view according to the player in the world
    view->setCenter(world->getWidth() / 2.0f, world->getCamera()->getConvertedHeight());

    // update the position/value of the score
    score_text.setPosition(0, world->getCamera()->getConvertedHeight() - (world->getHeight() / 2.0f));
    score_text.setString(to_string(ConcreteFactory->get_score().lock()->getscore()));

    // check if game is over
    if (world->isGameOver()) {
        GameState = gameover;
        can_reset = true;
    }
}

void Game::gameOver(const float &dt) {

    // resetting the world
    if (can_reset) {
        // set the score for the endgame screen;
        score_text.setString("Score : " + to_string(ConcreteFactory->get_score().lock()->getscore()));
        score_text.setPosition(world->getWidth() / 2.0f - score_text.getGlobalBounds().width / 2.0f,
                               world->getHeight() / 2.0f - score_text.getGlobalBounds().height / 2.0f - 70.0f);

        // update the highscore
        if (highscore <= ConcreteFactory->get_score().lock()->getscore()) {
            highscore = ConcreteFactory->get_score().lock()->getscore();
        }

        // set the highscore for the endgame screen;
        highscore_text.setString("highscore : " + to_string(highscore));
        highscore_text.setPosition(world->getWidth() / 2.0f - highscore_text.getGlobalBounds().width / 2.0f,
                                   world->getHeight() / 2.0f - highscore_text.getGlobalBounds().height / 2.0f - 130.0f);

        world->Reset();
        can_reset = false;
    }
    view->setCenter(world->getWidth() / 2.0f, world->getCamera()->getConvertedHeight());
    world->startstate(dt);
}

void Game::drawGame() {
    window->clear(sf::Color::Black);

    // start draws
    if (GameState == start) {

        for (const weak_ptr<View::BG_Tile> &background : ConcreteFactory->getBackgrounds()) {
            window->draw(background.lock()->getBackground());
        }

        for (const shared_ptr<Platform> &platform : world->getPlatforms()) {
            window->draw(ConcreteFactory->get_platform(platform).lock()->getPlatform());
        }

        window->draw(ConcreteFactory->get_player().lock()->getPlayer());

        window->draw(Button);
    }
    // game loop draws
    else if (GameState == gameloop) {

        for (const weak_ptr<View::BG_Tile> &background : ConcreteFactory->getBackgrounds()) {
            window->draw(background.lock()->getBackground());
        }

        for (const shared_ptr<Platform> &platform : world->getPlatforms()) {
            window->draw(ConcreteFactory->get_platform(platform).lock()->getPlatform());
        }

        map<shared_ptr<Platform>, shared_ptr<Bonus>> bonus = world->getBonuses();
        for (std::map<shared_ptr<Platform>, shared_ptr<Bonus>>::iterator it = bonus.begin();
             it != bonus.end(); it++) {
            window->draw(ConcreteFactory->get_bonus(it->second).lock()->getBonus());
        }

        window->draw(ConcreteFactory->get_player().lock()->getPlayer());

        window->draw(score_text);

    }
    // game over draws
    else if (GameState == gameover) {
        for (const weak_ptr<View::BG_Tile> &background : ConcreteFactory->getBackgrounds()) {
            window->draw(background.lock()->getBackground());
        }

        for (const shared_ptr<Platform> &platform : world->getPlatforms()) {
            window->draw(ConcreteFactory->get_platform(platform).lock()->getPlatform());
        }

        window->draw(ConcreteFactory->get_player().lock()->getPlayer());
        window->draw(score_text);
        window->draw(highscore_text);
        window->draw(Button);
    }

    window->display();
}

bool Game::MouseOnButton(const sf::Sprite &_button) const{

    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

    bool mouseInButton = (float) mousePosition.x >= _button.getPosition().x
                         && (float) mousePosition.x <= _button.getPosition().x + _button.getGlobalBounds().width
                         && (float) mousePosition.y >= _button.getPosition().y
                         && (float) mousePosition.y <= _button.getPosition().y + _button.getGlobalBounds().height;
    return mouseInButton;
}

Game::~Game() {
    world.reset();
    ConcreteFactory.reset();
    view.reset();
    window.reset();
}
