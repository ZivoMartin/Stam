#ifndef __RANDOM_POSITION_GENERATOR__
#define __RANDOM_POSITION_GENERATOR__

#include <random>
#include "../util/vec2.hpp"

class RandomPositionGenerator {
public:
    RandomPositionGenerator(vec2i d, unsigned seed = std::random_device{}())
        :  gen(seed), dist_x(0, d.x - 1), dist_y(0, d.y - 1) {}
    RandomPositionGenerator() = default;
    
    vec2f random_position() {
        return vec2f(dist_x(gen), dist_y(gen));
    }

private:
    std::mt19937 gen;
    std::uniform_int_distribution<> dist_x;
    std::uniform_int_distribution<> dist_y;
};

#endif // __RANDOM_POSITION_GENERATOR__
