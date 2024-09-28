/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:59:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/28 02:35:16 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bvh.h"
#include "object.h"

void	print_node(t_bvh_node *n, t_vector *objs, char *str)
{
	t_object	*obj;
	int			i;
	int			j;

	i = n->start;
	j = n->start + n->size;
	printf("%s: \n", str);
	printf("node.start = %d\n", n->start);
	printf("node.size = %d\n", n->size);
	printf("start + size = %d\n", j);
	print_aabb(&n->aabb, str);
	while (i < j)
	{
		obj = at_vector(objs, i);
		print_aabb(&obj->aabb, "abb");
		++i;
	}
}

void	print_node2(t_bvh_node *n, t_cached_triangle *tri, char *str)
{
	int			i;
	int			j;

	i = n->start;
	j = n->start + n->size;
	printf("%s: \n", str);
	printf("node.start = %d\n", n->start);
	printf("node.size = %d\n", n->size);
	printf("start + size = %d\n", j);
	print_aabb(&n->aabb, str);
	while (i < j)
	{
		print_aabb(&tri[i].aabb, "abb");
		++i;
	}
}
