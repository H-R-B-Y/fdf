/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 16:24:23 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-17 16:24:23 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_reproject(t_fdf *fdf)
{
	if (!fdf)
		return ;
	fdf->project_index = (t_vec2){0,0};
	fdf->needs_project = 1;
}

void	set_retranslate(t_fdf *fdf)
{
	if (!fdf)
		return ;
	fdf->translate_index = (t_vec2){0,0};
	fdf->needs_translate = 1;
}

void	set_redraw(t_fdf *fdf)
{
	if (!fdf)
		return ;
	swap_imgs(fdf);
	fdf->index = 0;
	fdf->needs_draw = 1;
}

void	set_drawsteps(t_fdf *fdf, int v)
{
	if (!fdf || v < 0)
		return ;
	fdf->drawsteps = v;
}