
#ifndef AP_DOODLE_GAME_ABSTRACT_FACTORY_H
#define AP_DOODLE_GAME_ABSTRACT_FACTORY_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "../Score.h"
#include "../Camera.h"
#include "../Entity_Model/EM_Player.h"
#include "../Entity_Model/EM_Platform_Types/EM_Green_Platform.h"
#include "../Entity_Model/EM_Platform_Types/EM_Blue_Platform.h"
#include "../Entity_Model/EM_Platform_Types/EM_Yellow_Platform.h"
#include "../Entity_Model/EM_Platform_Types/EM_White_Platform.h"
#include "../Entity_Model/EM_BG_Tile.h"
#include "../Entity_Model/EM_Bonus.h"
#include "../Entity_Model/EM_Bonus_Types/EM_Spring.h"
#include "../Entity_Model/EM_Bonus_Types/EM_Jetpack.h"



class Abstract_Factory {

public:

    virtual shared_ptr<EM_Player> createPlayer(float player_width, float player_height, float startposx, float startposy,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_Green_Platform> createGreenPlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_Blue_Platform> createBluePlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_White_Platform> createWhitePlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_Yellow_Platform> createYellowPlatform(float platform_width, float platform_height, float move_height,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_BG_Tile> createBackground(float background_width, float background_height, float startposx, float startposy,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_Spring> createSpring(float spring_width, float spring_height,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_Jetpack> createJetpack(float jetpack_width, float jetpack_height,shared_ptr<Camera> camera)= 0;

};


#endif //AP_DOODLE_GAME_ABSTRACT_FACTORY_H
