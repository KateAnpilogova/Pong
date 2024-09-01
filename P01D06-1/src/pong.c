#include<stdio.h>

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

void move_rocket() {}

void move_ball() {}

void gameplay() {
    draw_court();
}





int main() {
    gameplay();
    
    return 0;
}
