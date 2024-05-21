/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:26:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/05/21 04:55:33 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mlx.h"
#include "mlx_wrapper.h"
#include <stdio.h>
#include <unistd.h>

static int	loop_hook(t_engine *engine);

int	main(int argc, char *argv[])
{
	t_engine	engine;

	if (write(STDOUT_FILENO, "miniRT\n", 7) != 7)
		return (1);
	if (argc == 1)
		return (0);
	if (init_engine(&engine, argv[1]) == -1)
		return (1);
	mlx_loop_hook(engine.mlx.mlx, loop_hook, &engine);
	mlx_loop(engine.mlx.mlx);
	clear_engine(&engine);
	return (0);
}

static int	loop_hook(t_engine *engine)
{
	printf("loop\n");
	(void) engine;
	return (0);
}
