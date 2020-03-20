#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include "Parser.h"
#include "CodeWriter.h"

void main(int argc, char *argv[]){
    FILE *src_f, *asm_f;
    DIR *dp = opendir(argv[1]);
    struct dirent *dirst;
    char command[3][15], vm_name[50] = {'\0'}, asm_name[50] = {'\0'}, func_name[50] = {'\0'};
    int i = 0, j = 0, write_cnt, *write_cnt_p, cmd_type, cmd_size = sizeof command[0] / sizeof command[0][0], func_size = sizeof func_name / sizeof func_name[0];
    write_cnt_p = &write_cnt;
    write_cnt = 0;

    // asmファイルの名前
    sprintf(asm_name, "%s.asm", argv[1]);

    asm_f = fopen(asm_name, "w");

    writeInit(asm_f, write_cnt_p);

    while((dirst = readdir(dp)) != NULL){

        // vmファイルじゃなかったら次のループ
        if(strstr(dirst->d_name, ".vm") == NULL) continue;
        
        // vmファイルの準備
        strZero(vm_name, 50);
        sprintf(vm_name, "%s/", argv[1]);
        strcat(vm_name, dirst->d_name);

        src_f = fopen(vm_name, "r");
        
        // EOFまで一行ずつ処理
        while (1){
            if (!advance(src_f, cmd_size, command)) break;

            cmd_type = commandType(cmd_size, command);
            switch (cmd_type)
            {
            case C_ARITHMETIC:
                writeArithmetic(asm_f, arg1(cmd_size, command, C_ARITHMETIC), write_cnt_p);
                break;

            case C_PUSH:
                writePushPop(asm_f, C_PUSH, arg1(cmd_size, command, C_PUSH), arg2(cmd_size, command), vm_name);
                break;

            case C_POP:
                writePushPop(asm_f, C_POP, arg1(cmd_size, command, C_POP), arg2(cmd_size, command), vm_name);
                break;

            case C_LABEL:
                writeLabel(asm_f, command[1]);
                break;

            case C_GOTO:
                writeGoto(asm_f, command[1]);
                break;

            case C_IF:
                writeIf(asm_f, command[1]);
                break;

            case C_FUNCTION:
                writeFunction(asm_f, command[1], arg2(cmd_size, command));
                sprintf(func_name, "%s", command[1]);
                break;

            case C_RETURN:
                writeReturn(asm_f);
                strZero(func_name, func_size);
                break;
            
            case C_CALL:
                writeCall(asm_f, command[1], arg2(cmd_size, command), write_cnt_p);
                break;

            default:
                break;
            }
        }


        fclose(src_f);
        
    }
    fclose(asm_f);

    closedir(dp);
    
    return;
}