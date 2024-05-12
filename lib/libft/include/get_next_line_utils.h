/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:39:50 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/27 01:44:52 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <sys/types.h>

typedef struct s_buffer
{
	char	buf[BUFFER_SIZE];
	ssize_t	start;
	ssize_t	end;
}	t_buffer;

#endif
