/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 20:24:38 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 20:24:38 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	delete_chunks(char **chunks);
int		str_is_int(char *str);

size_t	array_len(char **chunks)
{
	size_t	i;

	i = 0;
	while (chunks[i])
		i++;
	return (i);
}

int	chunk_is_valid(char *chunk)
{
	char	*post;

	post = ft_strchr(chunk, ',');
	if (post)
	{
		post[0] = '\0';
		post = post + 3;
		if (!str_is_int(chunk))
			return (0);
		while (*post != '\0')
		{
			if (!ft_strchr("0123456789ABCDEFabcdef", *post))
				return (0);
			post++;
		}
	}
	else
		if (!str_is_int(chunk))
			return (0);
	return (1);
}

int	chunks_is_int(char **chunks)
{
	int		index;

	index = 0;
	while (chunks[index])
	{
		if (!chunk_is_valid(chunks[index]))
			return (0);
		index++;
	}
	return (1);
}

// Return 0 for valid else code.
int	validate_map(t_list *map)
{
	size_t	last_len;
	char	**chunks;

	chunks = ft_split(map->content, ' ');
	last_len = array_len(chunks);
	if (!chunks_is_int(chunks) && (delete_chunks(chunks), 1))
		return (0);
	delete_chunks(chunks);
	while (map)
	{
		chunks = ft_split(map->content, ' ');
		if (array_len(chunks) != last_len
			|| !chunks_is_int(chunks))
		{
			delete_chunks(chunks);
			return (0);
		}
		delete_chunks(chunks);
		map = map->next;
	}
	return (last_len);
}
