/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 05:42:26 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/31 02:31:21 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <stddef.h>
# include "color.h"

typedef struct s_texture
{
	char	*file_name;
	t_color	*texture;
	size_t	width;
	size_t	height;
	int		maxval;
}	t_texture;

struct s_engine;
struct s_option;

t_texture	*parse_texture_if_needed(struct s_engine *engine, char *file);
int			parse_texture(struct s_engine *engine, struct s_option *data, char *arg);
int			parse_texture_file(t_texture *texture, char *file);

#endif
