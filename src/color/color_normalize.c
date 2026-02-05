/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:01:26 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 00:48:31 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_math.h"

t_colorf	color_add(t_colorf a, t_colorf b)
{
	t_colorf	result;

	result.r = ft_dmin(1, a.r + b.r);
	result.g = ft_dmin(1, a.g + b.g);
	result.b = ft_dmin(1, a.b + b.b);
	return (result);
}

t_colorf	color_multiply(t_colorf a, t_colorf b)
{
	t_colorf	result;

	result.r = ft_dmin(1, a.r * b.r);
	result.g = ft_dmin(1, a.g * b.g);
	result.b = ft_dmin(1, a.b * b.b);
	return (result);
}

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

t_colorf	color_normalize(t_color in)
{
	t_colorf	out;

	out.r = in.rgb.r / 255.0;
	out.g = in.rgb.g / 255.0;
	out.b = in.rgb.b / 255.0;
	return (out);
}

uint32_t	color_denormalize(t_colorf in)
{
	t_color	tmp;

	tmp.rgb.r = ft_min(in.r * 255.0, 255);
	tmp.rgb.g = ft_min(in.g * 255.0, 255);
	tmp.rgb.b = ft_min(in.b * 255.0, 255);
	return (tmp.color);
}
