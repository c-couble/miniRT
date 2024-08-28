/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 05:42:26 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/28 06:43:59 by ccouble          ###   ########.fr       */
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

struct s_engine;
struct s_option;

int	parse_texture(struct s_engine *engine, struct s_option *data, char *arg);

#endif
