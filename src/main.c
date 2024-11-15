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

t_vec2	vec2_default_translate(t_vec2 *vec, void *param);
t_vec3	vec3_change_scale(t_vec3 *vec, void *param);

void	close_sim(int code, t_fdf *master)
{
	if (!master)
		exit(code);
	if (master->main_img)
		mlx_delete_image(master->mlx, master->main_img);
	if (master->pre_img)
		mlx_delete_image(master->mlx, master->pre_img);
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
	t_fdf *fdf;

	fdf = param;
	if (data.key == MLX_KEY_ESCAPE && data.action == MLX_RELEASE && !data.modifier)
	{
		if (fdf->mlx)
			mlx_close_window(fdf->mlx);
		else
			close_sim(0, fdf);
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		code;

	if (argc < 1)
		return (1);
	fdf = zeroit(malloc(sizeof(t_fdf)), sizeof(t_fdf));
	if (!fdf)
		exit (1);
	code = parse_map(argv[1], &fdf->map);
	if (code)
		close_sim(code, fdf);
	fdf->mlx = mlx_init(1920, 1080 , "F D F", 0);
	fdf->main_img = mlx_new_image(fdf->mlx, 1920, 1080);
	mlx_image_to_window(fdf->mlx, fdf->main_img, 0, 0);
	fdf->pre_img = mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->projection = create_isometric();
	t_vec2 *offset = malloc(sizeof(t_vec2));
	float *scale = malloc(sizeof(float));
	*scale = 50.0f;
	offset->x = fdf->mlx->width/3;
	offset->y = fdf->mlx->height/3;
	t_vec3 *scale2 = malloc(sizeof(t_vec3));
	*scale2 = (t_vec3){1, -0.2, 1};
	prepend_frame(fdf->projection, create_tframe(TRVEC3X, vec3_change_scale, scale, 1));
	append_frame(fdf->projection, create_tframe(TRVEC2X, vec2_default_translate, offset, 1));
	prepend_frame(fdf->projection, create_tframe(	TRVEC3X, vec3_hadamard, scale2, 1));
	project(fdf->map, fdf->projection);
	mlx_key_hook(fdf->mlx, main_key_hook, fdf);
	// Draw loop goes here.
	fdf->thickness = 2;
	fdf->needs_draw = 1;
	draw_loop(fdf);
	mlx_loop(fdf->mlx);
	close_sim(0, fdf);
}
