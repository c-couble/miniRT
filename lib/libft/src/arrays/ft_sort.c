/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:11:40 by ccouble           #+#    #+#             */
/*   Updated: 2023/12/26 02:33:41 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_util.h"

void	ft_sort(int *tab, size_t len)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < len)
	{
		j = i;
		while (j > 0 && tab[j - 1] > tab[j])
		{
			ft_swap(tab + j, tab + (j - 1));
			j--;
		}
		i++;
	}
}
