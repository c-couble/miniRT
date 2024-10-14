/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_relative_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouble <ccouble@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:04:29 by ccouble           #+#    #+#             */
/*   Updated: 2024/10/14 15:12:36 by ccouble          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_string.h"

char	*get_relative_path(const char *main_file, const char *needed_file)
{
	char	*new_file;
	size_t	len;
	size_t	needed_file_len;

	len = ft_strlen(main_file);
	while (len > 0 && main_file[len] != '/')
		--len;
	if (len == 0)
		return (NULL);
	needed_file_len = ft_strlen(needed_file);
	++len;
	new_file = malloc((len + needed_file_len + 1) * sizeof(char));
	if (new_file == NULL)
		return (NULL);
	ft_strncpy(new_file, main_file, len);
	ft_strncpy(new_file + len, needed_file, needed_file_len);
	new_file[len + needed_file_len] = '\0';
	return (new_file);
}
