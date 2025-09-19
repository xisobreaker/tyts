#include "tyts/random.h"
#include <ctime>

namespace tyts {

Random::Random() : Random(std::time(nullptr))
{
}

Random::Random(uint64_t seed)
{
    engine_.seed(seed);
}

Random::~Random()
{
}

uint64_t Random::random(uint64_t min, uint64_t max)
{
    return (engine_() % (max - min + 1) + min);
}

} // namespace tyts