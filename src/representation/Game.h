
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
    /**
     * Game constructor.
     * constructs the game
     */
    Game();

    /**
    * @brief main game loop
    *
    * this function contains the main game loop
    */
    void run();

    /**
    * @brief updates the main game loop
    *
    * this function updates the main game loop
    *
    * @param dt: delta time (time it takes to render a frame)
    */
    void update(const float &dt);

    /**
    * @brief draws the entities
    *
    * this function draws the entities on the screen
    */
    void drawGame();

    /**
    * @brief game start
    *
    * this function handles the game start state
    *
    * @param dt: delta time (time it takes to render a frame)
    */
    void gameStart(const float &dt);

    /**
    * @brief game loop
    *
    * this function handles the game loop
    *
    * @param dt: delta time (time it takes to render a frame)
    */
    void gameLoop(const float &dt);

    /**
    * @brief game over
    *
    * this function handles the game over state
    * This function resets the game to the state it was in when it was first initialized
    *
    * @param dt: delta time (time it takes to render a frame)
    */
    void gameOver(const float &dt);

    ~Game();

private:

    /// check if the mouse in on the button
    bool MouseOnButton(const sf::Sprite& Button);

    /// loads the textures
    void LoadTextures();

    /// game
    unique_ptr<sf::RenderWindow> window; ///< winsow
    shared_ptr<Concrete_Factory> ConcreteFactory; ///< ConcreteFactory
    unique_ptr<World> world; ///< world

    shared_ptr<sf::View> view; ///< view

    gamestates GameState; ///< gamestate enum
    bool can_reset{}; ///< check if game can reset
    int highscore; ///< highscore of the player

    /// menu
    sf::Font font; ///< sfml font
    sf::Text score_text; ///< text to show the score on screen
    sf::Text highscore_text; ///< text to show the highscorescore on screen
    sf::Sprite Button; ///< sfml startbutton
    sf::Texture ButtonTexture; ///< sfml texture of startbutton
    sf::Texture ButtonTexture_pressed; ///< sfml texture of startbutton pressed
};


#endif//AP_DOODLE_GAME_GAME_H
