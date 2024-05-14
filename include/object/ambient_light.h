#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H

# include "object/rgb.h"

typedef struct s_ambient_light
{
	double	ratio;
	t_rgb	color;
}	t_ambient_light;

union u_object_data;

int	parse_ambient_light(union u_object_data *data);

#endif
