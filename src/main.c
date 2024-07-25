/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:26:04 by ccouble           #+#    #+#             */
/*   Updated: 2024/07/25 07:27:25 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "obj_3d.h"
#include "object.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_engine	engine;

	if (write(STDOUT_FILENO, "miniRT\n", 7) != 7)
		return (1);
	t_obj_3d	obj;
	if (parse_obj_file(&obj, "./mario_course.obj") == -1)
	{
		write(2, "Error obj\n", 10);
		return (2);
	}
	if (argc == 1)
		return (0);
	if (init_engine(&engine, argv[1]) == -1)
		return (1);
	size_t i = 0;
	while (i < engine.scene.objects.size)
	{
		t_object	*bolide = at_vector(&engine.scene.objects, i);
		if (bolide->type == MESH)
			bolide->data.mesh.obj_3d = &obj;
		++i;
	}
	printf("finish init : obj count is %ld\n", engine.scene.objects.size);
	run_loop(&engine);
	clear_engine(&engine);
	return (0);
}
