#include <stdio.h>

int width = 80;
int length = 25;

int ballX =13;
int ballY = 5;

void draw_court() {
    for (int i = 0; i <= length; i++) {
        for (int j = 0; j <= width; j++) {
            if (i > 0 && i < length && j == 0)
                printf(" ");
            else if (i > 0 && i < length && j == width) {
                printf(" ");
                printf("\n");
            }
            else if (((i == 0) && (j > 0) && (j < width)) || ((i == length) && (j > 0) && (j < width)))
                printf("*");
            else if (j == 41 && i != 0 && i != length)
                printf("|");
            else if ((j == 2 && i > (length / 2) - 1 && i <= (length / 2) + 2)){
                printf("|");
            }
            else if ((j == 78 && i > (length / 2) - 1 && i <= (length / 2) + 2)){
                printf("|");
            }
            else if (i==ballX && j==ballY){
                printf("o");
            }

                // Рисуем ракетку
                 else {
                    printf(" ");
                }
            }
        }
} 

int main() {
    draw_court();
    return 0;
}