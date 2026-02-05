/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:29:10 by lespenel          #+#    #+#             */
/*   Updated: 2026/02/05 23:29:58 by lespenel         ###   ########.fr       */
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
