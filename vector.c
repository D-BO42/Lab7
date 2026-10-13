/*****************************
* Filename : vector.c
* Author: Dylan Bodoh
* Description: prints out the ascii table or the dec hex and bin of a ascii char
* Date: 9/29/26
* Compile: gcc -o veccalc veccalc.c
*/
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "vectors.h"
#define numvectors 10

static struct vector vecs[numvectors];
static int filled = 0;
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
    
    //check if full otherwize add at point filled
    if(filled < 10) {
        strcpy(vecs[filled].name, name);
        vecs[filled].x = x;
        vecs[filled].y = y;
        vecs[filled].z = z;
        filled++;
        return 0; //vector was added
    } else {
        return 1; //if mem is full return 1
    }
    
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
void clearVecs() {
    filled = 0; //set filled to 0 so they can be overwriten.
}

