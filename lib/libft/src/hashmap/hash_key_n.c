/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_key_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:32:30 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/12 14:52:00 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	hash_key_n(const char *key, size_t n)
{
	size_t	i;
	size_t	hash;

	hash = 5381;
	i = 0;
	while (key[i] && i < n)
	{
		hash = (hash << 5) + hash + key[i];
		++i;
	}
	return (hash);
}
