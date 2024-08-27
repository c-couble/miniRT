/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:41:34 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/27 02:45:33 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	const size_t	slen = ft_strlen(s);
	size_t			i;
	char			*str;

	i = 0;
	if (start >= slen)
		return (ft_calloc(1, sizeof(char)));
	while (s[i + (size_t)start] && i < len)
		++i;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s + (size_t)start, i);
	str[i] = '\0';
	return (str);
}
