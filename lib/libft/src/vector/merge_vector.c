/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:40:12 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/13 07:29:52 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_mem.h"
#include <unistd.h>

int	merge_vector(t_vector *to, t_vector *from, size_t i)
{
	while (to->size + from->size >= to->allocated)
	{
		set_alloc_size(to, from->size);
		if (reallocate_vector(to))
			return (-1);
	}
	ft_memmove(to->array + ((i + from->size) * to->elemsize),
		to->array + i * to->elemsize,
		(to->size - i) * to->elemsize);
	ft_memcpy(to->array + i * to->elemsize, from->array,
		from->size * from->elemsize);
	to->size += from->size;
	return (0);
}
