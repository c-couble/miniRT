/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespenel <lespenel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 04:20:33 by lespenel          #+#    #+#             */
/*   Updated: 2024/08/24 05:36:35 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H

# include "color.h"
# include "keyboard.h"
# include "vector.h"
# include <stddef.h>

typedef enum e_hooktype
{
	DESTROY,
	HOLD,
	MOUSE,
	MOUSE_MOTION,
	PRESS,
	LOOP
}	t_hooktype;

typedef struct s_hook
{
	void		(*func)(void *);
	void		*param;
	t_key		key;
	int			is_down;
	t_hooktype	type;
}	t_hook;

typedef struct s_mlx
{
	void		*img;
	void		*mlx;
	void		*mlx_window;
	t_color		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	size_t		height;
	size_t		width;
	t_vector	hooks;
	int			x;
	int			y;
	int			old_x;
	int			old_y;
	int			focused;
}	t_mlx;

int		init_mlx_struct(t_mlx *mlx);
void	clear_mlx_struct(t_mlx *mlx);
t_hook	create_mlx_hook(void (*f)(), void *param, t_key key, t_hooktype type);

int		key_down_hook(int key, t_mlx *mlx);
int		key_up_hook(int key, t_mlx *mlx);
int		loop_hook(t_mlx *mlx);
int		mouse_down_hook(int key, int x, int y, t_mlx *mlx);
int		mouse_up_hook(int key, int x, int y, t_mlx *mlx);
int		mouse_motion_hook(int x, int y, t_mlx *mlx);
int		focus_in_hook(t_mlx *mlx);
int		focus_out_hook(t_mlx *mlx);
int		destroy_hook(t_mlx *mlx);

#endif
