/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:31:06 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:31:43 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_math.h"

t_colorf	color_add_scale(t_colorf a, t_colorf b, double ratio)
{
	t_colorf	result;

	if (ratio < 0)
		return ((t_colorf){0, 0, 0});
	result.r = ft_dmin(1, a.r + b.r * ratio);
	result.g = ft_dmin(1, a.g + b.g * ratio);
	result.b = ft_dmin(1, a.b + b.b * ratio);
	return (result);
}
