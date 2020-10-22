/* main.c -- gum project
 * author - vooop binary 
 * licence - GPL licence */

#include <stdio.h>
#include "include/lexer.h"
#include "include/token.h"
#include "include/parser.h"

int
main(int argv, char* argc[])
{
    lexer_T* lexer = init_lexer(
        "let name = \"John Doe\";\n"
        "format(name);\n"
    );

    parser_T* parser = init_parser(lexer);
    AST_T* root = parser_parse(parser);

    printf("%d\n", root->type);
    printf("%ld\n", root->compound_size);

    return 0; 
}
