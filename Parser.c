#include<stdio.h>
#include "Parser.h"

int advance(FILE *src_f, char *command[]){
    int i, j, k, cmd_size = sizeof command[0] / sizeof command[0][0];
    char raw_command[200];

    do{
        if (fgets(raw_command, 200, src_f) == NULL) return 0;

        j = 0;
        for(i = 0; i < 3; i++){
            strZero(command[i], cmd_size);

            while(raw_command[j++] == ' ');

            if(! isRtnCmnt(raw_command, j)) break;

            k = 0;
            while(raw_command[j] != ' ' && ! isRtnCmnt(raw_command, j)) command[i][k++] = raw_command[j++];
        }
    } while(command[0][0] == '\0');
}

int commandType(char *command[]){

}

void strZero(char command[], int cmd_size){}

int isRtnCmnt(char raw_command[], int index){
    if(raw_command[index] == CR || raw_command[index] == '/' && raw_command[index+1] == '/') return 1;
    else return 0;
}