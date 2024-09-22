/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 02:34:35 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/03 03:15:37 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_math.h"

uint32_t	scale_color(t_color *c1, double ratio)
{
	t_color	result;

	if (ratio < 0)
		return (0);
	result.rgb.r = ft_dmin(255, c1->rgb.r * ratio);
	result.rgb.g = ft_dmin(255, c1->rgb.g * ratio);
	result.rgb.b = ft_dmin(255, c1->rgb.b * ratio);
	return (result.color);
}
