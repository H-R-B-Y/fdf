/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_projections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-14 18:13:34 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-14 18:13:34 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_tframe	*create_tframe(enum e_fntype type,
	void *func, void *param, int freeable)
{
	t_tframe	*output;

	if (!func)
		return (0);
	output = malloc(sizeof(t_tframe));
	if (!output)
		return (0);
	output->type = type;
	if (type == TRVEC2)
		output->func.trvec2 = func;
	else if (type == TRVEC3)
		output->func.trvec3 = func;
	else if (type == TRVEC2X)
		output->func.trvec2x = func;
	else if (type == TRVEC3X)
		output->func.trvec3x = func;
	output->param = param;
	output->param_freeable = freeable;
	return (output);
}

// Should be better protected
int	append_frame(t_proj *proj, t_tframe *frame)
{
	if (!proj || !frame)
		return (0);
	if (frame->type == TRVEC2 || frame->type == TRVEC2X)
		ft_lstadd_back(&proj->translate_2D, ft_lstnew(frame));
	else if (frame->type == TRVEC3 || frame->type == TRVEC3X)
		ft_lstadd_back(&proj->translate_3D, ft_lstnew(frame));
	return (1);
}

int	prepend_frame(t_proj *proj, t_tframe *frame)
{
	if (!proj || !frame)
		return (0);
	if (frame->type == TRVEC2 || frame->type == TRVEC2X)
		ft_lstadd_front(&proj->translate_2D, ft_lstnew(frame));
	else if (frame->type == TRVEC3 || frame->type == TRVEC3X)
		ft_lstadd_front(&proj->translate_3D, ft_lstnew(frame));
	return (1);
}
