#include <raylib.h>

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



    bool gameShouldUpdate = true;



    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_ESCAPE)) gameShouldUpdate = !gameShouldUpdate;
        
        if (gameShouldUpdate){

        }

        BeginDrawing();
            ClearBackground(GRAY);

            BeginMode2D(camera);

            EndMode2d();

            if (!gameShouldUpdate) DrawText("Game Stopt", screanWidth / 2.0f, screanHeight / 2.0f, 50, RED);

        EndDrawing();

    }

    return 0;
}
