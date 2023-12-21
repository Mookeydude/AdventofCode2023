#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int STOD();

int main(){
    char* number = malloc(16);
    char* Word = malloc(1028);
    int seed_array[30];
    char buffer[200];
    int j = 0;
    int numstart = 0;
    int seed_number = 0;
    int soil_number = 0;
    int map_array[3];
    int seed_size = 0;
    FILE* fptr = fopen("Input.txt", "r");
    if(fptr == NULL){
        printf("File failed to open\n");
        return 1;
    }

    while(fgets(Word, sizeof buffer, fptr) != NULL){
        //printf("%s", Word);
        //printf("%c\n", Word[0])
       // printf("Line length: %d\n", (int)strlen(Word));
        if((strstr(Word, "seed-to-soil")) != NULL){
            seed_number = 1;
            //j = 0;
            //seed_size = j;
            j = 0;
        }
        else if((strstr(Word, "soil-to-fertilizer")) != NULL){
            soil_number = 1;
        }
        //if(!seed_number){
            for(int i = 0; i < (int)strlen(Word); i++){
                //printf("%c\n", Word[i]);
            if(isdigit(Word[i])){
                numstart = 1;
                strncat(number, &Word[i], 1);
            }
            else if((Word[i] == ' ') || (Word[i] == '\n')){
                if(numstart){
                    numstart = 0;
                    printf("%d\n", STOD(number));
                    if(!seed_number){
                        seed_array[j] = STOD(number);
                        seed_size = j;
                        j++;
                    }
                    else if((seed_number) && (!soil_number)){
                        map_array[j] = STOD(number);
                        if(Word[i] == '\n'){
                            for(int m = 0; m<seed_size)


                        }

                    }
                    strcpy(number, "");
                }
            }
           // seed_number = 1;
        //}

        }//
    }
return 0;
}

int STOD(char* number){
int sum = 0;

for(int i = strlen(number); i>0; i--){
//printf("%d\n", number[strlen(number)])
sum = sum +((number[strlen(number)-i]-48) * (pow(10, i-1)));
}
return sum;
}
