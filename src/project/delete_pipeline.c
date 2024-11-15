/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 16:42:42 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-15 16:42:42 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	_destory_frame_wrapper(void *param)
{
	t_tframe *p;

	p = param;
	if (p->param_freeable)
		free(p->param);
	free(param);
}

void	destroy_projection(t_proj **proj)
{
	if ((*proj)->param_freeable)
		free((*proj)->param);
	ft_lstclear(&(*proj)->translate_3D, _destory_frame_wrapper);
	ft_lstclear(&(*proj)->translate_2D, _destory_frame_wrapper);
	free((*proj));
	*proj = 0;
}
