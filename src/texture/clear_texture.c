/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 06:42:43 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/27 03:12:10 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "texture.h"

void	clear_texture(t_texture *texture)
{
	free(texture->file_name);
	free(texture->texture);
}
