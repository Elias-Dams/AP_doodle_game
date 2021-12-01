/*
 * Alle entiteiten worden opgeslagen in de wereld, die
 * verantwoordelijk is voor het regelen van de algemene
 * spellogica en de interacties tussen de entiteiten die het
 * bevat, zoals het creëren en vernietigen van entiteiten en
 * botsingen detectie tussen hen. Je kunt deze botsingen
 * detecteren door basis kruisende rechthoeken te gebruiken.
 * Er is geen nodig om hier al te veel aandacht aan te besteden,
 * zoals het laten werken met complexere vormen of het voorspellen
 * van botsingen. Maar gebruik ook geen SFML utilities hier,
 * aangezien deze klasse deel uitmaakt van de logica bibliotheek
 */

#ifndef AP_DOODLE_GAME_WORLD_H
#define AP_DOODLE_GAME_WORLD_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <memory>
#include "design_patterns/Abstract_Factory.h"
#include "Random.h"
#include "Camera.h"

class World {
public:
    World();

    void update(float dt, const char &key);

    shared_ptr<EM_Player>  getPlayer() const;

    int getWidth() const;

    int getHeight() const;

    void create_platforms();
    void add_platforms();

    const vector<shared_ptr<EM_Platform>> &getPlatforms() const;

    bool colisionCheck(shared_ptr<EM_Platform> platform);

    shared_ptr<Camera> getCamera() const;



private:
    shared_ptr<EM_Player> player;
    Abstract_Factory factory;
    vector<shared_ptr<EM_Platform>> platforms;
    unique_ptr<Random> random;
    shared_ptr<Camera> camera;
    int height_of_last_platform;
    int platforms_per_view;
    int WIDTH;
    int HEIGHT;



};


#endif //AP_DOODLE_GAME_WORLD_H