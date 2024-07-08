#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>
#include <limits.h>

typedef struct{
    u_int64_t source;
    u_int64_t dest;
    u_int64_t count;
}map;

int numofmaps;
map maplist[100][100] = {0, 0, 0};

u_int64_t mappath(u_int64_t seed, u_int64_t* dist_to_next){
    u_int64_t lowest_distance = LLONG_MAX;
    for(int i = 0; i<numofmaps; i++){
        for(int k = 0; ;k++){
            map checkmap = maplist[i][k];
            //printf("source %"PRIu64" destination %"PRIu64" count %"PRIu64"\n", maplist[i][k].source, maplist[i][k].dest, maplist[i][k].count);
            if((seed >= checkmap.source) && (seed < checkmap.source + checkmap.count)){
                u_int64_t dist_to_next = checkmap.count - (seed - checkmap.source);
                if(dist_to_next < lowest_distance){
                    lowest_distance = dist_to_next;
                }
                seed -= checkmap.source;
                seed += checkmap.dest;
                //printf("seed is now %"PRIu64"\n", seed);
                break;
            }
            if(maplist[i][k].count == 0){
                //printf("reached here\n");
                break;
            }
        }
    }
    if(dist_to_next){
        *dist_to_next = lowest_distance;
    }
    return seed;
}

int linesinmap = 0;
int main(){
    FILE* fp = fopen("Input.txt", "r");
    char Line[256];
    int num_seeds = -1;
    u_int64_t seeds[100] = {0};
    fgets(Line, 256, fp);
    char * start;
    char* end = &Line[7];
    do{
        start = end;
        seeds[++num_seeds] = strtoll(start, &end, 10);
    }while(start != end);
    for(int i=0; seeds[i] != 0; i++){
       // printf("%"PRIu64"\n", seeds[i]);
    }

    numofmaps = 0;
    while (fgets(Line,256,fp) != NULL) {
        if(strchr(Line, ':')){
           // printf("Reached here\n");
                numofmaps++;
                linesinmap = 0;
            }
        else if (strlen(Line) > 1) {
            u_int64_t source, destination, count;
            sscanf(Line,"%"SCNu64" %"SCNu64" %"SCNu64, &destination, &source, &count);
            map newmap = {source, destination, count};
            maplist[numofmaps-1][linesinmap++] = newmap;
        }
    }
    u_int64_t lowest_number = LLONG_MIN;
    for(int i = 0; i<num_seeds; i++){
        printf("Seed is %"PRIu64"\n", seeds[i]);
        u_int64_t seed = mappath(seeds[i], NULL);
        //num_seeds++;
        printf("\n");
        if(lowest_number > seed){
            lowest_number = seed;
        }
    }
    printf("The lowest one is %"PRIu64"\n", lowest_number);

    lowest_number = LLONG_MIN;
    for(int i = 0; i<num_seeds; i+=2){
        u_int64_t range_start = seeds[i];
        u_int64_t range_end = range_start + seeds[i+1];
        while (range_start<range_end) {
            u_int64_t jump;
            u_int64_t part_two_seed = mappath(range_start, &jump);
            if(part_two_seed < lowest_number){
                lowest_number = part_two_seed;
            }
            range_start += jump;
        }

    }
    printf("Part 2 lowest = %"PRIu64"\n", lowest_number);
    //printf("it worked\n");
    return 0;
}
