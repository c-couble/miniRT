/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 02:30:04 by lespenel          #+#    #+#             */
/*   Updated: 2024/07/03 04:42:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_math.h"

uint32_t	add_color(t_color *c1, t_color *c2)
{
	t_color	result;

	result.rgb.r = ft_dmin(255, c1->rgb.r + c2->rgb.r);
	result.rgb.g = ft_dmin(255, c1->rgb.g + c2->rgb.g);
	result.rgb.b = ft_dmin(255, c1->rgb.b + c2->rgb.b);
	return (result.color);
}
