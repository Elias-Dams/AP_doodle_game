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

        src/logic/Entity_Model/M_BG_Tile.cpp
        src/logic/Entity_Model/M_BG_Tile.h
        src/logic/Entity_Model/M_Bonus.h
        src/logic/Entity_Model/M_Bonus.cpp
        src/logic/Entity_Model/M_Player.cpp
        src/logic/Entity_Model/M_Player.h
        src/logic/Entity_Model/M_Platform.cpp
        src/logic/Entity_Model/M_Platform.h
        src/logic/Entity_Model/Entity_Model.h
        src/logic/Entity_Model/Entity_Model.cpp
        src/logic/Entity_Model/M_Platform_Types/M_Green_Platform.cpp
        src/logic/Entity_Model/M_Platform_Types/M_Green_Platform.h
        src/logic/Entity_Model/M_Platform_Types/M_Blue_Platform.cpp
        src/logic/Entity_Model/M_Platform_Types/M_Blue_Platform.h
        src/logic/Entity_Model/M_Platform_Types/M_Yellow_Platform.cpp
        src/logic/Entity_Model/M_Platform_Types/M_Yellow_Platform.h
        src/logic/Entity_Model/M_Platform_Types/M_White_Platform.cpp
        src/logic/Entity_Model/M_Platform_Types/M_White_Platform.h
        src/logic/Entity_Model/M_Bonus_Types/M_Jetpack.cpp
        src/logic/Entity_Model/M_Bonus_Types/M_Jetpack.h
        src/logic/Entity_Model/M_Bonus_Types/M_Spring.cpp
        src/logic/Entity_Model/M_Bonus_Types/M_Spring.h

        src/logic/Namespaces.cpp
        )

set( REPRESENTATION

        main.cpp
        src/representation/Game.cpp
        src/representation/Game.h

        src/representation/design_patterns/Concrete_Factory.h
        src/representation/design_patterns/Concrete_Factory.cpp

        src/representation/Entity_View/V_Player.h
        src/representation/Entity_View/V_Player.cpp
        src/representation/Entity_View/V_Platform.h
        src/representation/Entity_View/V_Platform.cpp
        src/representation/Entity_View/V_BG_Tile.cpp
        src/representation/Entity_View/V_BG_Tile.h
        src/representation/Entity_View/V_Bonus.h
        src/representation/Entity_View/V_Bonus.cpp
        src/representation/Entity_View/Entity_View.h
        src/representation/Entity_View/Entity_View.cpp
        src/representation/Entity_View/V_Platform_Types/V_Blue_Platform.cpp
        src/representation/Entity_View/V_Platform_Types/V_Blue_Platform.h
        src/representation/Entity_View/V_Platform_Types/V_Green_Platform.cpp
        src/representation/Entity_View/V_Platform_Types/V_Green_Platform.h
        src/representation/Entity_View/V_Platform_Types/V_White_Platform.cpp
        src/representation/Entity_View/V_Platform_Types/V_White_Platform.h
        src/representation/Entity_View/V_Platform_Types/V_Yellow_Platform.cpp
        src/representation/Entity_View/V_Platform_Types/V_Yellow_Platform.h
        src/representation/Entity_View/V_Bonus_Types/V_Jetpack.cpp
        src/representation/Entity_View/V_Bonus_Types/V_Jetpack.h
        src/representation/Entity_View/V_Bonus_Types/V_Spring.cpp
        src/representation/Entity_View/V_Bonus_Types/V_Spring.h
        )

add_executable(AP_doodle_game ${REPRESENTATION})

include_directories(src/logic)

add_library(logic ${LOGIC})

target_link_libraries(AP_doodle_game logic sfml-graphics sfml-window sfml-system)