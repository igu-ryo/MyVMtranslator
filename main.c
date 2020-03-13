#include<stdio.h>
#include "Parser.h"
#include "CodeWriter.h"

int write_cnt = 0;

void main(int argc, char *argv[]){
    FILE *src_f, *asm_f;
    char command[3][15], asm_name[50] = {'\0'};
    int i = 0, cmd_type, cmd_size = sizeof command[0] / sizeof command[0][0];

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
        if (!advance(src_f, cmd_size, command)) break;

        cmd_type = commandType(cmd_size, command);
        switch (cmd_type)
        {
        case C_ARITHMETIC:
            writeArithmetic(asm_f, arg1(cmd_size, command, C_ARITHMETIC));
            break;
        
        case C_PUSH:
            writePushPop(asm_f, C_PUSH, arg1(cmd_size, command, C_PUSH), arg2(cmd_size, command, C_PUSH));
            break;
        
        case C_POP:
            break;
        
        default:
            break;
        }
    }

    // 無限ループ
    fprintf(asm_f, "(INFINITE_LOOP)\n");
    fprintf(asm_f, "@INFINITE_LOOP\n");
    fprintf(asm_f, "0;JMP\n");

    // ファイルクローズ
    fclose(src_f);
    fclose(asm_f);

    return;
}