/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:14:09 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/21 07:39:51 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

static char	*get_next_word(char *s, const char *delim);

char	*ft_strtok(char *s, const char *delim)
{
	static char	*str = NULL;
	char		*rvalue;

	if (s)
	{
		str = s;
		while (*str && ft_strchr(delim, *str))
			++str;
		if (*str == '\0')
			str = NULL;
	}
	if (str)
	{
		rvalue = str;
		str = get_next_word(str, delim);
		return (rvalue);
	}
	return (NULL);
}

static char	*get_next_word(char *s, const char *delim)
{
	while (*s && ft_strchr(delim, *s) == NULL)
		++s;
	while (*s && ft_strchr(delim, *s))
	{
		*s = '\0';
		++s;
	}
	if (*s == '\0')
		s = NULL;
	return (s);
}
