/*
 * Deze klasse bewaart het verschil in tijd tussen de huidige update stap (tick) en de vorige.
 * Dit wordt gebruikt om ervoor te zorgen dat de logica van het spel op dezelfde snelheid draait, ongeacht de snelheid
 * van het apparaat waarop het draait. Het is niet toegestaan om "busy waiting" te gebruiken om apparaten te vertragen
 * die te snel draaien, de framerate moet dynamisch zijn. De enige uitzondering hierop is dat je de framerate kunt
 * beperken op een bepaalde maximale waarde (bijvoorbeeld 60 FPS), om overeen te komen met de maximale
 * verversingsfrequentie van je beeldscherm. Om deze klasse te implementeren moet u gebruik maken van C++
 * functionaliteit, niet van de SFML Klok klasse.
 */

#ifndef AP_DOODLE_GAME_STOPWATCH_H
#define AP_DOODLE_GAME_STOPWATCH_H

#include <iostream>
#include <list>
#include <string>
#include <chrono>
#include <memory>

using namespace std;

// i used https://refactoring.guru/design-patterns/singleton/cpp/example as inspiration for the singleton design pattern

class Stopwatch {

private:

    static shared_ptr<Stopwatch> singleton_;

    std::chrono::steady_clock::time_point now;


public:

    //Singletons should not be cloneable.
    Stopwatch(Stopwatch &other) = delete;

    //Singletons should not be assignable.
    void operator=(const Stopwatch &) = delete;

    static shared_ptr<Stopwatch> GetInstance();

    float mark_time();


    Stopwatch();

    virtual ~Stopwatch();
};



#endif //AP_DOODLE_GAME_STOPWATCH_H
