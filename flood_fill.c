#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30


void flood_fill(unsigned char figure[ROWS][COLS], char x, char y, const char originalColor, const char replacementColor);
void flood_fill_stack();
void flood_fill_queue();

int main()
{
    unsigned char figure[ROWS][COLS] = {
        {0, 0, 0, 0, 0}, 
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    flood_fill(figure, 1, 1, 1, 3);
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) printf("%d", figure[i][j]);
        printf("\n");
    }

    return 0;
}

void flood_fill(unsigned char figure[ROWS][COLS], char x, char y, const char originalColor, const char replacementColor) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) return;
    if (originalColor == replacementColor || figure[x][y] != originalColor) return;

    figure[x][y] = replacementColor;

    flood_fill(figure, x, (y - 1), originalColor, replacementColor);
    flood_fill(figure, x, (y + 1), originalColor, replacementColor);
    flood_fill(figure, (x - 1), y, originalColor, replacementColor);
    flood_fill(figure, (x + 1), y, originalColor, replacementColor);
}

void flood_fill_stack() {}
void flood_fill_queue() {}