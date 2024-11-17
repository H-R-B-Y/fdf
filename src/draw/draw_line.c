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
	int	radius;
	int	dx[2];

	radius = thickness / 2;
	dx[0] = -radius;
	while (dx[0] <= radius)
	{
		dx[1] = -radius;
		while (dx[1] <= radius)
		{
			dx[1]++;
			if ((dx[0] * dx[0]) + (dx[1] * dx[1]) <= radius * radius)
				if ((center.x + dx[0]) < img->width
					&& (center.y + dx[1]) < img->height
					&& (center.x + dx[0]) > 0
					&& (center.y + dx[1]) > 0)
					mlx_put_pixel(img, (center.x + dx[0]),
						(center.y + dx[1]), colour);
		}
		dx[0]++;
	}
}

void	draw_ln_point(mlx_image_t *img,
	t_vec2 pt,
	float thickness,
	t_line *ln)
{
	uint32_t	colour1;
	uint32_t	colour2;

	colour1 = ln->start->colour;
	colour2 = ln->end->colour;
	colour1 = lerp_colour(colour1, colour2,
			normalize(0, vec2_distance(ln->startv, ln->endv),
				vec2_distance(ln->startv, &pt)));
	colour1 = colour_rgba(
			rgba_get_red(colour1),
			rgba_get_green(colour1),
			rgba_get_blue(colour1),
			0xFF);
	_draw_point(img, pt, thickness, colour1);
}

t_vec2	_make_s(t_line *ln)
{
	t_vec2	v;

	v = (t_vec2){-1, -1};
	if (ln->startv->x < ln->endv->x)
		v.x = 1;
	if (ln->startv->y < ln->endv->y)
		v.y = 1;
	return (v);
}

void	draw_line(t_line *ln,
		mlx_image_t *img,
		float thickness)
{
	t_vec2	d;
	t_vec2	s;
	double	err;
	double	e2;
	t_vec2	st;

	st = *ln->startv;
	d = (t_vec2){fabs(ln->endv->x - ln->startv->x),
		fabs(ln->endv->y - ln->startv->y)};
	s = _make_s(ln);
	err = d.x - d.y;
	while (1)
	{
		if (fabs(st.x - ln->endv->x) < 1 && fabs(st.y - ln->endv->y) < 1)
			break ;
		if (st.x < img->width && st.y < img->height
			&& st.x >= 1 && st.y >= 1)
			draw_ln_point(img, st, thickness, ln);
		e2 = 2 * err;
		err -= (d.y * (e2 > -d.y));
		st.x += (s.x * (e2 > -d.y));
		err += (d.x * (e2 < d.x));
		st.y += (s.y * (e2 < d.x));
	}
}
