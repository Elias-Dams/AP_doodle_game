cmake_minimum_required(VERSION 3.16)
project(AP_doodle_game)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML COMPONENTS graphics window system)



set(LOGIC
        src/logic/Stopwatch.cpp
        src/logic/Stopwatch.h
        src/logic/Camera.cpp
        src/logic/Camera.h
        src/logic/Random.cpp
        src/logic/Random.h
        src/logic/World.cpp
        src/logic/World.h
        src/logic/Score.cpp
        src/logic/Score.h
        src/logic/design_patterns/Observer.cpp
        src/logic/design_patterns/Observer.h
        src/logic/design_patterns/Subject.cpp
        src/logic/design_patterns/Subject.h
        src/logic/design_patterns/IObserver.cpp
        src/logic/design_patterns/IObserver.h
        src/logic/design_patterns/ISubject.cpp
        src/logic/design_patterns/ISubject.h
        src/logic/design_patterns/Abstract_Factory.h
        src/logic/design_patterns/Abstract_Factory.cpp

        src/logic/Entity_Model/EM_BG_Tile.cpp
        src/logic/Entity_Model/EM_BG_Tile.h
        src/logic/Entity_Model/EM_Bonus.h
        src/logic/Entity_Model/EM_Bonus.cpp
        src/logic/Entity_Model/EM_Player.cpp
        src/logic/Entity_Model/EM_Player.h
        src/logic/Entity_Model/EM_Platform.cpp
        src/logic/Entity_Model/EM_Platform.h
        src/logic/Entity_Model/Entity_Model.h
        src/logic/Entity_Model/Entity_Model.cpp
        src/logic/Entity_Model/EM_Platform_Types/EM_Green_Platform.cpp
        src/logic/Entity_Model/EM_Platform_Types/EM_Green_Platform.h
        src/logic/Entity_Model/EM_Platform_Types/EM_Blue_Platform.cpp
        src/logic/Entity_Model/EM_Platform_Types/EM_Blue_Platform.h
        src/logic/Entity_Model/EM_Platform_Types/EM_Yellow_Platform.cpp
        src/logic/Entity_Model/EM_Platform_Types/EM_Yellow_Platform.h
        src/logic/Entity_Model/EM_Platform_Types/EM_White_Platform.cpp
        src/logic/Entity_Model/EM_Platform_Types/EM_White_Platform.h
        src/logic/Entity_Model/EM_Bonus_Types/EM_Jetpack.cpp
        src/logic/Entity_Model/EM_Bonus_Types/EM_Jetpack.h
        src/logic/Entity_Model/EM_Bonus_Types/EM_Spring.cpp
        src/logic/Entity_Model/EM_Bonus_Types/EM_Spring.h

        )

set( REPRESENTATION

        main.cpp
        src/representation/Game.cpp
        src/representation/Game.h

        src/representation/design_patterns/Concrete_Factory.h
        src/representation/design_patterns/Concrete_Factory.cpp

        src/representation/Entity_View/EV_Player.h
        src/representation/Entity_View/EV_Player.cpp
        src/representation/Entity_View/EV_Platform.h
        src/representation/Entity_View/EV_Platform.cpp
        src/representation/Entity_View/EV_BG_Tile.cpp
        src/representation/Entity_View/EV_BG_Tile.h
        src/representation/Entity_View/EV_Bonus.h
        src/representation/Entity_View/EV_Bonus.cpp
        src/representation/Entity_View/Entity_View.h
        src/representation/Entity_View/Entity_View.cpp
        src/representation/Entity_View/EV_Platform_Types/EV_Blue_Platform.cpp
        src/representation/Entity_View/EV_Platform_Types/EV_Blue_Platform.h
        src/representation/Entity_View/EV_Platform_Types/EV_Green_Platform.cpp
        src/representation/Entity_View/EV_Platform_Types/EV_Green_Platform.h
        src/representation/Entity_View/EV_Platform_Types/EV_White_Platform.cpp
        src/representation/Entity_View/EV_Platform_Types/EV_White_Platform.h
        src/representation/Entity_View/EV_Platform_Types/EV_Yellow_Platform.cpp
        src/representation/Entity_View/EV_Platform_Types/EV_Yellow_Platform.h
        src/representation/Entity_View/EV_Bonus_Types/EV_Jetpack.cpp
        src/representation/Entity_View/EV_Bonus_Types/EV_Jetpack.h
        src/representation/Entity_View/EV_Bonus_Types/EV_Spring.cpp
        src/representation/Entity_View/EV_Bonus_Types/EV_Spring.h)

add_executable(AP_doodle_game ${REPRESENTATION})

include_directories(src/logic)

add_library(logic ${LOGIC})

target_link_libraries(AP_doodle_game logic sfml-graphics sfml-window sfml-system)