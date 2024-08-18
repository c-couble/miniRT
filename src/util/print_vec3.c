/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vec3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:28:03 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/18 14:27:43 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <stdio.h>

void print_vec3(t_vec3 *ray, char *str)
{
	dprintf(2, "%s x =%lf, y = %lf, z = %lf\n", str,
		ray->x, ray->y, ray->z);
}
