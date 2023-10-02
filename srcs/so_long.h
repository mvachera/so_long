/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:18:28 by mvachera          #+#    #+#             */
/*   Updated: 2023/08/20 16:15:58 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ECHAP 65307

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;

	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
	void	*floor;
	char	**map;

	int		size_x;
	int		size_y;

	int		width;
	int		height;

	int		player_x;
	int		player_y;

	int		exit_x;
	int		exit_y;

	int		mouv;

	int		collect_count;
	int		total_collect;
}			t_game;

void		all_line_new(t_list **all_line, char *line);
void		extract_to_all_line(char *av1, t_list **all_line);
int			check_map(char *av1, char **map_a_parser);
int			back_track(char *av1, t_game *game);
char		**map_parser(t_list *all_line);
char		*cpy(char *all_line_content);
int			check(char **map);
int			entrer_sortie(char **map);
int			point_ber(char *av1);
int			first_last_line(char *line);
int			first_last_char(char *line);
int			item(char *line);
int			total_collectible(char **map);
void		flood_fill(char **tab, t_point size, t_point begin);
char		**make_area(char **a, t_point size);
int			make_flood_fill(char **map_a_parser);
t_point		get_above_cell(t_point b);
t_point		get_below_cell(t_point b);
t_point		get_left_cell(t_point b);
t_point		get_right_cell(t_point b);
void		free_map(char **map_a_parser);
int			map_valide(char **map_a_parser);
t_point		get_begin_cell(char **map_a_parser);
int			reste(char **map);
int			finito(t_list *current, t_list *all_line, char **map_a_parser);
int			check_all_line(t_list *all_line);
char		**finito2(t_list *all_line);
int			lstnb(t_list *all_line);
char		**ft_strdup(char **map_a_parser);
int			init_single_texture(void **img_ptr, t_game *game, char *path);
void		new_pos(t_game *game, int new_y, int new_x);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
int			key_hook(int keycode, t_game *game);
int			disconnect(t_game *game);
int			find_new_pos(t_game *game, int i, int j);
void		get_new_pos(t_game *game);
int			init_texture(t_game *game);
void		print_img(t_game *game, size_t i, size_t j);
void		print_map(t_game *game);
void		print_window(t_game *game);
void		set_map(t_game *game);
void		find_exit(t_game *game);
int			taille_max_map(char **map);

#endif
