#ifndef _TOKEN_H_
#define _TOKEN_H_

typedef struct TOKEN_STRUCT
{
    enum
    {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_STRING,
        TOKEN_SEMI,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
    } type;

    char* value;
} token_T;

token_T*
init_token(int, char*);

#endif
