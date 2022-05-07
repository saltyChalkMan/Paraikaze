#pragma once
#include <raylib.h>

# include "entityMath.hpp"

class Entity{
    public:
        Entity(const char* filename, int w, int h, int pframes, Vector2 point, frameCounter* pframe);
        void setTopLeft(Vector2 point);
        void updateFrame();
        Rectangle getRect();
        void update();
    protected:
        int width, height, frames, currFrame;
        frameCounter * frame;
        Texture2D txt;
        Rectangle src, rect;
        Vector2 topLeft;
};

class Enemy: public Entity{
private:
    float gravity;
    Vector2 center, launchPoint, kemiPoint;
    bool reachedLaunch, reachedKemi;
public:
    Enemy(const char* filename, int w, int h, int pframes, Vector2 point,frameCounter* pframe, float pGravity, Rectangle launchArea);
    void fall();
    void update();
};
