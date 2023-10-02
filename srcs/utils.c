/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:07:32 by mvachera          #+#    #+#             */
/*   Updated: 2023/09/03 16:03:57 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_line_new(t_list **all_line, char *line)
{
	t_list	*new;
	t_list	*last;
	int		i;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	last = get_last_node(*all_line);
	i = 0;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!new->content)
		return ;
	while (line[i])
	{
		new->content[i] = line[i];
		i++;
	}
	new->content[i] = '\0';
	if (*all_line == NULL)
	{
		*all_line = new;
		return ;
	}
	last->next = new;
}

void	extract_to_all_line(char *av1, t_list **all_line)
{
	int		fd;
	char	*line;

	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		all_line_new(all_line, line);
		free(line);
	}
	close(fd);
}

int	lstnb(t_list *all_line)
{
	t_list	*current;
	int		i;

	current = all_line;
	i = 0;
	while (current)
	{
		if (ft_strlen(current->content) > 1)
			i++;
		current = current->next;
	}
	return (i);
}

char	*cpy(char *all_line_content)
{
	char	*line;
	int		j;

	line = malloc(sizeof(char) * (ft_strlen(all_line_content) + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (all_line_content[j] && all_line_content[j] != '\n')
	{
		line[j] = all_line_content[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	**map_parser(t_list *all_line)
{
	char	**map_a_parser;
	t_list	*current;

	map_a_parser = finito2(all_line);
	if (map_a_parser == NULL)
		return (NULL);
	current = all_line;
	while (current && ft_strlen(current->content) <= 1)
		current = current->next;
	while (current && ft_strlen(current->content) > 1)
		current = current->next;
	if (finito(current, all_line, map_a_parser) == 0)
		return (NULL);
	return (map_a_parser);
}
