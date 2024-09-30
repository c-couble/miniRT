/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:26:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 17:11:22 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "engine.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	t_engine	engine;

	if (write(STDOUT_FILENO, "miniRT\n", 7) != 7)
		return (1);
	if (argc == 1)
		return (0);
	if (init_engine(&engine, argv[1]) == -1)
		return (1);
	printf("finish init : obj count is %ld\n", engine.scene.objects.size);
	render_frame(&engine);
	mlx_put_image_to_window(engine.mlx.mlx, engine.mlx.mlx_window, engine.mlx.img, 0, 0);
	mlx_loop(engine.mlx.mlx);
	clear_engine(&engine);
	return (0);
}
