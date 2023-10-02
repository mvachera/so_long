/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:18:02 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/19 21:53:38 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
			}
			j++;
		}
		i++;
	}
	game->size_x = 64;
	game->size_y = 64;
	game->mouv = 0;
	game->collect_count = 0;
	game->total_collect = total_collectible(game->map);
	game->width = ft_strlen(game->map[0]);
	game->height = i;
}

void	find_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_y = i;
				game->exit_x = j;
			}
			j++;
		}
		i++;
	}
	game->map[game->exit_y][game->exit_x] = '0';
}

int	main(int ac, char **av)
{
	static t_game	game = {0};

	if (ac != 2)
		ft_printf("Error\nNombre d'argument incorrect!\n");
	else if (ac == 2 && back_track(av[1], &game) == 1)
	{
		set_map(&game);
		find_exit(&game);
		print_window(&game);
	}
	return (0);
}
