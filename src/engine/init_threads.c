/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 01:37:10 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/29 01:37:42 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "defines.h"
#include "engine.h"

int	init_threads(t_engine *engine)
{
	size_t	i;

	engine->thread_count = THREADS;
	engine->threads = malloc(engine->thread_count * sizeof(pthread_t));
	if (engine->threads == NULL)
		return (-1);
	if (pthread_mutex_init(&engine->line_mutex, NULL) != 0)
	{
		free(engine->threads);
		return (-1);
	}
	engine->current_line = 0;
	engine->stop = 0;
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
