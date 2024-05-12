/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_hashmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 04:51:28 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/03 04:54:32 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"
#include "vector.h"

void	destroy_hashmap(t_hashmap *hashmap)
{
	size_t	i;

	i = 0;
	while (i < HASHMAP_SIZE)
	{
		clear_vector(hashmap->map + i);
		++i;
	}
}
