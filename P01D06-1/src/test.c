#include <stdio.h>

int width = 80;
int length = 25;

int ballX =13;
int ballY = 5;
int rocketX = 1;
int rocketY = 14;
int dirX = 1;
int dirY = 1;

void draw_court(int ballX, int ballY, int length, int width) {
    printf("\033[0d\033[2J");
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

char key;
int RocketMovementLeft(char key){
    if (key=='a'){
        if (rocketY>=1){
                rocketY--; 
        } 
    } else if (key=='z'){
        if (rocketY<22){
                rocketY ++; 
        }
    } 
    return rocketY;
}

int RocketMovementRight(char key){
     if (key=='k'){
    if (rocketY>=1){
            rocketY --; 
        } 
    } else if (key=='m'){
        if (rocketY<22){
                rocketY ++; 
        }
    }
    return rocketY;
}

int move_ball(){
    dirX += dirX;
    dirY += dirY;

    /*столконовение с верхрней границей*/
    if (dirY<=0 || dirY >= (length-1)){
        dirY = -dirY;
    }
    /*столкновение с ракеткой*/
     if ((ballX == 2 && ballY == rocketY) || (ballX == 78 && ballY == rocketY)) {
            dirX = -dirX;
        }
    /*пролетает мимо ракетки*/
     if (ballX <= 0 || ballX >= (width - 1)) {
            printf("Game Over!\n");
        }
return dirX; 

}
int main(){
    int scorePlayer1=0;
    int scorePlayer2=0;
    /*проверка является ли key a или z тогда передаем в функцию RocketMovementLeft*/
    /*проверка является ли key k или m тогда передаем в функцию RocketMovementRight*/
   
    while (1){
    char key = getchar();
    draw_court(ballX, ballY, length, width);
    if (key=='a' || 'z'){
       return RocketMovementLeft(key);
    } else if(key == 'k' || 'm'){
        return RocketMovementRight(key);
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
