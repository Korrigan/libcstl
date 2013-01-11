/*
** tpl_list.h for test in /home/korrigan/dev/piscine-tek2/template_c
** 
** Made by Matthieu Rosinski
** Login   <korrigan@epitech.net>
** 
** Started on  Fri Jan 11 17:51:20 2013 Matthieu Rosinski
** Last update Fri Jan 11 23:54:19 2013 Matthieu Rosinski
*/

#include <stdlib.h>
#include <stdio.h>

#ifndef TPL_LIST_H_
# define TPL_LIST_H_

// Get the type of the list from the type of the data
# define list_type(type)			\
  struct {					\
    void *next;					\
    void *prev;					\
    type data;					\
  }

// list_type(type) *list_next(list_type(type) *list)
# define list_next(type, list) ((list_type(type) *)list->next)

// list_type(type) *list_prev(list_type(type) *list)
# define list_prev(type, list) ((list_type(type) *)list->prev)

# define list_push_back_exec(type, list, elm)		\
  {							\
    list_type(type) *it = *(list);			\
    list_type(type) *node = NULL;			\
    int ret = 1;					\
							\
    if (!(node = malloc(sizeof(list_type(type))))) {	\
      ret = 0;						\
    }							\
    else {						\
      node->data = (elm);				\
      node->next = NULL;				\
      node->next = NULL;				\
      if (*(list)) {					\
	while (it->next) {				\
	  it = it->next;				\
	}						\
	it->next = node;				\
	node->prev = it;				\
      } else {						\
	*(list) = node;					\
      }							\
    }							\
    ret;						\
  }

# define list_push_front_exec(type, list, elm)		\
  {							\
    list_type(type) *node = NULL;			\
    int ret = 1;					\
							\
    if (!(node = malloc(sizeof(list_type(type))))) {	\
      ret = 0;						\
    }							\
    else {						\
      node->data = (elm);				\
      node->next = NULL;				\
      node->prev = NULL;				\
      if (*(list)) {					\
	node->next = *(list);				\
	if ((*(list))->prev)				\
	  node->prev = (*(list))->prev;			\
	(*(list))->prev = node;				\
	*(list) = node;					\
      } else {						\
	*(list) = node;					\
      }							\
    }							\
    ret;						\
  }

# define list_pop_back_exec(type, list)		\
  {						\
    list_type(type) *it = *(list);		\
    type ret;					\
						\
    while (it->next) {				\
      it = it->next;				\
    }						\
    if (it->prev)				\
      list_prev(type, it)->next = NULL;		\
    if (it == *(list))				\
      *(list) = NULL;				\
    ret = it->data;				\
    free(it);					\
    ret;					\
  }

# define list_pop_front_exec(type, list)	\
  {						\
    list_type(type) *ret = NULL;		\
    type data;					\
						\
    ret = *(list);				\
    *(list) = (*(list))->next;			\
    if (*(list))				\
      (*(list))->prev = NULL;			\
    data = ret->data;				\
    free(ret);					\
    data;					\
  }

# define list_size_exec(type, list)		\
  {						\
    int i = 0;					\
    list_type(type) *it = list;			\
						\
    for (i = 0; it; ++i)			\
      it = it->next;				\
    i;						\
  }

// int list_push_back(list_type(type) **list, type elm)
# define list_push_back(type, list, elm) ((list_push_back_exec(type, list, elm)))

// int list_push_front(list_type(type) **list, type elm)
# define list_push_front(type, list, elm) ((list_push_front_exec(type, list, elm)))

// type list_pop_back(list_type(type) **list)
# define list_pop_back(type, list) ((list_pop_back_exec(type, list)))

// type list_pop_front(list_type(type) **list)
# define list_pop_front(type, list) ((list_pop_front_exec(type, list)))

// int list_empty(list_type(type) *list)
# define list_empty(type, list) (!(list_size_exec(type, list)))

// int list_size(list_type(type) *list)
# define list_size(type, list) ((list_size_exec(type, list)))

// void list_foreach(list_type(type) *list, void (*fct)(type data))
# define list_foreach(type, list, fct)		\
  do {						\
    list_type(type) *it = list;			\
						\
    while (it) {				\
      (fct)(it->data);				\
      it = it->next;				\
    }						\
  }						\
  while (0)

// void list_reverse(list_type(type) **list)
// WARNING: list MUST point to the first elem of the list
# define list_reverse(type, list)		\
  do {						\
    list_type(type) *it = *(list);		\
    list_type(type) *tmp = NULL;		\
		    				\
    if (*(list))				\
      do {					\
	tmp = it->next;				\
	it->next = it->prev;			\
	it->prev = tmp;				\
	*(list) = it;				\
	it = tmp;				\
      } while (it);				\
  } while (0)

// void list_delete(list_type(type) **list)
# define list_delete(type, list)		\
  do {						\
    while (!list_empty(type, *(list))) {	\
      list_pop_front(type, list);		\
    }						\
  }						\
  while (0)

#endif

