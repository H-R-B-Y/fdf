/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 20:02:15 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 20:02:15 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		file_readable(char *path);
t_list	*read_lines(int fd);
int		validate_map(t_list *map);
t_point	***generate_point_matrix(t_list *lines);
t_line	**generate_line_array(t_map *map);

int		parse_map(char *path, t_map **output)
{
	t_list	*lines;
	int		fd;

	lines = 0;
	fd = file_readable(path);
	// Check file is readable
	if (fd < 3)
		return (1);
	// read lines into linked list?
	lines = read_lines(fd);
	close(fd);
	// Validate map (remember 2 map types)
	fd = validate_map(lines);
	*output = zeroit(malloc(sizeof(t_map)), sizeof(t_map));
	if (!fd || !*output)
		return (2);
	(*output)->proto = lines;
	(*output)->size = (t_vec2){.x = fd,
		.y = ft_lstsize(lines)};
	// Convert map to points (remember 2 map types)
	(*output)->matrix = generate_point_matrix(lines);
	// Calculate the lines
	(*output)->lines = generate_line_array((*output));
	return (0);
}
