/* main.c -- gum project
 * author - vooop binary 
 * licence - GPL licence */

#include <stdio.h>
#include "include/lexer.h"
#include "include/token.h"
#include "include/parser.h"
#include "include/visitor.h"

int
main(int argv, char* argc[])
{
    lexer_T* lexer = init_lexer(
        "let name = \"Hello ,World\";\n"
        "let jk = \"JK :D\";\n "
        "format(jk);"
        "format(name);\n"
    );

    parser_T* parser = init_parser(lexer);
    AST_T* root = parser_parse(parser);
    visitor_T* visitor = init_visitor();

    visitor_visit(visitor, root);

    return 0; 
}
