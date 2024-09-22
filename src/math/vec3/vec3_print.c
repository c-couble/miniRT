/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:28:03 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 17:37:59 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vec3.h"

void	vec3_print(t_vec3 *ray, char *str)
{
	dprintf(2, "%s | x: %lf, y: %lf, z: %lf\n", str,
		ray->x, ray->y, ray->z);
}
