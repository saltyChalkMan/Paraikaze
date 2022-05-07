# include <raylib.h>
# include <raymath.h>
# include <iostream>

# include "entities.hpp"
# include "entityMath.hpp"

const int WIDTH = 600, HEIGHT = 600;

int main(void){

    InitWindow(WIDTH,HEIGHT,"KamiChute");
    SetTargetFPS(60);
    frameCounter frames(60);

    Entity plane = Entity("res/Plane.png", 70, 70, 9, GetMousePosition(), &frames);
    Enemy diver = Enemy("res/Plane.png", 55,55,9,Vector2{400,50},&frames, 5, Rectangle{0, 150,WIDTH,HEIGHT / 2});

    while(!WindowShouldClose()){


        frames.updateFrameCount();
        plane.setTopLeft(GetMousePosition());
        diver.fall();
        if (CheckCollisionRecs(plane.getRect(), diver.getRect())){
            std::cout << "Collision detect!\n";
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

            diver.update();
            plane.update();

        EndDrawing();
    }

    CloseWindow();

}
