cmake_minimum_required(VERSION 3.16)
project(AP_doodle_game)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML COMPONENTS graphics window system)

add_executable(AP_doodle_game
        main.cpp
        Game.cpp
        Game.h
        Stopwatch.cpp
        Stopwatch.h
        Camera.cpp
        Camera.h
        Random.cpp
        Random.h
        World.cpp
        World.h
        Score.cpp
        Score.h
        design_patterns/Observer.cpp
        design_patterns/Observer.h
        design_patterns/Subject.cpp
        design_patterns/Subject.h
        design_patterns/IObserver.cpp
        design_patterns/IObserver.h
        design_patterns/ISubject.cpp
        design_patterns/ISubject.h
        design_patterns/Abstract_Factory.h
        design_patterns/Abstract_Factory.cpp
        design_patterns/Concrete_Factory.h
        design_patterns/Concrete_Factory.cpp

        Entity_Model/EM_BG_Tile.cpp
        Entity_Model/EM_BG_Tile.h
        Entity_Model/EM_Bonus.h
        Entity_Model/EM_Bonus.cpp
        Entity_Model/EM_Player.cpp
        Entity_Model/EM_Player.h
        Entity_Model/EM_Platform.cpp
        Entity_Model/EM_Platform.h
        Entity_Model/Entity_Model.h
        Entity_Model/Entity_Model.cpp
        Entity_Model/EM_Platform_Types/EM_Green_Platform.cpp
        Entity_Model/EM_Platform_Types/EM_Green_Platform.h
        Entity_Model/EM_Platform_Types/EM_Blue_Platform.cpp
        Entity_Model/EM_Platform_Types/EM_Blue_Platform.h
        Entity_Model/EM_Platform_Types/EM_Yellow_Platform.cpp
        Entity_Model/EM_Platform_Types/EM_Yellow_Platform.h
        Entity_Model/EM_Platform_Types/EM_White_Platform.cpp
        Entity_Model/EM_Platform_Types/EM_White_Platform.h
        Entity_Model/EM_Bonus_Types/EM_Jetpack.cpp
        Entity_Model/EM_Bonus_Types/EM_Jetpack.h
        Entity_Model/EM_Bonus_Types/EM_Spring.cpp
        Entity_Model/EM_Bonus_Types/EM_Spring.h

        Entity_View/EV_Player.h
        Entity_View/EV_Player.cpp
        Entity_View/EV_Platform.h
        Entity_View/EV_Platform.cpp
        Entity_View/EV_BG_Tile.cpp
        Entity_View/EV_BG_Tile.h
        Entity_View/EV_Bonus.h
        Entity_View/EV_Bonus.cpp
        Entity_View/Entity_View.h
        Entity_View/Entity_View.cpp
        Entity_View/EV_Platform_Types/EV_Blue_Platform.cpp
        Entity_View/EV_Platform_Types/EV_Blue_Platform.h
        Entity_View/EV_Platform_Types/EV_Green_Platform.cpp
        Entity_View/EV_Platform_Types/EV_Green_Platform.h
        Entity_View/EV_Platform_Types/EV_White_Platform.cpp
        Entity_View/EV_Platform_Types/EV_White_Platform.h
        Entity_View/EV_Platform_Types/EV_Yellow_Platform.cpp
        Entity_View/EV_Platform_Types/EV_Yellow_Platform.h
        Entity_View/EV_Bonus_Types/EV_Jetpack.cpp
        Entity_View/EV_Bonus_Types/EV_Jetpack.h
        Entity_View/EV_Bonus_Types/EV_Spring.cpp
        Entity_View/EV_Bonus_Types/EV_Spring.h)

target_link_libraries(AP_doodle_game sfml-graphics sfml-window sfml-system)