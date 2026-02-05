/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:30:41 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:31:00 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_math.h"

t_colorf	color_scale(t_colorf to_scale, double ratio)
{
	t_colorf	result;

	if (ratio < 0)
		return ((t_colorf){0, 0, 0});
	result.r = ft_dmin(1, to_scale.r * ratio);
	result.g = ft_dmin(1, to_scale.g * ratio);
	result.b = ft_dmin(1, to_scale.b * ratio);
	return (result);
}
