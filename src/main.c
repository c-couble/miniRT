/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:26:04 by ccouble           #+#    #+#             */
/*   Updated: 2025/02/26 09:11:56 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "engine.h"
#include "mlx.h"

int	main(int argc, char *argv[])
{
	t_engine	engine;

	srand(time(NULL));
	if (write(STDOUT_FILENO, "miniRT\n", 7) != 7)
		return (1);
	if (argc == 1)
		return (0);
	if (init_engine(&engine, argv[1]) == -1)
		return (1);
	printf("finish init : obj count is %ld\n", engine.scene.objects.size);
	engine.scene.camera.should_render = 1;
	mlx_loop(engine.mlx.mlx);
	clear_engine(&engine);
	return (0);
}
