/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:50:03 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/27 02:48:29 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dst[dest_len] && dest_len < size)
		++dest_len;
	while (src[src_len])
		++src_len;
	while (src[i] && dest_len + i + 1 < size)
	{
		dst[i + dest_len] = src[i];
		++i;
	}
	if (dest_len < size)
		dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
