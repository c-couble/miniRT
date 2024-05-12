/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvalue_hashmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 05:26:14 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/04 12:44:25 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "vector.h"
#include "ft_string.h"
#include <stdlib.h>

int	setvalue_hashmap(t_hashmap *hashmap, char *key, char *value)
{
	const size_t	hash = hash_key(key) % HASHMAP_SIZE;
	size_t			i;
	t_pair			*existing;
	t_pair			pair;

	pair.key = key;
	pair.value = value;
	i = 0;
	while (i < hashmap->map[hash].size)
	{
		existing = at_vector(hashmap->map + hash, i);
		if (ft_strcmp(key, existing->key) == 0)
		{
			free(existing->key);
			free(existing->value);
			return (set_value_vector(hashmap->map + hash, &pair, i));
		}
		++i;
	}
	return (add_vector(hashmap->map + hash, &pair, 1));
}
