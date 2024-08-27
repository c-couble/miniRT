/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:24:54 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:30:33 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"

void	clear_vector(t_vector *this)
{
	if (this->array)
		free(this->array);
	this->array = NULL;
	this->allocated = 0;
	this->size = 0;
}
