/*
** tpl_queue.h for libcstl in /home/korrigan/dev/piscine-tek2/template_c
** 
** Made by Matthieu Rosinski
** Login   <korrigan@epitech.net>
** 
** Started on  Fri Jan 11 23:58:33 2013 Matthieu Rosinski
** Last update Sat Jan 12 00:03:01 2013 Matthieu Rosinski
*/

#ifndef TPL_QUEUE_H_
# define TPL_QUEUE_H_

# include "tpl_list.h"

# define queue_type(type) list_type(type)

// int queue_push(queue_type(type) **q, type elm)
# define queue_push(type, q, elm) list_push_front(type, q, elm)

// type queue_pop(queue_type(type) **q)
# define queue_pop(type, q) list_pop_back(type, q)

// void queue_delete(queue_type(type) **q)
# define queue_delete(type, q) list_delete(type, q)

#endif
