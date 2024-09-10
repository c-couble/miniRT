/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optional_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 05:13:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/05 07:13:12 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "engine.h"
#include "ft_string.h"
#include "object.h"
#include "object/optional_data.h"

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
	data->material.diffuse_ratio = DIFFUSE_RATIO;
	data->material.specular_ratio = SPECULAR_RATIO;
	data->material.specular_shine = SPECULAR_SHINE;
	data->material.reflect_ratio = REFLECT_RATIO;
	data->material.refraction_ratio = 0;
	data->texture = NULL;
	data->down_texture = NULL;
	data->up_texture = NULL;
}

static t_option_t	get_optional_type(char *type)
{
	static char	*values[] = {
	[MATERIAL] = "ma",
	[TEXTURE] = "tx",
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