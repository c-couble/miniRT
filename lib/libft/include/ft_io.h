/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 05:55:50 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/26 05:22:48 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include "get_next_line_utils.h"

int		ft_dprintf(int fd, char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putendl_fd(const char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(const char *s, int fd);
char	*get_next_line(int fd);
char	*get_next_line_ptr(int fd, t_buffer *buf);

#endif
