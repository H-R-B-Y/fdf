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
	if (master->pre_img)
		mlx_delete_image(master->mlx, master->pre_img);
	// if (master->map)
	// 	destroy_map(master->map);
	// if (master->projection)
	// 	destroy_projection(master->projection);
	if (master->mlx)
		mlx_terminate(master->mlx);
	free(master);
	exit(code);
}

void	main_key_hook(mlx_key_data_t *data, void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (data->key == MLX_KEY_ESCAPE && data->action == MLX_RELEASE && !data->modifier)
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
	fdf->projection = create_isometric();
	project(fdf->map, fdf->projection);
	return (0);
}
