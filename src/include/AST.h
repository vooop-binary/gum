#ifndef _AST_H_
#define _AST_H_
#include <stdlib.h>

typedef struct AST_STRUCT
{
   enum
   {
       AST_VARIABLE_DEFINATION,
       AST_FUNCTION_DEFINATION,
       AST_VARIABLE,
       AST_FUNCTION_CALL,
       AST_STRING,
       AST_COMPOUND,
       AST_NULL
   } type;

   /* AST_VARIABLE_DEFINATION */
   char* variable_defination_name;
   struct AST_STRUCT* variable_defination_value;

   /* AST_FUNCTION_DEFINATION */
   struct AST_STRUCT* funtion_defination_body;

   /* AST_VARIABLE */
   char* variable_name;

   /* AST_FUNCTION_CALL */
   char* function_call_name;
   struct AST_STRUCT** function_call_arguements;
   size_t function_call_arguements_size;

   /* AST_STRING */
   char* string_value;

   /* AST_COMPOUND */
   struct AST_STRUCT** compound_value;
   size_t compound_size;

} AST_T;

AST_T*
init_ast(int);

#endif
