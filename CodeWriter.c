#include<stdio.h>
#include<stdlib.h>
#include "Parser.h"
#include "CodeWriter.h"

void writeInit(FILE *asm_f, int *write_cnt_p){
    fprintf(asm_f, "@256\n");
    fprintf(asm_f, "D=A\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "M=D\n");
    writeCall(asm_f, "Sys.init", 0, write_cnt_p);
}

void writeArithmetic(FILE *asm_f, int a_type, int *write_cnt_p){
    if(a_type == A_ADD){
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "D=D+M\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
    } else if(a_type == A_SUB){
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "D=D-M\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
    } else if(a_type == A_NEG){
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "M=-M\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
    } else if(a_type == A_EQ){
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "D=D-M\n");
        fprintf(asm_f, "@TRUE%d\n", *write_cnt_p);
        fprintf(asm_f, "D;JEQ\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=0\n");
        fprintf(asm_f, "@END%d\n", *write_cnt_p);
        fprintf(asm_f, "0;JMP\n");
        fprintf(asm_f, "(TRUE%d)\n", *write_cnt_p);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=-1\n");
        fprintf(asm_f, "(END%d)\n", *write_cnt_p);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
        *write_cnt_p += 1;
    } else if(a_type == A_GT){
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "D=D-M\n");
        fprintf(asm_f, "@TRUE%d\n", *write_cnt_p);
        fprintf(asm_f, "D;JGT\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=0\n");
        fprintf(asm_f, "@END%d\n", *write_cnt_p);
        fprintf(asm_f, "0;JMP\n");
        fprintf(asm_f, "(TRUE%d)\n", *write_cnt_p);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=-1\n");
        fprintf(asm_f, "(END%d)\n", *write_cnt_p);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
        *write_cnt_p += 1;
    } else if(a_type == A_LT){
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "D=D-M\n");
        fprintf(asm_f, "@TRUE%d\n", *write_cnt_p);
        fprintf(asm_f, "D;JLT\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=0\n");
        fprintf(asm_f, "@END%d\n", *write_cnt_p);
        fprintf(asm_f, "0;JMP\n");
        fprintf(asm_f, "(TRUE%d)\n", *write_cnt_p);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=-1\n");
        fprintf(asm_f, "(END%d)\n", *write_cnt_p);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
        *write_cnt_p += 1;
    } else if(a_type == A_AND){
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "D=D&M\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
    } else if(a_type == A_OR){
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "D=M\n");
        fprintf(asm_f, "@R13\n");
        fprintf(asm_f, "D=D|M\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
    } else if(a_type == A_NOT){
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "AM=M-1\n");
        fprintf(asm_f, "M=!M\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
    }
}

void writePushPop(FILE *asm_f, int cmd_type, int seg_type, int num, char vm_name[]){
    if(cmd_type == C_PUSH){
        if(seg_type == CONSTANT){
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "D=A\n");
        } else if(seg_type == LOCAL){
            fprintf(asm_f, "@LCL\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "A=D+A\n");
            fprintf(asm_f, "D=M\n");
        } else if(seg_type == ARGUMENT){
            fprintf(asm_f, "@ARG\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "A=D+A\n");
            fprintf(asm_f, "D=M\n");
        } else if(seg_type == THIS){
            fprintf(asm_f, "@THIS\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "A=D+A\n");
            fprintf(asm_f, "D=M\n");
        } else if(seg_type == THAT){
            fprintf(asm_f, "@THAT\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "A=D+A\n");
            fprintf(asm_f, "D=M\n");
        } else if(seg_type == POINTER){
            fprintf(asm_f, "@3\n");
            fprintf(asm_f, "D=A\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "A=D+A\n");
            fprintf(asm_f, "D=M\n");
        } else if(seg_type == TEMP){
            fprintf(asm_f, "@5\n");
            fprintf(asm_f, "D=A\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "A=D+A\n");
            fprintf(asm_f, "D=M\n");
        } else if(seg_type == STATIC){
            fprintf(asm_f, "@%s.%d\n", vm_name, num);
            fprintf(asm_f, "D=M\n");
        }

        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=D\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
    }else if(cmd_type == C_POP){
        if(seg_type == LOCAL){
            fprintf(asm_f, "@LCL\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "D=D+A\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "M=D\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "M=M-1\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "M=D\n");
        } else if(seg_type == ARGUMENT){
            fprintf(asm_f, "@ARG\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "D=D+A\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "M=D\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "M=M-1\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "M=D\n");
        } else if(seg_type == THIS){
            fprintf(asm_f, "@THIS\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "D=D+A\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "M=D\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "M=M-1\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "M=D\n");
        } else if(seg_type == THAT){
            fprintf(asm_f, "@THAT\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "D=D+A\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "M=D\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "M=M-1\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "M=D\n");
        } else if(seg_type == POINTER){
            fprintf(asm_f, "@3\n");
            fprintf(asm_f, "D=A\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "D=D+A\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "M=D\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "M=M-1\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "M=D\n");
        } else if(seg_type == TEMP){
            fprintf(asm_f, "@5\n");
            fprintf(asm_f, "D=A\n");
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "D=D+A\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "M=D\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "M=M-1\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@R13\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "M=D\n");
        } else if(seg_type == STATIC){
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "M=M-1\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "D=M\n");
            fprintf(asm_f, "@%s.%d\n", vm_name, num);
            fprintf(asm_f, "M=D\n");
        }

        
    }
}

void writeLabel(FILE *asm_f, char label[]){
    fprintf(asm_f, "(%s)\n", label);
}

void writeGoto(FILE *asm_f, char label[]){
    fprintf(asm_f, "@%s\n", label);
    fprintf(asm_f, "0;JMP\n");
}

void writeIf(FILE *asm_f, char label[]){
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "M=M-1\n");
    fprintf(asm_f, "A=M\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@%s\n", label);
    fprintf(asm_f, "D;JNE\n");
}

void writeCall(FILE *asm_f, char func_name[], int numArgs, int *write_cnt_p){
    fprintf(asm_f, "@return-address%d\n", *write_cnt_p);
    fprintf(asm_f, "D=A\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "A=M\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "M=M+1\n");
    fprintf(asm_f, "@LCL\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "A=M\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "M=M+1\n");
    fprintf(asm_f, "@ARG\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "A=M\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "M=M+1\n");
    fprintf(asm_f, "@THIS\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "A=M\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "M=M+1\n");
    fprintf(asm_f, "@THAT\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "A=M\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "MD=M+1\n");
    fprintf(asm_f, "@5\n");
    fprintf(asm_f, "D=D-A\n");
    fprintf(asm_f, "@%d\n", numArgs);
    fprintf(asm_f, "D=D-A\n");
    fprintf(asm_f, "@ARG\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@LCL\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@%s\n", func_name);
    fprintf(asm_f, "0;JMP\n");
    fprintf(asm_f, "(return-address%d)\n", *write_cnt_p);
    *write_cnt_p += 1;
}

void writeReturn(FILE *asm_f){
    fprintf(asm_f, "@LCL\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@R15\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@5\n");
    fprintf(asm_f, "A=D-A\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@R14\n");
    fprintf(asm_f, "M=D\n");
    writePushPop(asm_f, C_POP, ARGUMENT, 0, NULL);
    fprintf(asm_f, "@ARG\n");
    fprintf(asm_f, "D=M+1\n");
    fprintf(asm_f, "@SP\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@R15\n");
    fprintf(asm_f, "A=M-1\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@THAT\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@R15\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@2\n");
    fprintf(asm_f, "A=D-A\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@THIS\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@R15\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@3\n");
    fprintf(asm_f, "A=D-A\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@ARG\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@R15\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@4\n");
    fprintf(asm_f, "A=D-A\n");
    fprintf(asm_f, "D=M\n");
    fprintf(asm_f, "@LCL\n");
    fprintf(asm_f, "M=D\n");
    fprintf(asm_f, "@R14\n");
    fprintf(asm_f, "A=M\n");
    fprintf(asm_f, "0;JMP\n");
}

void writeFunction(FILE *asm_f, char func_name[], int numLocals){
    int i;

    fprintf(asm_f, "(%s)\n", func_name);
    for(i = 0; i < numLocals; i++){
        writePushPop(asm_f, C_PUSH, CONSTANT, 0, NULL);
    }
}