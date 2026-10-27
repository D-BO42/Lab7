/*****************************
* Filename : vector.c
* Author: Dylan Bodoh
* Description: helper for veccalc holds methods and vectors
* Date: 9/29/26
* Compile: gcc -o veccalc veccalc.c vector.c
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"
#include "vectors.h"

//static struct vector vecs[numvectors];   needs to be changed to pointer in dynamit mem
static int size = 10; //starting size of 10 vector
static int filled = 0; // how many are filled
static struct vector *vecs;
void allocate() { //when program first starts
    vecs = malloc(size * sizeof(struct vector)); //10 vec array
}
void reallocate() { //adds 10 vectors to be used to mem
    size += 10;
    
         //if realloc dosent work
        struct vector *tptr;
        tptr = vecs;
        vecs = malloc(size * sizeof(struct vector));
        for(int i = 0; i < filled; i++) {
            vecs[i] = tptr[i];
        }
        free(tptr);
}
void quit() {
    free(vecs);
}

int newvec(char name[8], float x, float y, float z) //adds/replaces vector in the list
{
     
    //check if vector with name already exists and overwrite if does
    for(int i = 0; i < filled; i++) {
       
        if(!strcmp(name, vecs[i].name)) {
            vecs[i].x = x;
            vecs[i].y = y;
            vecs[i].z = z;
            return 0; //means vector was added
        } 
    }
    if(filled == size-2) {
        reallocate();
    }
    //check if full otherwize add at point filled
    //if(filled < 10) {
        strcpy(vecs[filled].name, name);
        vecs[filled].x = x;
        vecs[filled].y = y;
        vecs[filled].z = z;
        filled++;
        return 0; //vector was added
    //} else {
    //    return 1; //if mem is full return 1
    //}
    
}
struct vector addvec(char v1[8], char v2[8]) { //takes name of two vectors and adds them
    //find vectors
   struct vector vec1 = getvector(v1);
   struct vector vec2 = getvector(v2);
   struct vector vec3;
   vec3.x = vec1.x + vec2.x;
   vec3.y = vec1.y + vec2.y;
   vec3.z = vec1.z + vec2.z;
   return vec3;
}
struct vector subvec(char v1[8], char v2[8]) { //takes name of two vectors and subtracts them
    struct vector vec1 = getvector(v1);
    struct vector vec2 = getvector(v2);
    struct vector vec3;
    vec3.x = vec1.x - vec2.x;
    vec3.y = vec1.y - vec2.y;
    vec3.z = vec1.z - vec2.z;
    return vec3;
}
struct vector scaler(float s, char v1[8]) { //given vector and float gives scalar product
    struct vector vec1 = getvector(v1);
    struct vector vec2;
    vec2.x = vec1.x * s;
    vec2.y = vec1.y * s;
    vec2.z = vec1.z * s;
    return vec2;

}

struct vector getvector(char n[8]) { //gets a vector from the list and returns it
     for(int i = 0; i < filled; i++) {
        if(!strcmp(n, vecs[i].name)) {
            return vecs[i];
        } 
        
    }
    struct vector v = {"v", 0.0, 0.0, 0.0};
    printf("vector does not exist\n");
    return v;
}
void printVecs() {
    for(int i = 0; i < filled; i++) {
        printf("%s = %f, %f, %f\n", vecs[i].name, vecs[i].x, vecs[i].y, vecs[i].z);
        
    }

}
void save(char filename[50]){
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen");
        return;
    }
    for(int i = 0; i < filled; i++) {
        fprintf(file, "%s,%f,%f,%f\n", vecs[i].name, vecs[i].x, vecs[i].y, vecs[i].z);
    }
    fclose(file);
}
void load(char filename[50]){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }
    struct vector vec;
    while (fscanf(file, "%19[^,],%f,%f,%f", vec.name, &vec.x, &vec.y, &vec.z) == 4){
        newvec(vec.name, vec.x, vec.y, vec.z);
    }
    fclose(file);
}
void clearVecs() {
    filled = 0; //set filled to 0 so they can be overwriten.
}


