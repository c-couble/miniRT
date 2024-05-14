#include "ft_string.h"
#include "object/rgb.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>

static int	parse_uint8(uint8_t *n);

int	parse_rgb(t_rgb *rgb)
{
	if (parse_uint8(&rgb->r) == -1)
		return (-1);
	if (parse_uint8(&rgb->g) == -1)
		return (-1);
	if (parse_uint8(&rgb->b) == -1)
		return (-1);
	return (0);
}

static int	parse_uint8(uint8_t *data)
{
	char	*arg;
	int		n;

	arg = ft_strtok(NULL, " \t,");
	if (arg == NULL)
		return (-1);
	n = ft_atoi(arg);
	if (n < 0 || n > 255)
		return (-1);
	*data = n;
	if (errno)
		return (-1);
	return (0);
}
