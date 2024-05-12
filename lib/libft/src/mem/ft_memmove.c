/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:06:19 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/27 01:16:09 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const long int	diff = dest - src;
	size_t			i;

	if (diff > 0)
	{
		while (n > 0)
		{
			--n;
			((char *)(dest))[n] = ((char *)(src))[n];
		}
	}
	else if (diff < 0)
	{
		i = 0;
		while (i < n)
		{
			((char *)(dest))[i] = ((char *)(src))[i];
			++i;
		}
	}
	return (dest);
}
