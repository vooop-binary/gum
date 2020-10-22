/* main.c -- gum project
 * author - vooop binary 
 * licence - GPL licence */

#include <stdio.h>
#include "include/gum_lexer.h"
#include "include/token.h"

int
main(int argv, char* argc[])
{
    lexer_T* lexer = init_lexer(
        "let name = \"John Doe\";\n"
        "format(name);\n"
    );

    token_T* token = (void*)0;

    while ((token = lexer_get_next_token(lexer)) != (void*)0)
    {
        printf("TOKEN(%d, %s)\n", token->type, token->value);
    }

    return 0; 
}
