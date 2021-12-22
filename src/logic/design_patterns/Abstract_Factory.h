
#ifndef AP_DOODLE_GAME_ABSTRACT_FACTORY_H
#define AP_DOODLE_GAME_ABSTRACT_FACTORY_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "../Score.h"
#include "../Camera.h"
#include "../Entity_Model/Player.h"
#include "../Entity_Model/EM_Platform_Types/Green_Platform.h"
#include "../Entity_Model/EM_Platform_Types/Blue_Platform.h"
#include "../Entity_Model/EM_Platform_Types/Yellow_Platform.h"
#include "../Entity_Model/EM_Platform_Types/White_Platform.h"
#include "../Entity_Model/BG_Tile.h"
#include "../Entity_Model/Bonus.h"
#include "../Entity_Model/EM_Bonus_Types/Spring.h"
#include "../Entity_Model/EM_Bonus_Types/Jetpack.h"

class Abstract_Factory {

public:

    virtual shared_ptr<Model::Player> createPlayer(float player_width, float player_height, float startposx, float startposy, shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<Model::BG_Tile> createBackground(float background_width, float background_height, float startposx, float startposy, shared_ptr<Camera> camera) = 0;

    virtual shared_ptr<Model::Green_Platform> createGreenPlatform(float platform_width, float platform_height, shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<Model::Blue_Platform> createBluePlatform(float platform_width, float platform_height, shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<Model::White_Platform> createWhitePlatform(float platform_width, float platform_height, shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<Model::Yellow_Platform> createYellowPlatform(float platform_width, float platform_height, float move_height, shared_ptr<Camera> camera) = 0;

    virtual shared_ptr<Model::Spring> createSpring(float spring_width, float spring_height, shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<Model::Jetpack> createJetpack(float jetpack_width, float jetpack_height, shared_ptr<Camera> camera)= 0;

    virtual void delete_platform(weak_ptr<Model::Platform> platform) = 0;
    virtual void delete_player(weak_ptr<Model::Player> player) = 0;
    virtual void delete_bonus(weak_ptr<Model::Bonus> bonus) = 0;

};


#endif //AP_DOODLE_GAME_ABSTRACT_FACTORY_H
