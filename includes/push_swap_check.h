/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_check.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:29:09 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:37:46 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECK_H
# define PUSH_SWAP_CHECK_H

# include <stdio.h>
# include <stdarg.h>
# include "get_next_line.h"
# include "libft.h"

# define ACTION_AMT 11
# define ACTION_STRLEN_MAX 4

typedef struct s_circledata
{
	int					value;
	struct s_circledata	*prev;
	struct s_circledata	*next;
}				t_circledata;

typedef struct s_head
{
	t_circledata	*head;
}				t_head;

typedef struct s_commands
{
	char				*str;
	struct s_commands	*next;
}				t_commands;

/*------------------Stack Linked List-------------------*/
/*------------------stackedlinkedlist.c---------------- */
t_circledata	*firstentry(int value);
int				insertend(t_circledata *start, int value);
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
/*------------------Action Linked List-----------------*/
/*------------------actionlinkedlist.c-----------------*/
int				cmdinsertend(t_commands *start, char *cmd);
void			cmdfree_list(t_commands *start);
void			cmdprint_list(t_commands *start);
/*--------------Action Input Verification---------------*/
/*------------------actioninputcheck.c------------------*/
int				action_input(t_circledata *stack_a, t_commands *start);
int				action_check(char *str);
/*------------------Sorting the List--------------------*/
/*---------------------sort_list.c----------------------*/
int				sort_list(t_head *stack_a, t_commands *start);
int				list_check(t_head *stack_a, t_head *stack_b);
void			action_call(t_head *stack_a, t_head *stack_b, char *action);
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
/*-------------------Error Handling--------------------*/
/*-------------------errorhandle.c---------------------*/
int				error_action(t_circledata *stack, t_commands *start, char *cmd);
int				error_call(t_circledata *stack_a);
int				ok_call(t_head *stack_a, t_commands *start);
int				ko_call(t_head *stack_a, t_head *stack_b, t_commands *start);

#endif