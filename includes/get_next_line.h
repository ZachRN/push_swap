/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:28:44 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:28:46 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# define FD_TOTAL 2048

typedef struct s_filehold
{
	char	*all_fd[FD_TOTAL];
	char	buf[BUFFER_SIZE + 1];
}				t_filehold;

int		get_next_line(int fd, char **line);

#endif