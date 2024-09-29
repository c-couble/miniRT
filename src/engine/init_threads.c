/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 01:37:10 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/29 06:36:30 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "defines.h"
#include "engine.h"

static int	prepare_threads(t_engine *engine);

int	init_threads(t_engine *engine)
{
	size_t	i;

	if (prepare_threads(engine) == -1)
		return (-1);
	i = 0;
	pthread_mutex_lock(&engine->line_mutex);
	while (i < engine->thread_count)
	{
		if (pthread_create(engine->threads + i, NULL, routine, engine) != 0)
		{
			clear_threads(engine, i);
			return (-1);
		}
		++i;
	}
	return (0);
}

static int	prepare_threads(t_engine *engine)
{
	engine->thread_count = THREADS;
	engine->threads = malloc(engine->thread_count * sizeof(pthread_t));
	if (engine->threads == NULL)
		return (-1);
	if (pthread_mutex_init(&engine->line_mutex, NULL) != 0)
	{
		free(engine->threads);
		return (-1);
	}
	engine->current_line = engine->scene.camera.frame_height;
	engine->stop = 0;
	engine->thread_run = 0;
	return (0);
}
