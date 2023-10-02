/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:42:23 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/19 21:49:35 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	disconnect(t_game *game)
{
	free_map(game->map);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ECHAP)
		disconnect(game);
	if (keycode == UP || keycode == 65362)
		move_up(game);
	if (keycode == LEFT || keycode == 65361)
		move_left(game);
	if (keycode == DOWN || keycode == 65364)
		move_down(game);
	if (keycode == RIGHT || keycode == 65363)
		move_right(game);
	return (0);
}

int	find_new_pos(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		game->player_y = i;
		game->player_x = j;
		return (1);
	}
	return (0);
}

void	get_new_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (find_new_pos(game, i, j))
				return ;
			j++;
		}
		i++;
	}
	ft_printf("Error\nLa position du joueur, n'a pas ete trouver!\n");
}
