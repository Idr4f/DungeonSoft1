#include <string>
#include <random>
#include "Lucky.h"

Lucky::Lucky(){};

bool Lucky::throw_coin() {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::bernoulli_distribution coinFlip(0.5);

    return coinFlip(generator);
};