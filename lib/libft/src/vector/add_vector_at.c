/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:47:35 by lespenel          #+#    #+#             */
/*   Updated: 2024/03/12 09:26:58 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_mem.h"

int	add_vector_at(t_vector *this, const void *new, size_t at)
{
	if (at > this->size)
		return (-1);
	if (this->size + 1 >= this->allocated)
	{
		set_alloc_size(this, 1);
		if (reallocate_vector(this))
			return (-1);
	}
	ft_memmove(this->array + (at + 1) * this->elemsize,
		this->array + at * this->elemsize,
		(this->size - at) * this->elemsize);
	ft_memcpy(this->array + (at * this->elemsize), new, this->elemsize);
	this->size += 1;
	return (0);
}
