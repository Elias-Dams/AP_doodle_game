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

        src/logic/Entity_Model/BG_Tile.cpp
        src/logic/Entity_Model/BG_Tile.h
        src/logic/Entity_Model/Bonus.h
        src/logic/Entity_Model/Bonus.cpp
        src/logic/Entity_Model/Player.cpp
        src/logic/Entity_Model/Player.h
        src/logic/Entity_Model/Platform.cpp
        src/logic/Entity_Model/Platform.h
        src/logic/Entity_Model/Entity_Model.h
        src/logic/Entity_Model/Entity_Model.cpp
        src/logic/Entity_Model/EM_Platform_Types/Green_Platform.cpp
        src/logic/Entity_Model/EM_Platform_Types/Green_Platform.h
        src/logic/Entity_Model/EM_Platform_Types/Blue_Platform.cpp
        src/logic/Entity_Model/EM_Platform_Types/Blue_Platform.h
        src/logic/Entity_Model/EM_Platform_Types/Yellow_Platform.cpp
        src/logic/Entity_Model/EM_Platform_Types/Yellow_Platform.h
        src/logic/Entity_Model/EM_Platform_Types/White_Platform.cpp
        src/logic/Entity_Model/EM_Platform_Types/White_Platform.h
        src/logic/Entity_Model/EM_Bonus_Types/Jetpack.cpp
        src/logic/Entity_Model/EM_Bonus_Types/Jetpack.h
        src/logic/Entity_Model/EM_Bonus_Types/Spring.cpp
        src/logic/Entity_Model/EM_Bonus_Types/Spring.h

        src/logic/Namespaces.cpp
        )

set( REPRESENTATION

        main.cpp
        src/representation/Game.cpp
        src/representation/Game.h

        src/representation/design_patterns/Concrete_Factory.h
        src/representation/design_patterns/Concrete_Factory.cpp

        src/representation/Entity_View/Player.h
        src/representation/Entity_View/Player.cpp
        src/representation/Entity_View/Platform.h
        src/representation/Entity_View/Platform.cpp
        src/representation/Entity_View/BG_Tile.cpp
        src/representation/Entity_View/BG_Tile.h
        src/representation/Entity_View/Bonus.h
        src/representation/Entity_View/Bonus.cpp
        src/representation/Entity_View/Entity_View.h
        src/representation/Entity_View/Entity_View.cpp
        src/representation/Entity_View/EV_Platform_Types/Blue_Platform.cpp
        src/representation/Entity_View/EV_Platform_Types/Blue_Platform.h
        src/representation/Entity_View/EV_Platform_Types/Green_Platform.cpp
        src/representation/Entity_View/EV_Platform_Types/Green_Platform.h
        src/representation/Entity_View/EV_Platform_Types/White_Platform.cpp
        src/representation/Entity_View/EV_Platform_Types/White_Platform.h
        src/representation/Entity_View/EV_Platform_Types/Yellow_Platform.cpp
        src/representation/Entity_View/EV_Platform_Types/Yellow_Platform.h
        src/representation/Entity_View/EV_Bonus_Types/Jetpack.cpp
        src/representation/Entity_View/EV_Bonus_Types/Jetpack.h
        src/representation/Entity_View/EV_Bonus_Types/Spring.cpp
        src/representation/Entity_View/EV_Bonus_Types/Spring.h
        )

add_executable(AP_doodle_game ${REPRESENTATION})

include_directories(src/logic)

add_library(logic ${LOGIC})

target_link_libraries(AP_doodle_game logic sfml-graphics sfml-window sfml-system)