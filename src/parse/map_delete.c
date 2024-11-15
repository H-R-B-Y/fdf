/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 16:36:01 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-15 16:36:01 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	delete_matrix(t_point ***matrix, t_vec2 size)
{
	t_vec2	iter;

	iter = (t_vec2){0, 0};
	while (iter.y < size.y)
	{
		iter.x = 0;
		while (iter.x < size.x)
		{
			free(matrix[(int)iter.y][(int)iter.x]);
			iter.x++;
		}
		free(matrix[(int)iter.y]);
		iter.y++;
	}
	free(matrix);
}

void	delete_lines(t_line **lines, size_t ln_count)
{
	size_t i;

	i = 0;
	while (i < ln_count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	destroy_map(t_map **map)
{
	ft_lstclear(&(*map)->proto, free);
	delete_matrix((*map)->matrix, (*map)->size);
	delete_lines((*map)->lines, (*map)->ln_count);
	free(*map);
	*map = 0;
}
