/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:05:11 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/03 01:06:40 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3d.h"

double	vector_normalize(t_vector3d *vec)
{
	const double norm = vector_get_norm(vec);

	vector_divide(vec, norm);
	return (norm);
}
