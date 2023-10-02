/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:04:50 by mvachera          #+#    #+#             */
/*   Updated: 2023/07/16 21:38:07 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	back_track(char *av1, t_game *game)
{
	static t_list	*all_line;
	char			**map_a_parser;

	all_line = NULL;
	extract_to_all_line(av1, &all_line);
	if (!all_line || check_all_line(all_line) == 0)
	{
		ft_printf("Error\nLe fichier est vide ou inexistant!\n");
		return (0);
	}
	map_a_parser = map_parser(all_line);
	if (!map_a_parser)
		return (0);
	free_stash(all_line);
	if (check_map(av1, map_a_parser) == 1)
	{
		game->map = ft_strdup(map_a_parser);
		if (!game->map)
			return (free_map(map_a_parser), 0);
		if (make_flood_fill(map_a_parser) == 1)
			return (free_map(map_a_parser), 1);
		free_map(game->map);
		free_map(map_a_parser);
	}
	return (0);
}

void	flood_fill(char **t, t_point s, t_point b)
{
	char	i;
	char	c;
	char	e;

	i = '0';
	t[b.y][b.x] = '2';
	e = 'E';
	c = 'C';
	if (b.y > 0 && (t[b.y - 1][b.x] == i || t[b.y - 1][b.x] == c || t[b.y
			- 1][b.x] == e))
		flood_fill(t, s, get_above_cell(b));
	if (b.y < (s.y - 1) && (t[b.y + 1][b.x] == i || t[b.y + 1][b.x] == c
			|| t[b.y - 1][b.x] == e))
		flood_fill(t, s, get_below_cell(b));
	if (b.x > 0 && (t[b.y][b.x - 1] == i || t[b.y + 1][b.x] == c || t[b.y
			- 1][b.x] == e))
		flood_fill(t, s, get_left_cell(b));
	if (b.x < (s.x - 1) && (t[b.y][b.x + 1] == i || t[b.y][b.x + 1] == c
			|| t[b.y - 1][b.x] == e))
		flood_fill(t, s, get_right_cell(b));
}

int	make_flood_fill(char **map_a_parser)
{
	int		l;
	int		i;
	t_point	size;
	t_point	begin;

	i = 0;
	while (map_a_parser[i] != NULL)
		i++;
	l = ft_strlen(map_a_parser[0]);
	size.x = l;
	size.y = i;
	begin = get_begin_cell(map_a_parser);
	flood_fill(map_a_parser, size, begin);
	if (map_valide(map_a_parser) == 0)
		return (0);
	return (1);
}

int	map_valide(char **map_a_parser)
{
	int	i;
	int	j;

	i = 0;
	while (map_a_parser[i])
	{
		j = 0;
		while (map_a_parser[i][j])
		{
			if (map_a_parser[i][j] == 'E' || map_a_parser[i][j] == 'C')
			{
				if (map_a_parser[i][j] == 'E')
					ft_printf("Error\nLa sortie est inaccessible!\n");
				if (map_a_parser[i][j] == 'C')
					ft_printf("Error\nUn collectible est inaccessible!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_map(char **map_a_parser)
{
	int	i;

	i = 0;
	while (map_a_parser[i])
	{
		free(map_a_parser[i]);
		i++;
	}
	free(map_a_parser);
}
