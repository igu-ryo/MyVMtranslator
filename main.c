#include<stdio.h>
#include "Parser.h"

void main(int argc, char *argv[]){
    FILE *src_f, *asm_f;
    char command[3][15], asm_name[50];
    int i = 0;

    // asmファイルの名前
    while (argv[1][i] != '.'){
        asm_name[i] = argv[1][i];
        i++;
    }
    sprintf(asm_name, "%s.asm", asm_name);

    // ファイルオープン
    src_f = fopen(argv[1], "r");
    asm_f = fopen(asm_name, "w");

    // EOFまで一行ずつ処理
    while (1){
        if (!advance(src_f, command)) break;

        switch (commandType(command))
        {
        case C_ARITHMETIC:
            /* code */
            break;
        
        case C_PUSH:
            /* code */
            break;
        
        case C_POP:
            /* code */
            break;
        
        default:
            break;
        }
    }

    // ファイルクローズ
    fclose(src_f);
    fclose(asm_f);


    return;
}