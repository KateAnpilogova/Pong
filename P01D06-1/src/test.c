#include<stdio.h>

#define WIDTH_SCREEN 82;
#define LENGTH_SCREEN 22;
 


char key;
int RocketMovementLeft(char key){
    if (key=='a'){
        if (position>=1){
            position --; 
        } 
    } else if (key=='z'){
        if (position<22){
            position ++; 
        }
    }
    
}

int RocketMovementRight(char key){
     if (key=='k'){
    if (position>=1){
            position --; 
        } 
    } else if (key=='m'){
        if (position<22){
                position ++; 
        }
    }

void rocket(){
    int Y.startPosition=LENGTH_SCREEN/2
    int X.startPosiiton=0
    /*нарисовать ракетку и передавать в нее изменение координат
    есть исходная позиция и цикл где перезаписывается позиция пока идет игра 
    на основе функций изменения позиции*/
    for (int i = (LENGTH_SCREEN/2)-1; i<= (LENGTH_SCREEN/2)+3, i++) {
        printf
            
        }
    }
    /*while все выполняется */

}

int main(){
    key = getchar();
    
    /*проверка является ли key a или z тогда передаем в функцию RocketMovementLeft*/
    /*проверка является ли key k или m тогда передаем в функцию RocketMovementRight*/
    
}