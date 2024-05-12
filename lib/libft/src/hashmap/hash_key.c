/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxperei <maxperei@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:32:30 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/04 09:24:32 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	hash_key(const char *key)
{
	size_t	hash;

	hash = 5381;
	while (*key)
	{
		hash = (hash << 5) + hash + *key;
		++key;
	}
	return (hash);
}
