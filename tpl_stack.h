/*
** tpl_stack.h for libcstl in /home/korrigan/dev/piscine-tek2/template_c
** 
** Made by Matthieu Rosinski
** Login   <korrigan@epitech.net>
** 
** Started on  Sat Jan 12 00:03:26 2013 Matthieu Rosinski
** Last update Sat Jan 12 00:05:35 2013 Matthieu Rosinski
*/

#ifndef TPL_STACK_H_
# define TPL_STACK_H_

# include "tpl_list.h"

# define stack_type(type) list_type(type)

// int stack_push(stack_type(type) **stack, type elm)
# define stack_push(type, stack, elm) list_push_front(type, stack, elm)

// type stack_pop(stack_type(type) **stack)
# define stack_pop(type, stack) list_pop_front(type, stack)

// void stack_delete(stack_type(type) **stack)
# define stack_delete(type, stack) list_delete(type, stack)

#endif
