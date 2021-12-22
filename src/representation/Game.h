
#ifndef AP_DOODLE_GAME_GAME_H
#define AP_DOODLE_GAME_GAME_H

#include "../logic/Stopwatch.h"
#include "../logic/World.h"
#include "design_patterns/Concrete_Factory.h"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

enum gamestates {
    start,
    gameloop,
    gameover
};

class Game {

public:
    Game();

    /// this function contains the main game loop
    void run();

    /// this function updates the main game loop
    void update(const float &dt);

    /// this function draws the entitys on the screen
    void drawGame();

    /// making the gamestart
    void gameStart(const float &dt);

    /// generate the world when playing
    void gameLoop(const float &dt);

    /// resets the world
    void gameOver(const float &dt);

    /// check if the mouse in on the button
    bool MouseOnButton(sf::Sprite Button);

    void LoadTextures();

    ~Game();

private:
    /// game
    unique_ptr<sf::RenderWindow> window; ///< winsow
    shared_ptr<Concrete_Factory> ConcreteFactory; ///< ConcreteFactory
    unique_ptr<World> world; ///< world
    shared_ptr<Stopwatch> clock; ///< clock
    shared_ptr<sf::View> view; /// view

    gamestates GameState; /// gamestate enum
    bool can_reset; /// check if game can reset
    int highscore; /// highscore of the player

    /// menu
    sf::Font font; /// sfml font
    sf::Text score_text; /// text to show the score on screen
    sf::Text highscore_text; /// text to show the highscorescore on screen
    sf::Sprite Button; /// sfml startbutton
    sf::Texture ButtonTexture; /// sfml texture of startbutton
    sf::Texture ButtonTexture_pressed; /// sfml texture of startbutton pressed
};


#endif//AP_DOODLE_GAME_GAME_H
