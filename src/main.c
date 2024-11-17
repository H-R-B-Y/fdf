/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 16:02:30 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 16:02:30 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	close_sim(int code, t_fdf *master)
{
	if (!master)
		exit(code);
	if (master->main_img)
		mlx_delete_image(master->mlx, master->main_img);
	if (master->map)
		destroy_map(&master->map);
	if (master->projection)
		destroy_projection(&master->projection);
	if (master->mlx)
		mlx_terminate(master->mlx);
	free(master);
	exit(code);
}

void	main_key_hook(mlx_key_data_t data, void *param)
{
	t_fdf	*fdf;

	fdf = param;
	if (data.key == MLX_KEY_ESCAPE && data.action == MLX_RELEASE
		&& !data.modifier)
	{
		if (fdf->mlx)
			mlx_close_window(fdf->mlx);
		else
			close_sim(0, fdf);
	}
	if (data.key == MLX_KEY_R && data.action == MLX_RELEASE)
	{
		fdf->auto_center = (t_vec2){0, 0};
		swap_imgs(fdf);
		set_retranslate(fdf);
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		code;

	if (argc < 1)
		return (1);
	fdf = init_fdf(argv[1]);
	mlx_key_hook(fdf->mlx, main_key_hook, fdf);
	mlx_loop_hook(fdf->mlx, draw_loop, fdf);
	mlx_loop(fdf->mlx);
	close_sim(0, fdf);
}

// t_vec2 *offset = malloc(sizeof(t_vec2));
// float *scale = malloc(sizeof(float));
// *scale = 1000.0f;
// offset->x = fdf->mlx->width/2;
// offset->y = fdf->mlx->height;
// t_vec3 *scale2 = malloc(sizeof(t_vec3));
// *scale2 = (t_vec3){1, -1, 1};
// append_frame(fdf->projection, create_tframe(TRVEC3X, vec3_change_scale, scale, 1));
// prepend_frame(fdf->projection, create_tframe(TRVEC2X, vec2_default_translate, offset, 1));
// append_frame(fdf->projection, create_tframe(TRVEC3X, vec3_hadamard, scale2, 1));
