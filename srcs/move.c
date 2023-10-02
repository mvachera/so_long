/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:57:23 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/19 21:54:25 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*

position actuel joueur
position futur

check si pos futur accessible ?

sauvegarder ancienne position joueur
deplacer le joueur dans ton tableau

ancienne	pos = 0

put image to window (JOUEURIMG, joueur.x * 64, joueur.y * 64);
put image to window (SOLIMG, oldjoueur.x * 64, ...);

*/

void	new_pos(t_game *game, int new_y, int new_x)
{
	game->mouv++;
	game->map[game->player_y][game->player_x] = '0';
	game->player_y = new_y;
	game->player_x = new_x;
	game->map[game->player_y][game->player_x] = 'P';
	if (game->collect_count == game->total_collect)
		game->map[game->exit_y][game->exit_x] = 'E';
}

void	move_up(t_game *game)
{
	int	new_y;

	get_new_pos(game);
	new_y = game->player_y - 1;
	if (game->map[new_y][game->player_x] == '1')
		return ;
	if (game->map[new_y][game->player_x] == 'C')
		game->collect_count++;
	if (game->map[new_y][game->player_x] == 'E')
	{
		if (game->collect_count == game->total_collect)
			disconnect(game);
		else
			return ;
	}
	else
		new_pos(game, new_y, game->player_x);
	ft_printf("Nombre de pas : %d\n", game->mouv);
	print_map(game);
}

void	move_left(t_game *game)
{
	int	new_x;

	get_new_pos(game);
	new_x = game->player_x - 1;
	if (game->map[game->player_y][new_x] == '1')
		return ;
	if (game->map[game->player_y][new_x] == 'C')
		game->collect_count++;
	if (game->map[game->player_y][new_x] == 'E')
	{
		if (game->collect_count == game->total_collect)
			disconnect(game);
		return ;
	}
	else
		new_pos(game, game->player_y, new_x);
	ft_printf("Nombre de pas : %d\n", game->mouv);
	print_map(game);
}

void	move_right(t_game *game)
{
	int	new_x;

	get_new_pos(game);
	new_x = game->player_x + 1;
	if (game->map[game->player_y][new_x] == '1')
		return ;
	if (game->map[game->player_y][new_x] == 'C')
		game->collect_count++;
	if (game->map[game->player_y][new_x] == 'E')
	{
		if (game->collect_count == game->total_collect)
			disconnect(game);
		return ;
	}
	else
		new_pos(game, game->player_y, new_x);
	ft_printf("Nombre de pas : %d\n", game->mouv);
	print_map(game);
}

void	move_down(t_game *game)
{
	int	new_y;

	get_new_pos(game);
	new_y = game->player_y + 1;
	if (game->map[new_y][game->player_x] == '1')
		return ;
	if (game->map[new_y][game->player_x] == 'C')
		game->collect_count++;
	if (game->map[new_y][game->player_x] == 'E')
	{
		if (game->collect_count == game->total_collect)
			disconnect(game);
		return ;
	}
	else
		new_pos(game, new_y, game->player_x);
	ft_printf("Nombre de pas : %d\n", game->mouv);
	print_map(game);
}
