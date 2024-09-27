/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_depth_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:02:47 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 05:10:03 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdint.h>

uint32_t	get_depth_color(int value, int max_value)
{
	const int	step = ((double)max_value / 4);
	const int	left = max_value % 4;

	if (max_value == 0)
		return (GREEN);
	if (max_value < 4)
		return (interpolate_color(GREEN, YELLOW, value, max_value));
	if (value < step)
		return (interpolate_color(GREEN, YELLOW, value, step));
	else if (value < 2 * step)
		return (interpolate_color(YELLOW, ORANGE, value - step, step));
	else if (value < 3 * step)
		return (interpolate_color(ORANGE, RED, value - (2 * step), step));
	return (interpolate_color(RED, BLUE, value - (3 * step), step + left));
}
