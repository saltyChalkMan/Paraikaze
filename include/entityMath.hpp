# pragma once 
# include <raylib.h>
# include <raymath.h>

namespace enemyMath{
    float genRandFloat(float min, float max);
    Vector2 genRandPoint(Rectangle area);
    Vector2 getOffsetIncr(Vector2 origin, Vector2 target, int incr);
}

class frameCounter{
    private: 
        int frames, fps;
    public:
        frameCounter(int pfps);
        void updateFrameCount();
};