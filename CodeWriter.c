#include<stdio.h>
#include<stdlib.h>
#include "Parser.h"
#include "CodeWriter.h"

void writeArithmetic(FILE *asm_f, int a_type){
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
        fprintf(asm_f, "@TRUE%d\n", write_cnt);
        fprintf(asm_f, "D;JEQ\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=0\n");
        fprintf(asm_f, "@END%d\n", write_cnt);
        fprintf(asm_f, "0;JMP\n");
        fprintf(asm_f, "(TRUE%d)\n", write_cnt);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=-1\n");
        fprintf(asm_f, "(END%d)\n", write_cnt);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
        write_cnt++;
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
        fprintf(asm_f, "@TRUE%d\n", write_cnt);
        fprintf(asm_f, "D;JGT\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=0\n");
        fprintf(asm_f, "@END%d\n", write_cnt);
        fprintf(asm_f, "0;JMP\n");
        fprintf(asm_f, "(TRUE%d)\n", write_cnt);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=-1\n");
        fprintf(asm_f, "(END%d)\n", write_cnt);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
        write_cnt++;
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
        fprintf(asm_f, "@TRUE%d\n", write_cnt);
        fprintf(asm_f, "D;JLT\n");
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=0\n");
        fprintf(asm_f, "@END%d\n", write_cnt);
        fprintf(asm_f, "0;JMP\n");
        fprintf(asm_f, "(TRUE%d)\n", write_cnt);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "A=M\n");
        fprintf(asm_f, "M=-1\n");
        fprintf(asm_f, "(END%d)\n", write_cnt);
        fprintf(asm_f, "@SP\n");
        fprintf(asm_f, "M=M+1\n");
        write_cnt++;
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

void writePushPop(FILE *asm_f, int cmd_type, int seg_type, int num){
    if(cmd_type == C_PUSH){
        if(seg_type == CONSTANT){
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "D=A\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "M=D\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "M=M+1\n");
        }
    }else if(cmd_type == C_POP){
        if(seg_type == CONSTANT){
            fprintf(asm_f, "@%d\n", num);
            fprintf(asm_f, "D=A\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "A=M\n");
            fprintf(asm_f, "M=D\n");
            fprintf(asm_f, "@SP\n");
            fprintf(asm_f, "M=M+1\n");
        }
    }
}