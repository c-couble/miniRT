/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:51:28 by lespenel          #+#    #+#             */
/*   Updated: 2024/09/17 17:47:38 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "object.h"

void	print_objs(t_vector *objs)
{
	size_t		i;
	t_object	*obj;

	i = 0;
	printf("print obj, size = %ld\n", objs->size);
	while (i < objs->size)
	{
		obj = at_vector(objs, i);
		printf("obj nb: %ld | type = %d\n", i, obj->type);
		++i;
	}
}
