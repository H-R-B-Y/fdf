/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 20:19:58 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 20:19:58 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	file_readable(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 3)
		return (0);
	return (fd);
}

t_list	*read_lines(int fd)
{
	char	*current_line;
	t_list	*list;

	current_line = get_next_line(fd);
	list = 0;
	while(current_line)
	{
		if (current_line[ft_strlen(current_line) - 1] == '\n')
			current_line[ft_strlen(current_line) - 1] = '\0';
		if (ft_strlen(current_line) != 0)
			ft_lstadd_back(&list, ft_lstnew(current_line));
		current_line = get_next_line(fd);
	}
	return (list);
}
