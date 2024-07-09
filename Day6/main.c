#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE* fp = fopen("Input.txt", "r");
    char Line[256];
    fgets(Line, 256, fp);
    int times[15] = {0};
    int distances[15] = {0};

    char * start;
    char * end = &Line[6];
    int num = -1;
    do {
        printf("ran the while\n");
    start = end;
    times[++num] = strtoll(start, &end, 10);
} while (start != end);

    fgets(Line,256, fp);
    end = &Line[9];
    num = -1;
    do {
        start = end;
        distances[++num] = strtoll(start, &end, 10);
    } while (start != end);

    for(int k = 0; k<num; k++){

    }
//printf("Numbers read was %d\n", num);
for(int i=0; i<num; i++){

//printf("%d\n", times[i]);

}
    return 0;
}
