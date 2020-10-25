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
        TOKEN_LBRACE,
        TOKEN_RPAREN,
        TOKEN_RBRACE,
        TOKEN_COMMA,
        TOKEN_EOF,
    } type;

    char* value;
} token_T;

token_T*
init_token(int, char*);

#endif
