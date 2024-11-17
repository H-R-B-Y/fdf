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

void	swap_imgs(t_fdf *fdf)
{
	mlx_delete_image(fdf->mlx, fdf->main_img);
	fdf->main_img = mlx_new_image(fdf->mlx,
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
	swap_imgs(fdf);
	fdf->needs_draw = 0;
}

void	_stepped_draw(t_fdf *fdf)
{
	int	count;

	count = 0;
	while (fdf->index < fdf->map->ln_count)
	{
		draw_line(fdf->map->lines[fdf->index],
			fdf->main_img, fdf->thickness);
		fdf->index++;
		count++;
		if (fdf->drawsteps && count >= fdf->drawsteps)
			return ;
	}
	fdf->needs_draw = 0;
}

void	draw_loop(void *p)
{
	t_fdf	*fdf;

	fdf = p;
	if (fdf->needs_project)
		project_loop(fdf);
	else if (fdf->needs_translate)
		translate_loop(fdf);
	else if (fdf->needs_draw)
		_stepped_draw(fdf);
}
