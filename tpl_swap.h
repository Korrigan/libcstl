/*
** tpl_swap.h for libcstl in /home/korrigan/dev/piscine-tek2/template_c
** 
** Made by Matthieu Rosinski
** Login   <korrigan@epitech.net>
** 
** Started on  Sat Jan 12 00:56:52 2013 Matthieu Rosinski
** Last update Sat Jan 12 00:59:20 2013 Matthieu Rosinski
*/

#ifndef TPL_SWAP_H_
# define TPL_SWAP_H_

// void swap(type *a, type *b)
# define swap(type, a, b)			\
  do {						\
    type tmp = *a;				\
						\
    *a = *b;					\
    *b = tmp;					\
  } while (0)

#endif
