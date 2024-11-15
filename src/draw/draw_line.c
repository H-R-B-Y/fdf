/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-14 20:52:01 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-14 20:52:01 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	_draw_point(mlx_image_t *img,
			t_vec2 center, float thickness,
			uint32_t colour)
{
	int	radius = thickness / 2;
	int	dx[2];

	dx[0] = -radius;
	while (dx[0] <= radius)
	{
		dx[1] = -radius;
		while(dx[1] <= radius)
		{
			dx[1]++;
			if ((dx[0] * dx[0]) + (dx[1] * dx[1]) <= radius * radius)
				if ((center.x + dx[0]) < img->width && (center.y + dx[1]) < img->height
					&& (center.x + dx[0]) > 0 && (center.y + dx[1]) > 0)
					mlx_put_pixel(img, (center.x + dx[0]), (center.y + dx[1]), colour);
		}
		dx[0]++;
	}
}

void	draw_ln_point(mlx_image_t *img,
	t_vec2 pt,
	float thickness)
{
	uint32_t	colour;

	colour = 0x000000FF;
	_draw_point(img, pt, thickness, colour);
}

void	draw_line(t_line *ln,
		mlx_image_t *img,
		float thickness)
{
	t_vec2	d;
	t_vec2	s;
	double err;
	double e2;
	t_vec2	start;
	
	(void)thickness;
	start = *ln->startv;
	d = (t_vec2){fabs(ln->endv->x - ln->startv->x), fabs(ln->endv->y - ln->startv->y)};
	s = (t_vec2){(ln->startv->x < ln->endv->x) ? 1 : -1, (ln->startv->y < ln->endv->y) ? 1 : -1};
	err = d.x - d.y;
	while (1) {
		if (fabs(start.x - ln->endv->x) < 1 && fabs(start.y - ln->endv->y) < 1)
			break;
		if (start.x < img->width && start.y < img->height
			&& start.x >= 1 && start.y >= 1)
			draw_ln_point(img, start, thickness);
		e2 = 2 * err;
		err -= (d.y * (e2 > -d.y));
		start.x += (s.x * (e2 > -d.y));
		err += (d.x * (e2 < d.x));
		start.y += (s.y * (e2 < d.x));
	}
}
