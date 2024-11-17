/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 14:10:38 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-17 14:10:38 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_vec3	vec3_hadamard(t_vec3 *vec, void *param);

t_fdf	*init_fdf(char *path)
{
	t_fdf	*fdf;
	int	code;

	fdf = zeroit(malloc(sizeof(t_fdf)), sizeof(t_fdf));
	if (!fdf)
		close_sim(1, fdf);
	fdf->thickness = 2;
	fdf->default_colour = 0x000000FF;
	fdf->needs_project = 1;
	fdf->needs_draw = 0;
	fdf->drawsteps = 500;
	code = parse_map(path, &fdf->map, fdf->default_colour);
	if (code)
		close_sim(code, fdf);
	fdf->base_scale = (t_vec3){5, -1, 5};
	fdf->mlx = mlx_init(1920, 1080 , "F D F", 1);
	fdf->main_img = mlx_new_image(fdf->mlx, 1920, 1080);
	mlx_image_to_window(fdf->mlx, fdf->main_img, 0, 0);
	fdf->projection = create_isometric();
	prepend_frame(fdf->projection, create_tframe(TRVEC3X, vec3_hadamard, &fdf->base_scale, 0));
	append_frame(fdf->projection, create_tframe(TRVEC2X, vec2_add, &fdf->auto_center, 0));
	return (fdf);
}

