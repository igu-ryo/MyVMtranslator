#ifndef _INCLUDE_PARSER_
#define _INCLUDE_PARSER_

#define CR 13

enum{
    C_ARITHMETIC,
    C_PUSH,
    C_POP,
    C_LABEL,
    C_GOTO,
    C_IF,
    C_FUNCTION,
    C_RETURN,
    C_CALL
};

enum{
    A_ADD,
    A_SUB,
    A_NEG,
    A_EQ,
    A_GT,
    A_LT,
    A_AND,
    A_OR,
    A_NOT,
    ARGUMENT,
    LOCAL,
    STATIC,
    CONSTANT,
    THIS,
    THAT,
    POINTER,
    TEMP
};

int advance(FILE *src_f, int cmd_size, char command[][cmd_size]);
int commandType(int cmd_size, char command[][cmd_size]);
int arg1(int cmd_size, char command[][cmd_size], int cmd_type);
int arg2(int cmd_size, char command[][cmd_size], int cmd_type);
void strZero(char command[], int cmd_size);
int isRtnCmnt(char raw_command[], int index);

extern int write_cnt;

#endif