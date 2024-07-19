/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 07:53:27 by ccouble           #+#    #+#             */
/*   Updated: 2024/06/24 07:58:43 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"
#include <stddef.h>
#include <stdio.h>

void	mat4_print(t_mat4 *mat)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (i % 4 == 0 && i != 0)
			printf("\n");
		printf("%lf ", mat->matrix[i]);
		++i;
	}
	printf("\n");
}
