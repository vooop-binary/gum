#ifndef _GUM_LEXER_H_
#define _GUM_LEXER_H_

#include "token.h"

typedef struct LEXER_STRUCT 
{
    char c;
    unsigned int i;
    char* contents;
} lexer_T;


lexer_T*
init_lexer(char*);

void
lexer_advance(lexer_T*);

void
lexer_skip_whitespace(lexer_T*);

token_T*
lexer_get_next_token(lexer_T*);

token_T*
lexer_collect_string(lexer_T*);

token_T*
lexer_collect_id(lexer_T*);

token_T*
lexer_advance_with_token(lexer_T*, token_T*);

char*
lexer_get_current_char_as_string(lexer_T*);

#endif
