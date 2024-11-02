#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack/Stack.h"


#define ROWS 20
#define COLS 30

void flood_fill(unsigned char figure[ROWS][COLS], char x, char y, const char originalColor, const char replacementColor);
void flood_fill_stack(unsigned char figure[ROWS][COLS], char x, char y, const char originalColor, const char replacementColor);
void flood_fill_queue();
void menu(unsigned char figure[ROWS][COLS]);
void display();
void delay();

int main()
{
    unsigned char figure[ROWS][COLS] = {
        {1, 1, 1, 1, 1}, 
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0}
    };

    menu(figure);

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) printf("%d", figure[i][j]);
        printf("\n");
    }
    

    return 0;
}


void menu(unsigned char figure[ROWS][COLS]) {
    unsigned char newColor, x, y, option;

   printf("[!] ====== IMAGE ====== [!]\n\n"); 
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) printf("%d", figure[i][j]);
        printf("\n");
    }

    printf("[!] ====== IMAGE ====== [!]\n\n"); 

    printf("[!] NEW COLOR: ");
    scanf("%d", &newColor);
    printf("[!] PIXEL (X Y): ");
    scanf("%d %d", &x, &y);

    printf("SELECT THE FUNCTION\n[1] RECURSIVE\n[2] STACK\n[3] QUEUE\n-> ");
    scanf("%d", &option);
    printf("\n\n\n");
    
    switch (option) {
    case 1:
        flood_fill(figure, x, y, figure[x][y], newColor);
        break;
    case 2:
        flood_fill_stack(figure, x, y, figure[x][y], newColor);
        break;
    default:
        break;
    }
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

void flood_fill_stack(unsigned char figure[ROWS][COLS], char x, char y, const char originalColor, const char replacementColor) {
    if (figure[x][y] == replacementColor) return;

    Stack pixelStack = stack_create();
    stack_push(pixelStack, x);
    stack_push(pixelStack, y);

    while (stack_size(pixelStack) >= 0) {
        char newY = stack_pop(pixelStack);
        char newX = stack_pop(pixelStack);

        if (figure[newX][newY] == originalColor) {
            figure[newX][newY] = replacementColor;

            if (newX + 1 < ROWS) {
                stack_push(pixelStack, newX + 1);
                stack_push(pixelStack, newY);
            }

            if (newX - 1 >= 0) {
                stack_push(pixelStack, newX - 1);
                stack_push(pixelStack, newY);
            }

            if (newY + 1 < COLS) {
                stack_push(pixelStack, newX);
                stack_push(pixelStack, newY + 1);
            }

            if (newY - 1 >= 0) {
                stack_push(pixelStack, newX);
                stack_push(pixelStack, newY - 1);
            }
        }
    }
}

void flood_fill_queue() {}