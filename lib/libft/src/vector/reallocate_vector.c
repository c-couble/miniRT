/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocate_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:30:36 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:30:55 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mem.h"
#include "vector.h"

int	reallocate_vector(t_vector *this)
{
	size_t	elem;
	void	*ptr;

	elem = this->size * this->elemsize;
	ptr = malloc(this->allocated * this->elemsize);
	if (ptr == NULL)
		return (-1);
	ft_memcpy(ptr, this->array, elem);
	ft_memset(ptr + elem, 0, (this->allocated * this->elemsize) - elem);
	if (this->array)
		free(this->array);
	this->array = ptr;
	return (0);
}
