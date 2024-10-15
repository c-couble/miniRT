/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_divide_nw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 01:48:19 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/14 01:54:39 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

t_vec4	*vec4_divide_nw(t_vec4 *in, double divider, t_vec4 *out)
{
	out->x = in->x / divider;
	out->y = in->y / divider;
	out->z = in->z / divider;
	return (out);
}
