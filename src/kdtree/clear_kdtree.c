/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_kdtree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:46:30 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/26 20:50:19 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kdtree.h"
#include <stdlib.h>

void	clear_kdtree(t_kdtree *tree)
{
	if (tree == NULL)
		return ;
	clear_kdtree(tree->left);
	clear_kdtree(tree->right);
	free(tree);
}
