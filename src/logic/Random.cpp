//
// Created by legod on 15/11/2021.
//

#include "Random.h"

Random::Random(){

}

Random* Random::singleton_= nullptr;

Random *Random::GetInstance() {
    if(singleton_ == nullptr){
        singleton_ = new Random();
    }
    return singleton_;
}

float Random::generate_between(const float &min, const float &max){

    std::uniform_real_distribution<double> distribution(min, max);
    std::random_device rd;
    std::default_random_engine generator(rd());

    return distribution(generator);
}

Random::~Random() {
    std::cout << "destructor of Random" << std::endl;
}

