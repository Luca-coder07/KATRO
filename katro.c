/*
    Case on board: 128
    board: 5 x 4 (640 x 512)
    center: (screensize / 2) - (imagesize / 2)
*/

#include "katro.h"

void    draw_all_dots(int tab1[2][5], int tab2[2][5])
{
    int row;
    int column;
    char nbr1[2];
    char nbr2[2];

    row = 0;
    while (row < 2)
    {
        column = 0;
        while (column < 5)
        {
            sprintf(nbr1, "%d", tab1[row][column]);
            sprintf(nbr2, "%d", tab2[row][column]);
            DrawText(nbr1, (column * 128) + 129, (row * 128) + 93, 30, (Color) {200, 200, 200, 255});
            DrawText(nbr2, (column * 128) + 129, ((row + 2) * 128) + 93, 30, (Color) {200, 200, 200, 255});
            column++;
        }
        row++;
    }
}

void	draw_all_lines(int screenWidth, int screenHeight)
{
	DrawLine((screenWidth / 2) - 320, (screenHeight / 2) - 128, (screenWidth / 2) + 320, (screenHeight / 2) - 128, (Color) {0, 0, 0, 255});
	DrawLine((screenWidth / 2) - 320, (screenHeight / 2),       (screenWidth / 2) + 320, (screenHeight / 2),       (Color) {0, 0, 0, 255});
	DrawLine((screenWidth / 2) - 320, (screenHeight / 2) + 128, (screenWidth / 2) + 320, (screenHeight / 2) + 128, (Color) {0, 0, 0, 255});
	DrawLine((screenWidth / 2) - 192, (screenHeight / 2) - 256, (screenWidth / 2) - 192, (screenHeight / 2) + 256, (Color) {0, 0, 0, 255});
	DrawLine((screenWidth / 2) - 64,  (screenHeight / 2) - 256, (screenWidth / 2) - 64,  (screenHeight / 2) + 256, (Color) {0, 0, 0, 255});
	DrawLine((screenWidth / 2) + 64,  (screenHeight / 2) - 256, (screenWidth / 2) + 64,  (screenHeight / 2) + 256, (Color) {0, 0, 0, 255});
	DrawLine((screenWidth / 2) + 192, (screenHeight / 2) - 256, (screenWidth / 2) + 192, (screenHeight / 2) + 256, (Color) {0, 0, 0, 255});
}

void    display_window(int tab1[2][5], int tab2[2][5])
{
    const int   screenWidth = 800;
    const int   screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Katro Ado");
	Texture2D   board = LoadTexture("assets/plateau.jpg");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground((Color) {20, 20, 20, 255});
		DrawTexture(board, (screenWidth / 2) - 320, (screenHeight / 2) - 256, WHITE);
		draw_all_lines(screenWidth, screenHeight);
        draw_all_dots(tab1, tab2);
		EndDrawing();
    }
    CloseWindow();
}

int main(void)
{
    int tab_j1[2][5] = {{3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}};
    int tab_j2[2][5] = {{3, 3, 3, 3, 3}, {3, 3, 3, 3, 3}};

    display_window(tab_j1, tab_j2);
    return (0);
}