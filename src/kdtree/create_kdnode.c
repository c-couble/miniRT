/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_kdnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:36:24 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/25 19:14:43 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kdtree.h"
#include <stdlib.h>

int	create_kdnode(t_kdtree **node, t_photon *photon)
{
	*node = malloc(sizeof(t_kdtree));
	if (*node == NULL)
		return (-1);
	(*node)->photon = *photon;
	(*node)->left = NULL;
	(*node)->right = NULL;
	return (0);
};
