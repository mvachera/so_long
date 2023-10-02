/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:36:37 by mvachera          #+#    #+#             */
/*   Updated: 2023/07/06 16:48:02 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	get_above_cell(t_point b)
{
	t_point	p;

	p.y = b.y - 1;
	p.x = b.x;
	return (p);
}

t_point	get_below_cell(t_point b)
{
	t_point	p;

	p.y = b.y + 1;
	p.x = b.x;
	return (p);
}

t_point	get_left_cell(t_point b)
{
	t_point	p;

	p.y = b.y;
	p.x = b.x - 1;
	return (p);
}

t_point	get_right_cell(t_point b)
{
	t_point	p;

	p.y = b.y;
	p.x = b.x + 1;
	return (p);
}

t_point	get_begin_cell(char **map_a_parser)
{
	int		i;
	int		j;
	t_point	begin;

	i = 0;
	while (map_a_parser[i] != NULL)
	{
		j = 0;
		while (map_a_parser[i][j])
		{
			if (map_a_parser[i][j] == 'P')
			{
				begin.x = j;
				begin.y = i;
			}
			j++;
		}
		i++;
	}
	return (begin);
}
