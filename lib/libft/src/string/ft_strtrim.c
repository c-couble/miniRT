/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:05:21 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/27 02:44:30 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	char	*str;

	while (ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	if (i == 0)
		return (ft_calloc(1, sizeof(char)));
	--i;
	while (ft_strchr(set, s1[i]))
		--i;
	str = malloc((i + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, i + 1);
	str[i + 1] = '\0';
	return (str);
}
