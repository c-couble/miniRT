/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_alloc_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:01:45 by ccouble           #+#    #+#             */
/*   Updated: 2024/03/21 05:33:54 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stddef.h>

void	set_alloc_size(t_vector *this, size_t count)
{
	if (this->allocated == 0 || this->size + count >= this->allocated - 1)
	{
		if (this->allocated == 0)
			this->allocated = BASE_ALLOC;
		else
			this->allocated *= 2;
		return ;
	}
}
