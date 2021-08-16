#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct	s_circledata
{
	int					value;
	int					radix;
	struct s_circledata *prev;
	struct s_circledata *next;
}				t_circledata;

typedef struct	s_head
{
	t_circledata	*head;
}				t_head;
/*------------------Stack Linked List-------------------*/
/*------------------stackedlinkedlist.c---------------- */
t_circledata	*firstEntry(int value);
int				insertEnd(t_circledata *start, int value);
void			free_list(t_circledata *start);
void			print_list(t_circledata *start);
/*--------------Number Input Verificatio---------------*/
/*--------numinputcheck.c && strnuminputcheck.c--------*/
int				str_ps_atoi(char *str, int *numInput, int i);
int				string_input_numbers(char *argv[], t_head *stack_a);
int				str_in_loop(char *str, int i, t_head *stack_a);
int				ps_atoi(char *str, int *numInput);
int				input_numbers(int argc, char *argv[], t_head *stack_a);
int				dupe_check_list(t_circledata *stack_a, int numinput, int *list);
int				duplication_check_two(t_circledata *stack_a);
int				total_ele(t_circledata *stack_a);
/*-------------------Action Commands--------------------*/
/*-------------actions_sr.c && actions_prr.c----------- */
void			swap(t_head *stack_head);
void			swap_both(t_head *stack_a, t_head *stack_b);
void			push(t_head *stack_take_head, t_head *stack_give_head);
void			push_empty(t_head *stack_take_head, t_circledata *current);
void			rotate(t_head *stack_head);
void			rotate_both(t_head *stack_a, t_head *stack_b);
void			reverse_rotate(t_head *stack_head);
void			reverse_rotate_both(t_head *stack_a, t_head *stack_b);
/*---------------------Radix Commands---------------------*/
/*-----------radix_sort.c && sort_value_radix.c-----------*/
void			radix_sort(t_head *stack_a, int amount);
void			rs_list(t_head *stack_a, t_head *stack_b, int maxbits, int amt);
void			bit_shift(t_head *stack_a, t_head *stack_b, int i, int num);
int				list_check(t_head *stack_a, t_head *stack_b);
void			radix_value_assign(t_head *stack_a, int amount);
void			min_do(t_circledata *cur, t_circledata *final, int max, int i);
int				find_max(t_head *stack_a);
/*-------------------Error Handling--------------------*/
/*-------------------errorhandle.c---------------------*/
int				error_call(t_circledata *stack_a);
#endif