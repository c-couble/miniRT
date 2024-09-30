/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:26:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 19:38:06 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "engine.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	t_engine	engine;

	if (argc == 1)
		return (0);
	if (init_engine(&engine, argv[1]) == -1)
		return (1);
	render_frame(&engine);
	mlx_put_image_to_window(engine.mlx.mlx,
		engine.mlx.mlx_window, engine.mlx.img, 0, 0);
	mlx_loop(engine.mlx.mlx);
	clear_engine(&engine);
	return (0);
}
