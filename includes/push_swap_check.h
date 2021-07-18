#ifndef FT_PUSH_SWAP_CHECK_H
# define FT_PUSH_SWAP_CHECK_H

# include <stdio.h>
# include <stdarg.h>
# include "get_next_line.h"
# include "libft.h"

# define ACTION_AMT 11
# define ACTION_STRLEN_MAX 4

typedef struct s_circledata
{
    int     value;
    struct s_circledata *prev;
    struct s_circledata *next;
}               t_circledata;

typedef struct s_head
{
    t_circledata *head;
}               t_head;

typedef struct s_commands
{
	char *str;
	struct s_commands *next;
}				t_commands;

// typedef struct	s_cmd_head
// {
// 	t_commands *head;
// }				t_cmd_head;

/*-------------------Linked List .c--------------------*/
t_circledata    *firstEntry(int value);
int             insertEnd(t_circledata *start, int value, int error);
void            print_list(t_circledata *start);
void            free_list(t_circledata *start);
/*-------------------Linked List .c--------------------*/

// probably obsolete;
int	ps_atoi(const char *str, int *num);
//int duplication_check(int *stack_a, int argc);
int input_numbers(int argc, char *argv[], t_head *stack_a_head);
int duplication_check_two(t_circledata *stack_a, int argc);
void	cmdprint_list(t_commands *start);
void	cmdFree_List(t_commands *start);
int cmdInsertEnd(t_commands *start, char *cmd);
int	free_action(t_circledata *stack_a, t_commands *start, char *cmd);
int action_input(t_circledata *stack_a);
// static char actions[ACTION_AMT][ACTION_STRLEN_MAX] =
// {
// 	"sa",
// 	"sb",
// 	"ss",
// 	"pa",
// 	"pb",
// 	"ra",
// 	"rb",
// 	"rr",
// 	"rra",
// 	"rrb",
// 	"rrr"
// };

//int action_check(char *str);

#endif