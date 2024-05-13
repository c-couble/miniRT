/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:14:09 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/13 21:46:29 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

static char	*get_next_word(char *s, const char *delim);

char	*ft_strtok_r(char *s, const char *delim, char **saveptr)
{
	char		*rvalue;

	if (s)
	{
		*saveptr = s;
		while (**saveptr && ft_strchr(delim, **saveptr))
			++*saveptr;
		if (**saveptr == '\0')
			*saveptr = NULL;
	}
	if (*saveptr)
	{
		rvalue = *saveptr;
		*saveptr = get_next_word(*saveptr, delim);
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
