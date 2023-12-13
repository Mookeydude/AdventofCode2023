#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RED "red"
#define BLUE "blue"
#define GREEN "green"
#define GAME "ame"

int STOD(char* number){
int sum = 0;

for(int i = strlen(number); i>0; i--){
//printf("%d\n", number[strlen(number)])
sum = sum +((number[strlen(number)-i]-48) * (pow(10, i-1)));
}
return sum;
}

int ColorFind(char* Line, char* color, int marble){
    char *number = malloc(16);
    char * sentence = malloc (1024);
    int biggest_number = 0;
    strcpy(sentence, Line);
    //int sum = 0;
    //int num = 0
    if(strstr(sentence, color) == NULL){
printf("shit don't work\n");
        return 0;

    }
    else{
//printf("shit works\n");
    }
    while(strstr(sentence, color) != NULL){
        char* word = strstr(sentence, color);
        //printf("%s\n", word);
        while((*word != ',') && (*word != ':') && (*word != ';') && (*word != 10)){
           // printf("%d\n", (int)*word);
            if((*word >= 48) && (*word <=57)){
                char c = *word;
          //      printf("%c\n", c);
                //strncat(number, &c, 1);
            }
            *word--;
        }
       *word++;
        //printf("%s\n", word);
        for(int i = 0;(word[i] != ',')&&(word[i] != ':')&&(word[i] != ';') && (word[i] != '\n'); i++){
            if((word[i] >= 48) && (word[i] <=57)){

                char c = word[i];
                strncat(number, &c, 1);
            }
            word[i] = ' ';
           // printf("%s", word);
            //i++;
        }
        if(STOD(number) > biggest_number){
            biggest_number = STOD(number);
        }
        //printf("%s\n", number);
        strcpy(number, "");
    }
//printf("made it here\n");
    return biggest_number;
}

int main(){

    FILE *fptr;
    int array[100][3];
    int c;
    int red = 12;
    int green = 13;
    int blue = 14;
    int red_cube = 0;
    int blue_cube = 0;
    int green_cube = 0;
    int i = 0;
    int sum = 0;
    char * Line;
    Line = malloc(1024);
    char * number = malloc(16);
    //number = "";
    fptr = fopen("Input.txt", "r");

    if(fptr == NULL){
        printf("Y U Stupid :(\n");
        return 0;
    }
    else{
        printf("You good\n");
    }
    //fgets(Line, sizeof(Line), fptr);
    //printf("%s", Line);
     //fgets(Line, sizeof(Line), fptr);
    //printf("%s", Line);
    while(getc(fptr) != EOF){
        strcpy(number, "");
        fgets(Line, 1024, fptr);
       // printf("%s", Line);
        char* g = strstr(Line, GAME);
        if(g == NULL){
          //  printf("game not present\n");
        }
        else{
            //printf("%s", g);
            //printf("%c\n", *g);
            //*g++;
            //printf("%c\n", *g);
            while(*g != ':' ){
                //printf("%c", *g);
                if((*g >= 48) && (*g <= 57)){
                    char c = *g;
                   // printf("%c", c);
                    strncat(number, &c, 1);
                    //printf("%s", number);
                }
            *g++;
            }
            //printf("made it here\n");
            if(ColorFind(Line, BLUE, 14) > 0){
                printf("Game %d: Failed: Color: %s\n", STOD(number), BLUE);
                blue = ColorFind(Line, BLUE, 14);
                printf("blue = %d\n", blue);
                //continue;
            }
            if(ColorFind(Line, RED, 12) > 0){
                printf("Game %d: Failed: Color: %s\n", STOD(number), RED);
            //    sum = sum + STOD(number);
               // continue;
                red = ColorFind(Line, RED, 12);
                printf("red = %d\n", red);
            }
            if(ColorFind(Line, GREEN, 13) > 0){
                printf("Game %d: Failed: Color: %s\n", STOD(number), GREEN);
                //sum = sum + STOD(number);
                //continue;
                green = ColorFind(Line, GREEN, 13);
                printf("green = %d\n", green);
            }
           // else{
               // sum = sum + STOD(number);
            //}
            }
            //printf("yay\n");
          //  int i = strlen(number);
            //printf("%s length: %d\n",number, i);
            //printf("sum: %d\n", STOD(number));
        strcpy(number, "");
        printf("%d\n", green * red * blue);
            sum = sum + (green * red * blue);
    }
    printf("%d\n", sum);
    return 0;
}
