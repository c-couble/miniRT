/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 08:02:53 by ccouble           #+#    #+#             */
/*   Updated: 2024/04/06 08:04:12 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "vector.h"
#include "ft_string.h"

void	remove_hashmap(t_hashmap *hashmap, const char *key)
{
	const size_t	hash = hash_key(key) % HASHMAP_SIZE;
	t_vector		*vector;
	t_pair			*pair;
	size_t			i;

	vector = hashmap->map + hash;
	i = 0;
	while (i < vector->size)
	{
		pair = at_vector(vector, i);
		if (ft_strcmp(pair->key, key) == 0)
		{
			remove_vector(vector, i);
			return ;
		}
		++i;
	}
}
