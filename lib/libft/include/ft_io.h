/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 05:55:50 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/05 07:29:17 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stddef.h>
# include "get_next_line_utils.h"

typedef struct s_file
{
	size_t	length;
	char	*content;
}	t_file;

int		ft_dprintf(int fd, char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(const char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(const char *s, int fd);
int		get_file_content(t_file *file, const char *path);
char	*get_next_line(int fd);
char	*get_next_line_ptr(int fd, t_buffer *buf, const char *charset);

#endif
