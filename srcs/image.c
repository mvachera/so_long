/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:16:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/19 21:45:44 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_single_texture(void **img_ptr, t_game *game, char *path)
{
	*img_ptr = mlx_xpm_file_to_image(game->mlx, path, &game->size_x,
			&game->size_y);
	if (!*img_ptr)
	{
		ft_printf("Error\nUne image n'a pas ete initialiser correctement!\n");
		return (1);
	}
	return (0);
}

int	init_texture(t_game *game)
{
	if (init_single_texture(&game->wall, game, "image/wall.xpm"))
		return (1);
	if (init_single_texture(&game->player, game, "image/player.xpm"))
		return (1);
	if (init_single_texture(&game->collect, game, "image/collectible.xpm"))
		return (1);
	if (init_single_texture(&game->exit, game, "image/exit.xpm"))
		return (1);
	if (init_single_texture(&game->floor, game, "image/floor.xpm"))
		return (1);
	return (0);
}

void	print_img(t_game *game, size_t i, size_t j)
{
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, (j
				* 64), (i * 64));
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, (j * 64),
			(i * 64));
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect, (j
				* 64), (i * 64));
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, (j * 64),
			(i * 64));
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, (j * 64),
			(i * 64));
}

void	print_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			print_img(game, i, j);
			j++;
		}
		i++;
	}
}

void	print_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free_map(game->map);
		return ;
	}
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64, game->height
			* 64, "so_long");
	if (init_texture(game))
	{
		return ;
	}
	if (game->mlx_win == NULL)
	{
		free(game->mlx_win);
		free_map(game->map);
		return ;
	}
	print_map(game);
	mlx_hook(game->mlx_win, 17, (1L << 17), disconnect, game);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_loop(game->mlx);
}
