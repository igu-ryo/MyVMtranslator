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

int advance(FILE *, char *[]);
int commandType(char *[]);
void strZero(char [], int);
int isRtnCmnt(char [], int);

#endif