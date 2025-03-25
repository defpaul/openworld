#include<raylib.h>
#include"config.h"

void DrawLevel(Texture2D textures[], int level[10][10], int len)
{

    for (int y = len; y>=0; y--) {
        for (int x = 0; x<=len; x++){

            int posx = 40 * x;
            int posy = 40 * y;

            Texture2D image = textures[level[y][x]];

            Rectangle sorceRec = { 0.0f, 0.0f, (float)image.width, (float)image.height};
            Rectangle destRec = {(float)posx, (float)posy, image.width * 4.0f, image.height * 4.0f};
            Vector2 origin = {(float)image.width, (float)image.height};

            float rotation = 0.0f;


            DrawTexturePro(image, sorceRec, destRec, origin, rotation, WHITE);

        }
    }

}
