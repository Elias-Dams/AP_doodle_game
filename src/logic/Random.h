/*
 * Deze klasse wordt gebruikt om alle willekeurige getallen te genereren die je in het spel nodig hebt. Je wereld
 * generatie moet gebruik maken van deze willekeurige getallen om ervoor te zorgen dat de platforms niet altijd op
 * dezelfde posities liggen, en om een compleet andere wereld te genereren elke keer dat je spel wordt uitgevoerd.
 */

#ifndef AP_DOODLE_GAME_RANDOM_H
#define AP_DOODLE_GAME_RANDOM_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <random>

// i used https://refactoring.guru/design-patterns/singleton/cpp/example as inspiration for the singleton design pattern

using namespace std;

class Random {

private:
    Random();

    static Random* singleton_;


public:

    //Singletons should not be cloneable.
    Random(Random &other) = delete;

    //Singletons should not be assignable.
    void operator=(const Random &) = delete;

    static Random *GetInstance();

    float generate_between(const float &min, const float &max);

    virtual ~Random();

};


#endif //AP_DOODLE_GAME_RANDOM_H
