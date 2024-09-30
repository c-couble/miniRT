/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:20:07 by ccouble           #+#    #+#             */
/*   Updated: 2024/09/30 09:23:39 by lespenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTIL_H
# define PARSE_UTIL_H

# include <stdint.h>

int	parse_double(double *data, const char *nptr, double min, double max);
int	parse_int(int *data, const char *nptr, double min, double max);
int	parse_uint8t(uint8_t *data, char *nptr);

#endif
