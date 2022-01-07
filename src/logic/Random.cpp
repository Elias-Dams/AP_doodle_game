
#include "Random.h"

Random::Random() {
}

shared_ptr<Random> Random::singleton_ = nullptr;

shared_ptr<Random> Random::GetInstance() {
    if (singleton_ == nullptr) {
        singleton_ = make_shared<Random>();
    }
    return singleton_;
}

float Random::generate_between(const float min, const float max) {
    std::uniform_real_distribution<double> distribution(min, max);
    std::random_device rd;
    std::default_random_engine generator(rd());

    return distribution(generator);
}

float Random::generate_between_exeption(const float min, const float max, const float exeptionmin,  const float exeptionmax){
    std::uniform_int_distribution<int> distribution(1,2);
    std::random_device rd;
    std::default_random_engine generator(rd());
    if(exeptionmin < 0 ){
        return this->generate_between(exeptionmax, max);
    }
    else if(exeptionmax > max ){
        return this->generate_between(0, exeptionmin);
    }
    else{
        switch (distribution(generator)) {
            case(1):
                return this->generate_between(min, exeptionmin);
            case(2):
                return this->generate_between(exeptionmax, max);
        }
    }
}

Random::~Random() {

}
