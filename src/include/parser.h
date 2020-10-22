#ifndef _PARSER_H_
#define _PARSER_H_

#include "AST.h"
#include "lexer.h"

typedef struct PARSER_STRUCT
{
   lexer_T* lexer;
   token_T* current_token;
   token_T* prev_token;

} parser_T;

parser_T*
init_parser(lexer_T*);

parser_T*
parser_eat(parser_T*, int);

AST_T*
parser_parse(parser_T*);

AST_T*
parser_parse_statement(parser_T*);

AST_T*
parser_parse_statements(parser_T*);

AST_T*
parser_parse_expr(parser_T*);

AST_T*
parser_parse_factor(parser_T*);

AST_T*
parser_parse_term(parser_T*);

AST_T*
parser_parse_function_call(parser_T*);

AST_T*
parser_parse_variable_defination(parser_T*);

AST_T*
parser_parse_variable(parser_T*);

AST_T*
parser_parse_string(parser_T*);

AST_T*
parser_parse_id(parser_T*);

#endif
