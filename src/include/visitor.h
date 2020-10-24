#ifndef _VISITOR_H_
#define _VISITOR_H_

#include "AST.h"
#include <stdlib.h>

typedef struct VISITOR_STRUCT
{
   AST_T** variable_defination;
   size_t variable_defination_size;
} visitor_T;

visitor_T*
init_visitor();

AST_T*
visitor_visit(visitor_T*, AST_T*);

AST_T*
visitor_visit_variable_defination(visitor_T*, AST_T*);

AST_T*
visitor_visit_variable(visitor_T*, AST_T*);

AST_T*
visitor_visit_function_call(visitor_T*, AST_T*);

AST_T*
visitor_visit_string(visitor_T*, AST_T*);

AST_T*
visitor_visit_compound(visitor_T*, AST_T*);

#endif
