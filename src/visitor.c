#include "include/visitor.h"
#include "include/AST.h"
#include <stdio.h>
#include <string.h>

/* built in functions */

static AST_T* 
builtin_function_format(visitor_T* visitor, AST_T** args, int args_size)
{
    for (int i = 0; i < args_size; ++i)
   {
      AST_T* visited_ast = visitor_visit(visitor, args[i]);

      switch (visited_ast->type)
      {
         case AST_STRING: printf("%s\n", visited_ast->string_value); break;
         default: printf("%p\n", visited_ast); break;
      }

   }

   return init_ast(AST_NULL);
}

visitor_T*
init_visitor()
{
   visitor_T* visitor = calloc(1, sizeof(struct VISITOR_STRUCT));
   visitor->variable_defination = (void*)0;
   visitor->variable_defination_size = 0;

   return visitor;
}

AST_T*
visitor_visit(visitor_T* visitor, AST_T* node)
{

   switch (node->type)
   {
      case AST_VARIABLE_DEFINATION: return 
                                    visitor_visit_variable_defination(visitor, 
                                          node);
                                    break;

      case AST_VARIABLE:            return 
                                    visitor_visit_variable(visitor, node);
                                    break;

      case AST_FUNCTION_CALL:       return
                                    visitor_visit_function_call(visitor, node);
                                    break;

      case AST_STRING :             return
                                    visitor_visit_string(visitor, node);
                                    break;

      case AST_COMPOUND :           return
                                    visitor_visit_compound(visitor, node);
                                    break;

      case AST_NULL :               return
                                    node;
                                    break;

   }

   printf("Uncaught statement of type  %d\n", node->type);
   exit(-1);

   return init_ast(AST_NULL);
}

AST_T*
visitor_visit_variable_defination(visitor_T* visitor, AST_T* node)
{

   if (visitor->variable_defination == (void*)0)
   {
      visitor->variable_defination = calloc(1, sizeof(struct AST_STRUCT*));
      visitor->variable_defination[0] = node;
      ++visitor->variable_defination_size;
   }
   else 
   {
      ++visitor->variable_defination_size;
      visitor->variable_defination = realloc(
            visitor->variable_defination,
            visitor->variable_defination_size * sizeof(struct AST_STRUCT*)
            );
      visitor->variable_defination[visitor->variable_defination_size-1] = node;
   }

   return node;
}

AST_T*
visitor_visit_variable(visitor_T* visitor, AST_T* node)
{
   for (int i = 0; i < visitor->variable_defination_size; ++i)
   {
      AST_T* vardef = visitor->variable_defination[i];

      if (strcmp(vardef->variable_defination_name, node->variable_name) == 0)
      {
         return visitor_visit(visitor, vardef->variable_defination_value);
      }
   }

   printf("Undefined Variable `%s`\n", node->function_call_name);

   return node;
}

AST_T*
visitor_visit_function_call(visitor_T* visitor, AST_T* node)
{
   if (strcmp(node->function_call_name, "format") == 0)
   {
      return builtin_function_format(
         visitor,
         node->function_call_arguements,
         node->function_call_arguements_size
      );
   }
   else
   {
      printf("undefined function `%s`\n", node->function_call_name);
      exit(1);
   }
}

AST_T*
visitor_visit_string(visitor_T* visitor, AST_T* node)
{
   return node;
}

AST_T*
visitor_visit_compound(visitor_T* visitor, AST_T* node)
{
   for (int i = 0; i < node->compound_size; ++i)
   {
      visitor_visit(visitor, node->compound_value[i]);
   }

   return init_ast(AST_NULL);
}
