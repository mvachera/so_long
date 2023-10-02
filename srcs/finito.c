/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finito.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:10:42 by mvachera          #+#    #+#             */
/*   Updated: 2023/07/14 19:47:52 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all_line(t_list *all_line)
{
	t_list	*current;

	current = all_line;
	while (current)
	{
		if (ft_strlen(current->content) > 1)
			return (1);
		current = current->next;
	}
	free_stash(all_line);
	return (0);
}

int	finito(t_list *current, t_list *all_line, char **map_a_parser)
{
	while (current)
	{
		if (ft_strlen(current->content) > 1)
		{
			ft_printf("Error\nUne ligne vide a ete trouver!\n");
			free_stash(all_line);
			free_map(map_a_parser);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

char	**finito2(t_list *all_line)
{
	t_list	*current;
	char	**map_a_parser;
	int		i;

	i = 0;
	current = all_line;
	map_a_parser = malloc(sizeof(char *) * (lstnb(all_line) + 1));
	if (map_a_parser == NULL)
		return (NULL);
	while (current && ft_strlen(current->content) <= 1)
		current = current->next;
	while (current && ft_strlen(current->content) > 1)
	{
		map_a_parser[i] = cpy(current->content);
		if (map_a_parser[i] == NULL)
		{
			while (i >= 0)
				free(map_a_parser[i--]);
			return (NULL);
		}
		i++;
		current = current->next;
	}
	map_a_parser[i] = NULL;
	return (map_a_parser);
}

char	**ft_strdup(char **map_a_parser)
{
	char	**dst;
	int		i;

	i = 0;
	while (map_a_parser[i])
		i++;
	dst = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (map_a_parser[i])
	{
		dst[i] = cpy(map_a_parser[i]);
		if (dst[i] == NULL)
		{
			while (i >= 0)
				free(dst[i--]);
			return (NULL);
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
