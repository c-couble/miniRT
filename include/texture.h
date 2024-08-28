/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 05:42:26 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/28 06:03:20 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <stddef.h>
# include "color.h"

typedef struct s_texture
{
	char	*name;
	t_color	*texture;
	size_t	width;
	size_t	height;
}	t_texture;

struct s_optional_data;

int	parse_ppm_texture(struct s_optional_data *data);

#endif
