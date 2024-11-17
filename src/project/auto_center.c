/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 16:38:24 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-17 16:38:24 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	_calc_bbox(t_fdf *fdf, t_point ***m)
{
	t_vec2	index;
	t_vec2	*p;

	index = (t_vec2){0,0};
	while (index.y < fdf->map->size.y)
	{
		index.x = 0;
		while (index.x < fdf->map->size.x)
		{
			p = &m[(int)index.y][(int)index.x]->pre_translate;
			if (p->x < fdf->bbox.x.x)
				fdf->bbox.x.x = p->x;
			else if (p->x > fdf->bbox.y.x)
				fdf->bbox.y.x = p->x;
			if (p->y < fdf->bbox.x.y)
				fdf->bbox.x.y = p->y;
			else if (p->y > fdf->bbox.y.y)
				fdf->bbox.y.y = p->y;
			index.x++;
		}
		index.y++;
	}
}

void	auto_center(t_fdf *fdf)
{
	t_vec2	sim_size;

	_calc_bbox(fdf, fdf->map->matrix);
	sim_size = (t_vec2){
		.x = fabs(fdf->bbox.y.x - fdf->bbox.x.x),
		.y = fabs(fdf->bbox.y.y - fdf->bbox.x.y)};
	// Calculate the offset to center the simulation
	fdf->auto_center = (t_vec2){
		.x = (fdf->mlx->width / 2) - (fdf->bbox.x.x + sim_size.x / 2),
		.y = (fdf->mlx->height / 2) - (fdf->bbox.x.y + sim_size.y / 2)};
}
