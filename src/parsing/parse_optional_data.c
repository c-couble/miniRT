/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optional_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 05:13:57 by ccouble           #+#    #+#             */
/*   Updated: 2024/08/27 05:20:26 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "ft_string.h"
#include "object.h"
#include "object/optional_data.h"

static void			init_optional_data(t_optional_data *data);
static t_option_t	get_optional_type(char *type);
static int			parse_option(t_object *object, t_option_t type, char *arg);

int	parse_optional_data(t_object *object)
{
	char		*arg;
	char		*name;
	char		*save;
	t_option_t	type;

	init_optional_data(&object->optional_data);
	arg = ft_strtok(NULL, " \t");
	while (arg)
	{
		name = ft_strtok_r(arg, ":", &save);
		if (name == NULL)
			return (-1);
		type = get_optional_type(name);
		if (type == UNKNOWN_OPTION)
			return (-1);
		parse_option(object, type, ft_strtok_r(NULL, ":", &save));
		arg = ft_strtok(NULL, " \t");
	}
	return (0);
}

static void	init_optional_data(t_optional_data *data)
{
	data->material.diffuse_ratio = DIFFUSE_RATIO;
	data->material.specular_ratio = SPECULAR_RATIO;
	data->material.specular_shine = SPECULAR_SHINE;
	data->material.reflect_ratio = REFLECT_RATIO;
	data->material.refraction_ratio = 0;
}

static t_option_t	get_optional_type(char *type)
{
	static char	*values[] = {
	[MATERIAL] = "ma",
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

static int	parse_option(t_object *object, t_option_t type, char *arg)
{
	static int	(*values[])(t_optional_data *data, char *arg) = {
	[MATERIAL] = parse_material,
	};

	return (values[type](&object->optional_data, arg));
}
