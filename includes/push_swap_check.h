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

/*-------------------Linked List .c--------------------*/
t_circledata    *firstEntry(int value);
int             insertEnd(t_circledata **start, int value);
void            print_list(t_circledata **start);
void            free_list(t_circledata **start);
/*-------------------Linked List .c--------------------*/

// probably obsolete;
int	ps_atoi(const char *str, int *num);
int duplication_check(int *stack_a, int argc);
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