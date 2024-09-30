/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_render_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:55:10 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 10:57:22 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <fcntl.h>

int	save_render_file(t_engine *engine)
{
	int fd = open("render.ppm", O_CREAT | O_WRONLY);
	if (fd == -1)
		return (-1);
	return (0);
}
