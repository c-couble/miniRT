/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optional_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 05:13:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 13:25:27 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caustic.h"
#include "engine.h"
#include "ft_string.h"
#include "normal_map.h"
#include "object.h"
#include "object/optional_data.h"
#include "util.h"

static void			init_optional_data(t_option *data);
static t_option_t	get_optional_type(char *type);
static int			parse_option(t_engine *engine, t_object *object, char *arg);

int	parse_optional_data(t_engine *engine, t_object *object)
{
	char		*arg;

	init_optional_data(&object->optional_data);
	arg = ft_strtok(NULL, " \t");
	while (arg)
	{
		if (parse_option(engine, object, arg) == -1)
			return (-1);
		arg = ft_strtok(NULL, " \t");
	}
	return (0);
}

static void	init_optional_data(t_option *data)
{
	init_material(&data->material);
	data->texture = NULL;
	data->up_texture = NULL;
	data->down_texture = NULL;
	data->normal_map = NULL;
	data->up_normal_map = NULL;
	data->down_normal_map = NULL;
	data->checker.x_size = 0;
	data->checker.y_size = 0;
	data->checker.x_color.color = 0;
	data->checker.y_color.color = 0;
	data->photon_nb = 0;
}

static t_option_t	get_optional_type(char *type)
{
	static char	*values[] = {
	[MATERIAL] = "ma",
	[TEXTURE] = "tx",
	[NORMAL_MAP] = "nm",
	[CHECKERBOARD] = "ch",
	[CAUSTIC] = "ca",
	[BACKGROUND_COLOR] = "bkg",
	};
	size_t		i;

	i = 0;
	while (i < UNKNOWN_OPTION)
	{
		if (ft_strcmp(values[i], type) == 0)
			return (i);
		++i;
	}
	return (UNKNOWN_OPTION);
}

static int	parse_option(t_engine *engine, t_object *object, char *arg)
{
	static int	(*values[])(t_engine *engine, t_option *data, char *arg) = {
	[MATERIAL] = parse_material,
	[TEXTURE] = parse_texture,
	[NORMAL_MAP] = parse_normal_map,
	[CHECKERBOARD] = parse_checkerboard,
	[CAUSTIC] = parse_caustic,
	[BACKGROUND_COLOR] = parse_background_color,
	};
	t_option_t	type;
	char		*name;
	char		*save;

	name = ft_strtok_r(arg, ":", &save);
	if (name == NULL)
		return (-1);
	type = get_optional_type(name);
	if (type == UNKNOWN_OPTION)
		return (-1);
	arg = ft_strtok_r(NULL, ":", &save);
	if (arg == NULL)
		return (-1);
	return (values[type](engine, &object->optional_data, arg));
}
