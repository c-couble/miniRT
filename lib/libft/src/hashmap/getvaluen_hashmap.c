/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvaluen_hashmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 05:32:39 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/12 14:52:41 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "vector.h"
#include "ft_string.h"

char	*getvaluen_hashmap(t_hashmap *hashmap, const char *key, size_t n)
{
	const size_t	hash = hash_key_n(key, n) % HASHMAP_SIZE;
	t_vector		*vector;
	t_pair			*pair;
	size_t			i;

	vector = hashmap->map + hash;
	i = 0;
	while (i < vector->size)
	{
		pair = at_vector(vector, i);
		if (ft_strncmp(pair->key, key, n) == 0)
			return (pair->value);
		++i;
	}
	return (NULL);
}
