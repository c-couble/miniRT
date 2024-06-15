/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:20:33 by lespenel          #+#    #+#             */
/*   Updated: 2024/05/22 03:17:14 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H

# include "color.h"
# include <stddef.h>

typedef struct s_mlx
{
	void	*img;
	void	*mlx;
	void	*mlx_window;
	t_color	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	size_t	height;
	size_t	width;
}	t_mlx;

int		init_mlx_struct(t_mlx *mlx);
void	clear_mlx_struct(t_mlx *mlx);

#endif
