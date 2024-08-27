/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:17:00 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:31:00 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "vector.h"

void	remove_vector(t_vector *this, size_t i)
{
	const size_t	rmi = i * this->elemsize;
	const size_t	sizei = (this->size) * this->elemsize;
	void			*rmptr;

	rmptr = this->array + rmi;
	ft_memmove(rmptr, rmptr + this->elemsize, sizei - rmi);
	this->size--;
}
