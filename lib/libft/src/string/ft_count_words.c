/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:35:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/04/02 03:21:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_string.h"

size_t	ft_count_words(const char *s, char *delim)
{
	size_t	count;

	count = 0;
	while (*s && ft_strchr(delim, *s))
		++s;
	while (*s)
	{
		++count;
		while (*s && ft_strchr(delim, *s) == NULL)
			++s;
		while (*s && ft_strchr(delim, *s))
			++s;
	}
	return (count);
}
