#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int STOD();
int searchcard();

int main(){

    FILE* fptr;
    char  Line[400];
    //Line = malloc(512);
    int sum = 0;
    int total = -1;
    int cardtotal = 0;
    int scratchcard[10];
    int duplicate[10] = {1,1,1,1,1,1,1,1,1,1};
    int start = 0;
    char* number = malloc(16);
    fptr = fopen("Input.txt", "r");
    if(fptr == NULL){
        printf("File failed to open\n");
        return 1;
    }
    while(fgets(Line, sizeof Line, fptr) != NULL ) {
        int i = 0;
        int j = 0;
        int numstart = 0;
        int first = 0;
        int liststart = 0;
        int currentcardtotal = 0;
       // char* number;
       // int total = 0;
        number=malloc(16);
              printf("%s", Line);
        while(Line[i] != 0){
            start = 1;
            if(Line[i] == ':'){
                first = 1;
            }
            else if ((first == 1) && (isdigit(Line[i]))) {
                strncat(number, &Line[i], 1);
                numstart = 1;
            }
            else if((first == 1) && (numstart == 1) && ((Line[i] == ' ') || (Line[i] == '\n'))){
                if(liststart != 1){
                    //printf("%d\n", STOD(number));
                    scratchcard[j] = STOD(number);
                    strcpy(number, "");
                    j++;
                    numstart = 0;
                }

                else{
                  //  printf("%d\n", STOD(number));
                    if(searchcard(scratchcard, STOD(number)) > 0){
                        printf("match was found! %d\n", STOD(number));
                        total++;
                    }
                    strcpy(number, "");
            }
            }
            else if(Line[i] == '|'){
                //first = 0;
                numstart = 0;
                liststart = 1;
            }
            //printf("%c\n", Line[i]);
        i++;

                }
  if(total >= -1){
        //
        if(start > 0){
            cardtotal = cardtotal + duplicate[0];
            currentcardtotal = duplicate[0];
            printf("Number of matches%d\n", total + 1);
        printf("Number of cards %d\n", duplicate[0]);
        printf("Card Total = %d\n", cardtotal);
               }
            printf("cardtotal:%d\n", cardtotal);
            printf("total = %d\n", total);
            for(int k = 1; k <= 10; k++){
              if(k != 10){
                 duplicate[k-1] = duplicate[k];
              }
             else{
                  duplicate[k-1] = 1;
             }
           }
          for(int k = 0; k <= total; k++){
              duplicate[k] = duplicate[k] + currentcardtotal;
          }
          for(int m = 0; m < 10; m++){
            printf("number of cards%d: %d\n", m, duplicate[m]);
       }

          sum = sum + pow(2, total);
          //printf("Cardtotal = %d\n", cardtotal);
        //  printf("sum = %d\n", sum)
        }
        total = -1;


    }
    printf("Card Total is %d\n", cardtotal);
    printf("Total is %d\n", sum);
return 0;
}


int searchcard(int array[10], int number){
int j = 0;
for(int i = 0; i<10;  i++){
    if(number == array[i]){
j++;
    }

}
return j;
}

int STOD(char* number){
int sum = 0;

for(int i = strlen(number); i>0; i--){
//printf("%d\n", number[strlen(number)])
sum = sum +((number[strlen(number)-i]-48) * (pow(10, i-1)));
}
return sum;
}
