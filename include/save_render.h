/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_render.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:31:39 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 10:55:03 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_RENDER_H
# define SAVE_RENDER_H

# include "object/optional_data.h"

struct s_engine;

int	parse_save_render(struct s_engine *engine, t_option *data, char *arg);
int	save_render_file(struct s_engine *engine);

#endif
