/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:51:24 by ccouble           #+#    #+#             */
/*   Updated: 2024/02/28 01:09:03 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	init_vector(t_vector *this, size_t elemsize)
{
	this->elemsize = elemsize;
	this->allocated = 0;
	this->size = 0;
	this->array = NULL;
}
