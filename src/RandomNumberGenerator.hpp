#ifndef __RANDOM_NUMBER_GENERATOR__
#define __RANDOM_NUMBER_GENERATOR__

#include <random>
#include "vec2.hpp"

class RandomNumberGenerator {
public:
    RandomNumberGenerator(int min, int max, unsigned seed = std::random_device{}())
        :  gen(seed), dist(min, max) {}

    int random_number() {
        return dist(gen);
    }

private:
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;
};

#endif // __RANDOM_POSITION_GENERATOR__
