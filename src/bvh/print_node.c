/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:59:41 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/16 20:59:54 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "bvh.h"

void	print_node(t_bvh_node *n, t_vector *objs, char *str)
{
	int i = n->start;
	int j = n->start + n->size;
	t_object	*obj;
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
