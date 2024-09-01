#include<stdio.h>

int WIDTH = 82, LENGTH = 27;
int ballX, ballY; /*координаты шарика, задаем начальное, дальше задаем рандомное перемещение по 1*/
int dirX = 1, dirY = 1; /*направление движения шарика*/
int rocketX, rocketY; /*координаты ракетки, где х всегда равен 1!*/

void draw_court() {
    int WIDTH = 82, LENGTH = 27;
    for (int i = 0; i <= LENGTH; i++){
        for (int j = 0; j <= WIDTH; j++) {
            if (i > 0 && i < LENGTH && j == 0)
                printf("(");
            else if (i > 0 && i < LENGTH && j == WIDTH) {
                printf(")");
                printf("\n");
            }
            else if (((i == 0) && (j > 0) && (j < WIDTH)) || ((i == LENGTH) && (j > 0) && (j < WIDTH )))
                printf("#");
            else if (j == 41 && i != 0 && i != LENGTH)
                printf("|");
            else {
                printf(" ");
                if (j == WIDTH && i == 0)
                    printf("\n");
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
void draw_rocket(){
    /*нарисовать ракетку и передавать в нее изменение координат
    есть исходная позиция и цикл где перезаписывается позиция пока идет игра 
    на основе функций изменения позиции*/
    for (int y=0; y<LENGTH; y++){
        for (int x=0; x<WIDTH; x++){
            if (x==1 && y>=(LENGTH/2)-1 && y<=(LENGTH/2)+2){
                printf("| /n");
            }
    }
    }
    

}

void draw_ball(){
    for (int y=0; y<LENGTH; y++){
        for (int x=0; x<WIDTH; x++){
            if (x==ballX && y==ballY){
                printf("0 /n");
            }
        }
    }
}

int move_ball(){
    dirX += dirX;
    dirY += dirY;

    /*столконовение с верхрней границей*/
    if (dirY<=0 || dirY >= (LENGTH-1)){
        dirY = -dirY;
    }
    /*столкновение с ракеткой*/
    /*пролетает мимо ракетки*/
return dirX; 

}
int main(){
    int scorePlayer1=0;
    int scorePlayer2=0;
    ballX = WIDTH-1;
    ballY = LENGTH/2;
    rocketX = 1;
    rocketY = LENGTH/2;
    /*проверка является ли key a или z тогда передаем в функцию RocketMovementLeft*/
    /*проверка является ли key k или m тогда передаем в функцию RocketMovementRight*/
    key = getchar();
    if (key=='a' || 'z'){
       return RocketMovementLeft(key);
    } else if(key == 'k' || 'm'){
        return RocketMovementRight(key);
    }
    /*пока счет одного из игроков е станет 21*/

    while (scorePlayer1<=21 || scorePlayer2<=21){
        if (scorePlayer1==21){
            printf("Player 1 win!");
            break;
        } else if (scorePlayer2==21){
            printf("Player 2 win!");
            break;
        }
    }

}