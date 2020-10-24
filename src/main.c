/* main.c -- gum project
 * author - vooop binary 
 * licence - GPL licence */

#include <stdio.h>
#include <stdlib.h>
#include "include/lexer.h"
#include "include/token.h"
#include "include/parser.h"
#include "include/visitor.h"
#include "include/io.h"

int
main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf(
            "no file provided\n"
            "Usage: "
            "gum <filename>\n"
        );

        exit(1);
    }

    lexer_T* lexer = init_lexer(
            read_file(argv[1])
    );

    parser_T* parser = init_parser(lexer);
    AST_T* root = parser_parse(parser);
    visitor_T* visitor = init_visitor();

    visitor_visit(visitor, root);

    return 0; 
}
