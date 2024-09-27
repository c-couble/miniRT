/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 07:51:39 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 03:12:46 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "vector.h"
#include <stdlib.h>

void	clear_textures(t_vector *textures)
{
	size_t		i;
	t_texture	**texture;

	i = 0;
	while (i < textures->size)
	{
		texture = at_vector(textures, i);
		clear_texture(*texture);
		free(*texture);
		++i;
	}
	clear_vector(textures);
}
