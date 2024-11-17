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

t_point	*point_str(int x, int y, char *str, uint32_t default_colour)
{
	t_point	*output;
	char	*post;

	output = zeroit(malloc(sizeof(t_point)), sizeof(t_point));
	post = ft_strchr(str, ',');
	if (post)
	{
		*post = '\0';
		post = post + 1;
	}
	output->origin = (t_vec3){.x = x, .z = y,
		.y = ft_atoi(str)};
	output->output = (t_vec2){0, 0};
	if (!post)
		output->colour = default_colour;
	else
		output->colour = parse_rgba_str(post);
	return (output);
}

/*
Loop through lines.
*/
t_point	***generate_point_matrix(t_list *lines, uint32_t default_colour)
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
			matrix[y][x] = point_str(x, y, chunks[x], default_colour);
			x++;
		}
		delete_chunks(chunks);
		lines = lines->next;
		y++;
	}
	return (matrix);
}

t_line	*new_line(t_point *start, t_point *end)
{
	t_line	*output;

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
	t_vec3	i;
	t_line	**arr;

	i = (t_vec3){0, 0, 0};
	map->ln_count = (((map->size.x - 1) * map->size.y)
			+ ((map->size.y - 1) * map->size.x));
	arr = malloc(sizeof(t_line *) * map->ln_count);
	if (!arr)
		return (0);
	while (i.y < map->size.y)
	{
		i.x = 0;
		while (i.x < map->size.x)
		{
			if (i.x + 1 != map->size.x)
				arr[(int)i.z++] = new_line(map->matrix[(int)i.y][(int)i.x],
						map->matrix[(int)i.y][(int)i.x + 1]);
			if (i.y + 1 != map->size.y)
				arr[(int)i.z++] = new_line(map->matrix[(int)i.y][(int)i.x],
						map->matrix[(int)i.y + 1][(int)i.x]);
			i.x++;
		}
		i.y++;
	}
	return (arr);
}
