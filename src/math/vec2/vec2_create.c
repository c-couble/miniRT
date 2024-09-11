/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:15:46 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/11 14:20:20 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"

t_vec2	*vec2_create(double x, double y, t_vec2 *out)
{
	out->x = x;
	out->y = y;
	return (out);
}
