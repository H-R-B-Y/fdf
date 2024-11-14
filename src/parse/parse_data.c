/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 21:14:15 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 21:14:15 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	delete_chunks(char **chunks);
size_t	array_len(char **chunks);

t_point	*point_str(int x, int y, char *str)
{
	t_point	*output;
	char *post;

	output = zeroit(malloc(sizeof(t_point)), sizeof(t_point));
	post = ft_strchr(str, ',');
	if (post)
	{
		*post = '\0';
		post = post + 1;
	}
	output->origin = (t_vec3){.x = x, .y = y,
		.z = ft_atoi(str)};
	output->output = (t_vec2){0, 0};
	output->colour = 0; // need to convert str to uint32 thingy here
	return (output);
}

/*
Loop through lines.
*/
t_point	***generate_point_matrix(t_list *lines)
{
	int		y;
	int		x;
	char	**chunks;
	t_point	***matrix;

	y = 0;
	matrix = zeroit(malloc(sizeof(t_point **) * ft_lstsize(lines)),
		sizeof(t_point **) * ft_lstsize(lines));
	while (lines)
	{
		x = 0;
		chunks = ft_split(lines->content, ' ');
		matrix[y] = zeroit(malloc(sizeof(t_point *) * array_len(chunks)),
			sizeof(t_point *) * array_len(chunks));
		while (chunks[x])
		{
			matrix[y][x] = point_str(x, y, chunks[x]);
			x++;
		}
		lines = lines->next;
		y++;
	}
	return (matrix);
}

t_line	*new_line(t_point *start, t_point *end)
{
	t_line *output;

	output = malloc(sizeof(t_line));
	if (!output)
		return (0);
	output->start = start;
	output->startv = &start->output;
	output->end = end;
	output->endv = &end->output;
	return (output);
}

t_line	**generate_line_array(t_map *map)
{
	int		x;
	int		y;
	t_line	**arr;
	int		i;

	y = 0;
	i = 0;
	arr = malloc(sizeof(t_line *) * (((map->size.x - 1) * map->size.x)
			 + ((map->size.y - 1) * map->size.y)));
	if (!arr)
		return (0);
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			if (x + 1 != map->size.x)
				arr[i++] = new_line(map->matrix[y][x], map->matrix[y][x+1]);
			if (y + 1 != map->size.y)
				arr[i++] = new_line(map->matrix[y][x], map->matrix[y+1][x]);
			x++;
		}
		y++;
	}
	return (arr);
}