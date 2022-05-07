# include <raylib.h>
# include <raymath.h>
# include <random>
# include <chrono>
# include <math.h>
# include <iostream>

# include "entityMath.hpp"

float enemyMath::genRandFloat(float min, float max){
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_real_distribution<float> distr(min,max);
    return distr(gen);
}

Vector2 enemyMath::genRandPoint(Rectangle area){
    float xOffset = enemyMath::genRandFloat(0, area.width),
    yOffset = enemyMath::genRandFloat(0, area.height);
    Vector2 offset{xOffset,yOffset},
    origin{area.x,area.y};
    return Vector2Add(origin,offset);
}

Vector2 enemyMath::getOffsetIncr(Vector2 origin, Vector2 target, int incr){
    Vector2 displ = Vector2Subtract(target, origin);
    float angle = atan2(displ.y,displ.x),
    xDiff = cos(angle) * incr,
    yDiff = sin(angle) * incr;
    return Vector2{xDiff,yDiff};
}

frameCounter::frameCounter(int pfps)
:frames(0), fps(pfps)
{
}

void frameCounter::updateFrameCount(){
    ++frames %= fps;
}