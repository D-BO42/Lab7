/*****************************
* Filename : veccalc.c
* Author: Dylan Bodoh
* Description: prints out the ascii table or the dec hex and bin of a ascii char
* Date: 9/29/26
* Compile: gcc -o veccalc veccalc.c
*/
#include <stdio.h>
#include <string.h>
#include "vector.h"
#include "vectors.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    char input[99];
    
    if(argc > 1 && !strcmp(argv[1], "-h")) {
        printf("Vector Calculator Help\n"
        "----------------------\n\n"
        "Commands:\n"
        " quit Exit the program.\n"
        " clear Delete all stored vectors.\n"
        " help Display this help message.\n\n"
        "Vector Assignment:\n"
        " varname = x y z\n"
        "Display Vector:\n"
        " vector name\n"
        "Addition:\n"
        " var1 + var2\n\n"
        "Subtraction:\n"
        " var1 - var2\n\n"
        "Scalar Multiplication:\n"
        " var1 * number\n\n"
        "Assignment from Expression:\n"
        " result = var1 + var2\n"
        " result = var1 - var2\n"
        " result = var1 * number\n\n"
        "Notes:\n"
        " * Spaces are required around operators.\n"
        " * Maximum of 10 vectors may be stored.\n"
        " * Referenced vectors must exist.\n");
    }
    while(1) {
        printf("VECCALC> ");
        //pointers to different parts of input
        char *token1 = NULL;
        char *token2 = NULL;
        char *token3 = NULL; 
        char *token4 = NULL;
        char *token5 = NULL;
        
        fgets(input, 99, stdin);
        
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == '\n') {
                input[i] = ' ';
            }
        }
        //printf("%c", input);
        if (input[0] != '\n') {
            token1 = strtok(input, " "); //gets the string of the first val
        }
        if(token1 != NULL) {
            token2 = strtok(NULL, " ");
        }
         if(token2 != NULL) {
            token3 = strtok(NULL, " ");
        }
         if(token3 != NULL) {
            token4 = strtok(NULL, " ");
        }
         if(token4 != NULL) {
            token5 = strtok(NULL, " ");
        }
        if(token2 == NULL) 
            {
                //display, quit, help
                if(!strcmp(token1, "quit")) {
                    break;
                } else if(!strcmp(token1, "help")) {
                    printf("Vector Calculator Help\n"
                    "----------------------\n\n"
                    "Commands:\n"
                    " quit Exit the program.\n"
                    " clear Delete all stored vectors.\n"
                    " help Display this help message.\n\n"
                    "Vector Assignment:\n"
                    " varname = x y z\n"
                    "Display Vector:\n"
                    " vector name\n"
                    "Addition:\n"
                    " var1 + var2\n\n"
                    "Subtraction:\n"
                    " var1 - var2\n\n"
                    "Scalar Multiplication:\n"
                    " var1 * number\n\n"
                 
                    "Assignment from Expression:\n"
                    " result = var1 + var2\n"
                    " result = var1 - var2\n"
                    " result = var1 * number\n\n"
                    "Notes:\n"
                    " * Spaces are required around operators.\n"
                    " * Maximum of 10 vectors may be stored.\n"
                    " * Referenced vectors must exist.\n");
                }else if(!strcmp(token1, "list")) {
                    printVecs();
                }else if(!strcmp(token1, "clear")) {
                    clearVecs(); //clear vectors
                
                }else {
                    struct vector vec = getvector(token1);
                    printf("%s = %f, %f, %f\n", token1, vec.x, vec.y, vec.z);
                }
            }
        else if(!strcmp(token2, "="))
        {
            if(token4 != NULL && !strcmp(token4, "+"))
            {
                //c = a + b
                struct vector vec = addvec(token3, token5);
                if(newvec(token1, vec.x, vec.y, vec.z)) {
                    printf("mem full\n");
                } else {
                    printf("%s = %f, %f, %f\n", token1, vec.x, vec.y, vec.z);
                }
            }
            else if(token4 != NULL && !strcmp(token4, "-"))
            {
                //c = a - b
                struct vector vec = subvec(token3, token5);
                if(newvec(token1, vec.x, vec.y, vec.z)) {
                    printf("mem full\n");
                } else {
                    printf("%s = %f, %f, %f\n", token1, vec.x, vec.y, vec.z);
                }
            }
            else if(token4 != NULL && !strcmp(token4, "*"))
            {
                //c = a * 2 
                char *endptr;
                strtof(token3, &endptr);
                struct vector vec;
                if(endptr != token3 && *endptr == '\0') {
                    vec = scaler(atof(token3), token5);
             
                } else {
                    vec = scaler(atof(token5), token3);
           
                }
                
                if(newvec(token1, vec.x, vec.y, vec.z)) {
                    printf("mem full\n");
                } else {
                    printf("%s = %f, %f, %f\n", token1, vec.x, vec.y, vec.z);
                }
            }
            else
            {
                //a = 1 2 3
                if(newvec(token1, atof(token3), atof(token4), atof(token5))) {
                    printf("mem full\n");
                }
            }
        }
        else if(!strcmp(token2, "+"))
        {
            //a + b
            struct vector vec = addvec(token1, token3);
            printf("%f %f %f\n", vec.x, vec.y, vec.z);
        }
        else if(!strcmp(token2, "-"))
        {
            //a - b
            struct vector vec = subvec(token1, token2);
            printf("%f %f %f\n", vec.x, vec.y, vec.z);
        }
        else if(!strcmp(token2, "*"))
        {
            //a * 2
            char *endptr;
            strtof(token1, &endptr);
            if(endptr != token1 && *endptr == '\0') {
            struct vector vec = scaler(atof(token1), token3);
            printf("%f %f %f\n", vec.x, vec.y, vec.z); 
        } else {
            struct vector vec = scaler(atof(token3), token1);
            printf("%f %f %f\n", vec.x, vec.y, vec.z); 
        }

        }
        else
        {
            printf("bad input\n");
        }
    }



    return 0;
}