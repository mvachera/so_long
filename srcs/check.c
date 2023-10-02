/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:05:58 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/20 16:39:24 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(char **map)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(map[i]);
	if (first_last_line(map[i]) == 0 || entrer_sortie(map) == 0)
		return (0);
	while (map[i])
	{
		if (reste(map) == 0)
			return (0);
		i++;
	}
	if (len == i)
	{
		ft_printf("Error\nLa map est carrer!\n");
		return (0);
	}
	return (1);
}

int	taille_max_map(char **map)
{
	int	len;
	int	i;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 30)
		{
			ft_printf("Error\nLa map est trop grande!\n");
			return (0);
		}
		i++;
	}
	if (i > 16)
	{
		ft_printf("Error\nLa map est trop grande!\n");
		return (0);
	}
	return (1);
}

int	reste(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_printf("Error\nLa map n'est pas rectangle!\n");
			return (0);
		}
		if (item(map[i]) == 0 || first_last_char(map[i]) == 0)
			return (0);
		i++;
	}
	i--;
	if (first_last_line(map[i]) == 0)
		return (0);
	return (1);
}

int	check_map(char *av1, char **map_a_parser)
{
	if (point_ber(av1) == 0)
	{
		ft_printf("Error\nLe nom du fichier est incorrecte!\n");
		free_map(map_a_parser);
		return (0);
	}
	else if (taille_max_map(map_a_parser) == 0)
	{
		free_map(map_a_parser);
		return (0);
	}
	else if (check(map_a_parser) == 0)
	{
		free_map(map_a_parser);
		return (0);
	}
	else if (total_collectible(map_a_parser) == 0)
	{
		free_map(map_a_parser);
		return (0);
	}
	return (1);
}

int	total_collectible(char **map_a_parser)
{
	int	i;
	int	j;
	int	nbr_collectible;

	nbr_collectible = 0;
	i = 0;
	while (map_a_parser[i])
	{
		j = 0;
		while (map_a_parser[i][j])
		{
			if (map_a_parser[i][j] == 'C')
				nbr_collectible++;
			j++;
		}
		i++;
	}
	if (nbr_collectible == 0)
	{
		ft_printf("Error\nLa map doit contenir au moins 1 collectible\n");
		return (0);
	}
	return (nbr_collectible);
}
