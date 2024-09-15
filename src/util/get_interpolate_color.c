/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_interpolate_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:29:02 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/15 10:46:30 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdint.h>

uint32_t	get_interpolate_color(uint32_t c_a, uint32_t c_b, int curr, int max)
{
	const double	min = 0;
	const double	normalized = (curr - min) / (max - min);
	t_color			interpolated;
	t_color			a;
	t_color			b;

	a.color = c_a;
	b.color = c_b;
	interpolated.rgb.r = a.rgb.r + (b.rgb.r - a.rgb.r) * normalized;
	interpolated.rgb.g = a.rgb.g + (b.rgb.g - a.rgb.g) * normalized;
	interpolated.rgb.b = a.rgb.b + (b.rgb.b - a.rgb.b) * normalized;
	return (interpolated.color);
}