/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scale_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 05:19:54 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/03 05:21:01 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_math.h"

uint32_t	add_scale_color(t_color *c1, t_color *c2, double ratio)
{
	t_color	result;

	if (ratio < 0)
		return (0);
	result.rgb.r = ft_dmin(255, c1->rgb.r + c2->rgb.r * ratio);
	result.rgb.g = ft_dmin(255, c1->rgb.g + c2->rgb.g * ratio);
	result.rgb.b = ft_dmin(255, c1->rgb.b + c2->rgb.b * ratio);
	return (result.color);
}
