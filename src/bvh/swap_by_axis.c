/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_by_axis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:02:32 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 17:47:49 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object.h"
#include "util.h"

static void	swap_obj(t_object *a, t_object *b);

void	swap_by_axis(t_bvh_node *node, t_vector *objs, double pos, int axis)
{
	int			i;
	int			j;
	t_object	*obj;

	i = node->start;
	j = node->start + node->size - 1;
	while (i <= j)
	{
		obj = at_vector(objs, i);
		if (get_axis(&obj->aabb.center, axis) < pos)
			++i;
		else
		{
			swap_obj(obj, at_vector(objs, j));
			--j;
		}
	}
}

static void	swap_obj(t_object *a, t_object *b)
{
	t_object	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
