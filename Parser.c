#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "Parser.h"


int advance(FILE *src_f, int cmd_size, char command[][cmd_size]){
    int i, j, k;
    char raw_command[200];

    do{
        if (fgets(raw_command, 200, src_f) == NULL) return 0;

        j = 0;
        for(i = 0; i < 3; i++){
            strZero(command[i], cmd_size);
            
            while(raw_command[j] == ' ') j++;
            if(isRtnCmnt(raw_command, j)) continue;            

            k = 0;
            while(raw_command[j] != ' ' && ! isRtnCmnt(raw_command, j)) {
                command[i][k++] = raw_command[j++];
            }
        }
    } while(command[0][0] == '\0');

    return 1;
}

int commandType(int cmd_size, char command[][cmd_size]){
    if(strcmp(command[0], "push") == 0) return C_PUSH;
    else if (strcmp(command[0], "pop") == 0) return C_POP;
    else return C_ARITHMETIC;
}

int arg1(int cmd_size, char command[][cmd_size], int cmd_type){
    if(cmd_type == C_ARITHMETIC){
        if(strcmp(command[0], "add") == 0) return A_ADD;
        else if(strcmp(command[0], "sub") == 0) return A_SUB;
        else if(strcmp(command[0], "neg") == 0) return A_NEG;
        else if(strcmp(command[0], "eq") == 0) return A_EQ;
        else if(strcmp(command[0], "gt") == 0) return A_GT;
        else if(strcmp(command[0], "lt") == 0) return A_LT;
        else if(strcmp(command[0], "and") == 0) return A_AND;
        else if(strcmp(command[0], "or") == 0) return A_OR;
        else if(strcmp(command[0], "not") == 0) return A_NOT;
    }

    if(cmd_type == C_PUSH || cmd_type == C_POP){
        if(strcmp(command[1], "argument") == 0) return ARGUMENT;
        else if(strcmp(command[1], "local") == 0) return LOCAL;
        else if(strcmp(command[1], "static") == 0) return STATIC;
        else if(strcmp(command[1], "constant") == 0) return CONSTANT;
        else if(strcmp(command[1], "this") == 0) return THIS;
        else if(strcmp(command[1], "that") == 0) return THAT;
        else if(strcmp(command[1], "pointer") == 0) return POINTER;
        else if(strcmp(command[1], "temp") == 0) return TEMP;
    }
}

int arg2(int cmd_size, char command[][cmd_size], int cmd_type){
    int num = atoi(command[2]);
    return num;
}

void strZero(char command[], int cmd_size){
    int i;
    for(i = 0; i < cmd_size; i++) command[i] = '\0';

    return;
}

int isRtnCmnt(char raw_command[], int index){
    if(raw_command[index] == CR || raw_command[index] == '/' && raw_command[index+1] == '/') return 1;
    else return 0;
}