/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hashmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 07:40:07 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/04 07:42:15 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "vector.h"

void	init_hashmap(t_hashmap *hashmap)
{
	size_t	i;

	i = 0;
	while (i < HASHMAP_SIZE)
	{
		init_vector(hashmap->map + i, sizeof(t_pair));
		++i;
	}
}
