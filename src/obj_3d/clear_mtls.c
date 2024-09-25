/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_mtls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 03:49:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/25 05:50:59 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_mtl.h"
#include "vector.h"

void	clear_mtls(t_vector *mtls)
{
	size_t		i;
	t_obj_mtl	**mtl;

	i = 0;
	while (i < mtls->size)
	{
		mtl = at_vector(mtls, i);
		clear_mtl(*mtl);
		++i;
	}
	clear_vector(mtls);
}
