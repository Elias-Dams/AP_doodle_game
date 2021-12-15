
#ifndef AP_DOODLE_GAME_ABSTRACT_FACTORY_H
#define AP_DOODLE_GAME_ABSTRACT_FACTORY_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "../Score.h"
#include "../Entity_Model/EM_Player.h"
#include "../Entity_Model/EM_Platform_Types/EM_Green_Platform.h"
#include "../Entity_Model/EM_Platform_Types/EM_Blue_Platform.h"
#include "../Entity_Model/EM_Platform_Types/EM_Yellow_Platform.h"
#include "../Entity_Model/EM_Platform_Types/EM_White_Platform.h"
#include "../Entity_Model/EM_BG_Tile.h"
#include "../Entity_Model/EM_Bonus.h"
#include "../Entity_Model/EM_Bonus_Types/EM_Spring.h"
#include "../Entity_Model/EM_Bonus_Types/EM_Jetpack.h"

#include "../Entity_View/EV_Player.h"
#include "../Entity_View/EV_Platform_Types/EV_Green_Platform.h"
#include "../Entity_View/EV_Platform_Types/EV_Blue_Platform.h"
#include "../Entity_View/EV_Platform_Types/EV_Yellow_Platform.h"
#include "../Entity_View/EV_Platform_Types/EV_White_Platform.h"
#include "../Entity_View/EV_Bonus_Types/EV_Spring.h"
#include "../Entity_View/EV_Bonus_Types/EV_Jetpack.h"
#include "../Entity_View/EV_Bonus.h"
#include "../Entity_View/EV_BG_Tile.h"


class Abstract_Factory {

public:

    virtual shared_ptr<EM_Player> createPlayer(float player_width, float player_height, float startposx, float startposy,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_Green_Platform> createGreenPlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_Blue_Platform> createBluePlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_White_Platform> createWhitePlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_Yellow_Platform> createYellowPlatform(float platform_width, float platform_height, float move_height,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_BG_Tile> createBackground(float background_width, float background_height, float startposx, float startposy,shared_ptr<Camera> camera) = 0;
    virtual shared_ptr<EM_Spring> createSpring(float spring_width, float spring_height,shared_ptr<Camera> camera) = 0;

    virtual shared_ptr<EV_Player> get_player(const shared_ptr<EM_Player> player) = 0;
    virtual shared_ptr<EV_Platform> get_platform(const shared_ptr<EM_Platform> platform) = 0;
    virtual shared_ptr<EV_Bonus> get_bonus(const shared_ptr<EM_Bonus> bonus) = 0;
    virtual const vector<shared_ptr<EV_BG_Tile>> &getBackgrounds() const = 0;
    virtual shared_ptr<Score> get_score() =0;

};


#endif //AP_DOODLE_GAME_ABSTRACT_FACTORY_H
