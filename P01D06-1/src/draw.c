#include <stdio.h>

#define WIDTH 82
#define LENGTH 27
#define ballX (WIDTH - 2)   // Позиция мяча (зададим -2, чтобы он точно вписывался)
#define ballY (LENGTH / 2)  // Позиция мяча по вертикали

void draw_court() {
    for (int i = 0; i <= LENGTH; i++) {
        for (int j = 0; j <= WIDTH; j++) {
            // Рисование границ корта
            if (i == 0 || i == LENGTH) {
                if (j > 0 && j < WIDTH) {
                    printf("#"); // верхняя и нижняя границы
                } else {
                    printf(" ");
                }
            } else if (j == 0) {
                printf("("); // левая граница
            } else if (j == WIDTH) {
                printf(")"); // правая граница
            } else if (j == 41) {
                printf("|"); // центральная линия
            } else {
                // Рисование ракеток
                if (j == 1 && i >= (LENGTH / 2) - 1 && i <= (LENGTH / 2) + 1) {
                    printf("|"); // левая ракетка
                } else if (j == 80 && i >= (LENGTH / 2) - 1 && i <= (LENGTH / 2) + 1) {
                    printf("|"); // правая ракетка
                } 
                // Рисование мяча
                else if (j == ballX && i == ballY) {
                    printf("0"); // мяч
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n"); // переход на новую строку после завершения строки
    }
}

int main() {
    draw_court();
    return 0;
}