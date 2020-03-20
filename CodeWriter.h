#ifndef _INCLUDE_CODEWRITER_
#define _INCLUDE_CODEWRITER_

#include<stdio.h>

void writeInit(FILE *asm_f, int *write_cnt_p);
void writeArithmetic(FILE *asm_f, int a_type, int *write_cnt_p);
void writePushPop(FILE *asm_f, int cmd_type, int seg_type, int num, char vm_name[]);
void writeLabel(FILE *asm_f, char label[]);
void writeGoto(FILE *asm_f, char label[]);
void writeIf(FILE *asm_f, char label[]);
void writeCall(FILE *asm_f, char func_name[], int numArgs, int *write_cnt_p);
void writeReturn(FILE *asm_f);
void writeFunction(FILE *asm_f, char func_name[], int numLocals);

#endif