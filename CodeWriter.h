#ifndef _INCLUDE_CODEWRITER_
#define _INCLUDE_CODEWRITER_

#include<stdio.h>

void writeArithmetic(FILE *asm_f, int a_type);
void writePushPop(FILE *asm_f, int cmd_type, int seg_type, int num);

#endif