/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_vector_from_end.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 06:08:05 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/31 06:18:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ft_mem.h"

void	remove_vector_from_end(t_vector *this, size_t count)
{
	void	*rmptr;

	this->size -= count;
	rmptr = this->array + (this->size * this->elemsize);
	ft_memset(rmptr, 0, this->elemsize);
}
