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

void	main_key_hook(mlx_key_data_t *data, void *param)
{
	(void)param;
	if (data->key == MLX_KEY_ESCAPE && data->action == MLX_RELEASE && !data->modifier)
		ft_putendl_fd("Terminate MLX here!!", 1);
}


int main(int argc, char **argv)
{
	if (argc < 1)
		return (1);

	
	return (0);
}