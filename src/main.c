/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:26:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/18 02:33:52 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "mat4.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_engine	engine;
	t_mat4		mat = {{5, 6, 6, 8,
						2, 2, 2, 8,
						6, 6, 2, 8,
						2, 3, 6, 7}};

	mat4_inverse(&mat, &mat);
	if (write(STDOUT_FILENO, "miniRT\n", 7) != 7)
		return (1);
	if (argc == 1)
		return (0);
	if (init_engine(&engine, argv[1]) == -1)
		return (1);
	printf("finish init : obj count is %ld\n", engine.scene.objects.size);
	run_loop(&engine);
	clear_engine(&engine);
	return (0);
}
