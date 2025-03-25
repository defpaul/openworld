#include <raylib.h>
#include "config.h"
#include <stdio.h>

int main(void){

    const int screanWidth = 1400;
    const int screanHeight = 800;

    InitWindow(screanWidth, screanHeight, "open World");


    Camera2D camera = {0};
    camera.target = (Vector2) {0.0f, 0.0f};
    camera.offset = (Vector2) {screanWidth / 2.0f, screanHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(30);
    SetExitKey(KEY_NULL);

    Vector2 mousePoint = {0.0f, 0.0f};


    

    int LevelTextureLen = 2;
    Texture2D LevelTexture[] = {
        LoadTexture("assets/water.png"), 
        LoadTexture("assets/grass.png"),
        LoadTexture("assets/wall.png")
    };


    int len = 9;
    int Level[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,0,0,0},
    {0,0,0,1,1,1,1,1,0,0},
    {0,0,0,2,2,2,2,1,0,0},
    {0,0,0,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
    };


    /*-------------------------------------------

    Image test_image = LoadImage("assets/wall.png");
    Texture2D TestImage = LoadTextureFromImage(test_image);

    Rectangle sorceRec = {0.0f, 0.0f, (float)TestImage.width, (float)TestImage.height};
    Rectangle destRec = {0.0f, 0.0f, TestImage.width * 4.0f, TestImage.height * 4.0f};
    Vector2 origin = {(float)TestImage.width, (float)TestImage.height};

    float rotation = 0.0f;

    */


    bool gameShouldUpdate = true;

    Rectangle continueButton = {screanWidth / 2, (screanHeight / 2) + 50, 40, 200};


    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_ESCAPE)) gameShouldUpdate = !gameShouldUpdate;
        mousePoint = GetMousePosition();
        
        if (gameShouldUpdate){

        }
        else 
        {
            if (CheckCollisionPointRec(mousePoint, continueButton) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) gameShouldUpdate = true;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);


            BeginMode2D(camera);

                //DrawTexturePro(TestImage, sorceRec, destRec, origin, rotation, WHITE);
                DrawLevel(LevelTexture, Level, len);
                

            EndMode2D();


            if (!gameShouldUpdate) 
            {
                DrawText("Game Stopt", screanWidth / 2.0f, (screanHeight / 2.0f) - 20, 50, RED);
                DrawRectangle(continueButton.x, continueButton.y, continueButton.height, continueButton.width, GRAY);
                DrawText("Continiu", continueButton.x +40, continueButton.y +10, 20, RED);
            }

        EndDrawing();

    }

    for (int i=0; i<=LevelTextureLen; i++) {
        UnloadTexture(LevelTexture[i]);
    }



    CloseWindow();

    return 0;
}
