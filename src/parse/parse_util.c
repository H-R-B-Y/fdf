/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-13 20:51:00 by hbreeze           #+#    #+#             */
/*   Updated: 2024-11-13 20:51:00 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

# define INT_MAX_STR "2147483647"
# define INT_MIN_STR "-2147483648"

int	str_gt(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '-' && ++i)
			continue ;
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (0);
		i++;
	}
	return (0);
}

int	str_is_int(char *str)
{
	size_t	comp;
	size_t	test;

	if (str[0] == '-')
	{
		comp = ft_strlen(INT_MIN_STR);
		test = ft_strlen(str);
		if (test > comp || (test == comp && str_gt(str, INT_MIN_STR))
			|| (test == 1))
			return (0);
	}
	else
	{
		if (str[0] == '+')
			 str = &(str[1]);
		comp = ft_strlen(INT_MAX_STR);
		test = ft_strlen(str);
		if (test > comp || (test == comp && str_gt(str, INT_MAX_STR))
			|| (test == 0))
			return (0);
	}
	return (1);
}

void	delete_chunks(char **chunks)
{
	int	i;

	i = 0;
	while (chunks[i])
		free(chunks[i++]);
	free(chunks);
}
