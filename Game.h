/*
 * Als onderdeel van de spel representatie, is deze klasse
 * verantwoordelijk voor het opzetten van alles wat niet
 * gerelateerd is aan de basislogica van het spel.
 * Voorbeelden:
 * - SFML venster
 * - het ontvangen van gebruikersinteractie en deze doorgeven aan de World
 * - het instantiëren van concrete fabrieken
 * - uitvoeren van de gameloop
 */

#ifndef AP_DOODLE_GAME_GAME_H
#define AP_DOODLE_GAME_GAME_H

#include <iostream>
#include <list>
#include <string>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "Stopwatch.h"
#include "World.h"
#include "design_patterns/Concrete_Factory.h"


using namespace std;

class Game {

public:
    Game();

    /// this function contains the main game loop
    void run();

    /// this function updates the main game loop
    void update(const float& dt);

    /// this function draws the entitys on the screen
    void drawGame();

    /// resets the world
    void gameOver();

    /// check if the mouse in on the button
    bool MouseOnButton(sf::Sprite Button);

    void LoadTextures();

    ~Game();

private:
    /// game
    shared_ptr<sf::RenderWindow> window;
    shared_ptr<Concrete_Factory> ConcreteFactory;
    unique_ptr<World> world;
    shared_ptr<Stopwatch> clock;
    shared_ptr<sf::View>view;

    int highscore;
    bool GameOver;

    /// menu
    sf::Font font;
    sf::Text score_text;
    sf::Text highscore_text;
    sf::Sprite Button;
    sf::Texture ButtonTexture;
    sf::Texture ButtonTexture_pressed;




};


#endif //AP_DOODLE_GAME_GAME_H
