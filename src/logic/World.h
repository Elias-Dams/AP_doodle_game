
#ifndef AP_DOODLE_GAME_WORLD_H
#define AP_DOODLE_GAME_WORLD_H

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <typeinfo>
#include "design_patterns/Abstract_Factory.h"
#include "Random.h"
#include "Camera.h"

using namespace Model;

class World {
public:

    World(const shared_ptr<Abstract_Factory> &factory);

    void startstate(float dt);

    void update(float dt, const char &key);

    /// ---important getters---
    shared_ptr<EM_Player> getPlayer() const;

    int getWidth() const;

    int getHeight() const;

    const pair<shared_ptr<EM_BG_Tile>, shared_ptr<EM_BG_Tile>> &getBackground() const;

    shared_ptr<Camera> getCamera() const;

    const vector<shared_ptr<EM_Platform>> &getPlatforms() const;

    const map<shared_ptr<EM_Platform>, shared_ptr<EM_Bonus>> &getBonusses() const;
    /// ------------------------

    void Reset();

    bool isGameOver() const;

    virtual ~World();


private:

    void create_start_platform();

    void create_platforms();

    void add_platforms();

    bool colisionCheck(shared_ptr<Entity_Model> entity);

    shared_ptr<Abstract_Factory> factory;

    shared_ptr< EM_Player > player;
    vector< shared_ptr< EM_Platform > > platforms;
    map< shared_ptr< EM_Platform >, shared_ptr< EM_Bonus>  > bonusses;
    pair< shared_ptr< EM_BG_Tile >, shared_ptr < EM_BG_Tile> > background;

    unique_ptr<Random> random;
    shared_ptr<Camera> camera;

    bool GameOver;
    int constant;

    int last_max_of_radius;
    int height_of_the_last_platform;
    int platforms_per_view;
    int WIDTH;
    int HEIGHT;

};


#endif //AP_DOODLE_GAME_WORLD_H
