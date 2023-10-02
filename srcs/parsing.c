/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:00:12 by mvachera          #+#    #+#             */
/*   Updated: 2023/07/08 21:08:25 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	entrer_sortie(char **map)
{
	int		i;
	int		j;
	int		boil;
	int		bonl;

	i = 0;
	boil = 0;
	bonl = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				boil++;
			if (map[i][j] == 'E')
				bonl++;
			j++;
		}
		i++;
	}
	if (boil == 1 && bonl == 1)
		return (1);
	ft_printf("Error\nLa map doit avoir exactement une entree et une sortie!\n");
	return (0);
}

int	point_ber(char *av1)
{
	int	i;

	i = ft_strlen(av1) - 1;
	if (ft_strlen(av1) <= 4)
		return (0);
	if (av1[i] != 'r')
		return (0);
	i--;
	if (av1[i] != 'e')
		return (0);
	i--;
	if (av1[i] != 'b')
		return (0);
	i--;
	if (av1[i] != '.')
		return (0);
	return (1);
}

int	first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			ft_printf("Error\nLa map n'est pas fermee!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	first_last_char(char *line)
{
	int	len;

	len = ft_strlen(line) - 1;
	if (line[0] != '1')
	{
		ft_printf("Error\nLa map n'est pas fermee!\n");
		return (0);
	}
	if (line[len] != '1')
	{
		ft_printf("Error\nLa map n'est pas fermee!\n");
		return (0);
	}
	return (1);
}

int	item(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'C' || line[i] == 'P'
			|| line[i] == 'E')
			i++;
		else
		{
			ft_printf("Error\nUn caractere incorrecte a ete trouver!\n");
			return (0);
		}
	}
	return (1);
}
