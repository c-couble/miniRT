/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:52:01 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/20 05:53:09 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
# define WINDOW_NAME	"miniRt ®ccouble ®lespenel"

# include "scene.h"

typedef struct s_engine
{
	t_scene	scene;
}	t_engine;

typedef struct s_mlx
{
	void	*img;
	void	*mlx;
	void	*mlx_window;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

int		init_mlx(t_mlx *mlx);
void	clear_mlx(t_mlx *mlx);

#endif
