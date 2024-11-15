/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-14 21:07:35 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-14 21:07:35 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	_swap_imgs(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->main_img);
	fdf->main_img = fdf->pre_img;
	fdf->pre_img = mlx_new_image(fdf->mlx,
		fdf->mlx->width, fdf->mlx->height);
	mlx_image_to_window(fdf->mlx, fdf->main_img, 0, 0);
}

void	_draw_all(t_fdf *fdf)
{
	while (fdf->index < fdf->map->ln_count)
	{
		draw_line(fdf->map->lines[fdf->index],
			fdf->main_img, fdf->thickness);
		fdf->index++;
	}
	//_swap_imgs(fdf);
	fdf->needs_draw = 0;
}

void	_stepped_draw(t_fdf *fdf)
{
	int draw_steps;

	draw_steps = 0;
	while (fdf->index + draw_steps < fdf->map->ln_count
		&& draw_steps < fdf->drawsteps)
	{
		draw_line(fdf->map->lines[fdf->index + draw_steps],
			fdf->main_img, fdf->thickness);
		draw_steps++;
	}
	fdf->index += draw_steps;
	if (fdf->index == fdf->map->ln_count - 1)
		fdf->needs_draw = 0;
}

void	draw_loop(t_fdf *fdf)
{
	if (fdf->needs_draw)
	{
		if (fdf->drawsteps == 0)
			_draw_all(fdf);
		else
			_stepped_draw(fdf);
	}
}
