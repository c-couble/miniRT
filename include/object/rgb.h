#ifndef RGB_H
# define RGB_H

# include <stdint.h>

typedef struct s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

int	parse_rgb(t_rgb *rgb);

#endif
