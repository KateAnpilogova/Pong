#include <stdio.h>
#include <stdlib.h>

int width = 80;
int length = 25;

int ballX = 13;
int ballY = 5;
int rocketX = 1;
int rocketY = 14;
int dirX = 1;
int dirY = 1;

void draw_court(int ballX, int ballY, int length, int width) {
    printf("\033[0d\033[2J"); // Очистка экрана
    for (int i = 0; i <= length; i++) {
        for (int j = 0; j <= width; j++) {
            if (i > 0 && i < length && j == 0) {
                printf(" ");
            } else if (i > 0 && i < length && j == width) {
                printf(" ");
                printf("\n");
            } else if ((i == 0 && j > 0 && j < width) || (i == length && j > 0 && j < width)) {
                printf("*");
            } else if (j == 41 && i != 0 && i != length) {
                printf("|");
            } else if (j == 2 && i > (length / 2) - 1 && i <= (length / 2) + 2) {
                printf("|");
            } else if (j == 78 && i > (length / 2) - 1 && i <= (length / 2) + 2) {
                printf("|");
            } else if (i == ballX && j == ballY) {
                printf("o");
            } else {
                printf(" ");
            }
        }
    }
} 

int RocketMovementLeft(char key){
    if (key == 'a' && rocketY > 1) {
        rocketY--; 
    } else if (key == 'z' && rocketY < 22) {
        rocketY++; 
    }
    return rocketY;
}

int RocketMovementRight(char key){
    if (key == 'k' && rocketY > 1) {
        rocketY--; 
    } else if (key == 'm' && rocketY < 22) {
        rocketY++; 
    }
    return rocketY;
}

void move_ball() {
    ballX += dirX;
    ballY += dirY;

    /* столкновение с верхней и нижней границей */
    if (ballY <= 0 || ballY >= (width - 1)) {
        dirY = -dirY;
    }
    /* столкновение с ракеткой */
    if ((ballX == 2 && ballY == rocketY) || (ballX == 78 && ballY == rocketY)) {
        dirX = -dirX;
    }
    /* пролетает мимо ракетки */
    if (ballX <= 0 || ballX >= (length - 1)) {
        printf("Game Over!\n");
        // Завершим игру
        exit(0); 
    }
}

int main() {
    int scorePlayer1 = 0;
    int scorePlayer2 = 0;

    while (1) {
    
            char key = getchar(); // Считываем нажатую клавишу
            if (key == 'a' || key == 'z') {
                RocketMovementLeft(key);
            } else if (key == 'k' || key == 'm') {
                RocketMovementRight(key);
            }
        

        move_ball();
        draw_court(ballX, ballY, length, width);

    if (scorePlayer1 == 21) {
        printf("Player 1 wins!\n");
    } else if (scorePlayer2 == 21) {
        printf("Player 2 wins!\n");
    }

    return 0;
}
}
