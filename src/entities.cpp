# include <raylib.h>
# include <raymath.h>

# include "entities.hpp"
# include "entityMath.hpp"

// Base class entity

Entity::Entity(const char* filename, int w, int h, int pframes, Vector2 point, frameCounter* pframe)
: width(w), height(h), frames(pframes), currFrame(0), frame(pframe)
{
    Image img = LoadImage("res/Plane.png");
    ImageResize(&img, width * frames, height);
    txt = LoadTextureFromImage(img);
    UnloadImage(img);
    src = {(float)width * currFrame,0.0f,(float)width,(float)height};
    Vector2 offset{-((float)width / 2), -((float)height / 2)};
    topLeft = Vector2Add(point,offset);
    rect = {topLeft.x, topLeft.y, (float)width,(float)height};
}

void Entity::setTopLeft(Vector2 point){
    Vector2 offset{-((float)width / 2), -((float)height / 2)};
    topLeft = Vector2Add(point,offset);
    rect = {topLeft.x, topLeft.y, (float)width,(float)height};
}

void Entity::updateFrame(){
    ++currFrame %= frames;
    src = {(float)width * currFrame,0.0f,(float)width,(float)height};
}

void Entity::update(){
    updateFrame();
    DrawTextureRec(
            txt,
            src,
            topLeft,
            RAYWHITE
        );
}

Rectangle Entity::getRect(){
    return rect;
}

// Enemy- Child class of entity

Enemy::Enemy(const char* filename, int w, int h, int pframes, Vector2 point, frameCounter * pframe, float pGravity, Rectangle launchArea)
: Entity(filename, w, h, pframes, point, pframe),gravity(pGravity), center(point), reachedLaunch(false), reachedKemi(false)
{
    launchPoint = enemyMath::genRandPoint(launchArea);
    kemiPoint = enemyMath::genRandPoint(Rectangle{launchPoint.x - 100,launchPoint.y, 200,150});
}

void Enemy::fall() {
    Vector2 offset = enemyMath::getOffsetIncr(center, launchPoint, gravity);
    center = Vector2Add(center, offset);
    topLeft = Vector2Add(topLeft, offset);
    rect = {topLeft.x, topLeft.y, (float)width,(float)height};
}

void Enemy::update(){
    DrawLineEx(center, launchPoint, 5, RED);
    DrawCircle(launchPoint.x, launchPoint.y, 5, RED);
    DrawCircle(kemiPoint.x, kemiPoint.y, 5, GREEN);
    DrawTextureRec(
            txt,
            src,
            topLeft,
            RAYWHITE
        );
}