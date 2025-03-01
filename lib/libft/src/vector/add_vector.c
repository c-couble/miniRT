/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:19:23 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:30:27 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "vector.h"

int	add_vector(t_vector *this, const void *data, size_t count)
{
	size_t	currentelem;

	while (this->allocated == 0 || this->size + count >= this->allocated - 1)
	{
		set_alloc_size(this, count);
		if (reallocate_vector(this))
			return (-1);
	}
	currentelem = this->size * this->elemsize;
	ft_memcpy(this->array + currentelem, data, this->elemsize * count);
	this->size += count;
	return (0);
}
