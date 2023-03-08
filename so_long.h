/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:49:04 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/08 12:08:13 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define RED "\e[1;31m"
# define GREEN "\e[1;32m"

# define ESCAPE 65307
# define W 119
# define S 115
# define A 97
# define D 100

typedef struct s_image
{
	void	*player;
	void	*coll;
	void	*exit;
	void	*wall;
	void	*space;
	void	*enemy;
	int		width;
	int		height;
}			t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		height;
	int		width;
	int		go_up;
	int		go_down;
	int		go_left;
	int		go_right;
	int		player_x;
	int		player_y;
	int		player_count;
	int		collect_count;
	int		exit_count;
	int		move_count;
	int		exit_flag;
	t_image	xpm;
}			t_game;

int			close_x(t_game *game);
int			rectangle(t_game *game);
int			key_press(int key, t_game *game);
int			update_game(t_game *game);
int			key_release(int key, t_game *game);
int			display_game(t_game *game);
int			valid_extension(char *av);
int			check_char_and_wall(t_game *game);
void		get_map(t_game *game, char *map_name);
void		check(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		help_up(t_game *game);
void		help_down(t_game *game);
void		help_left(t_game *game);
void		help_right(t_game *game);
void		valid_path(t_game *game);
void		set_values(t_game *game);
void		convert_xpm(t_game *game);
void		count_error(t_game *game);
void		count_check(t_game *game);
void		free_game_map(t_game *game);
void		free_all(t_game *game);
void		restore_map(t_game *game);
void		img_to_win(t_game *game, int height, int width);
void		find_path(t_game *game, int y, int x, int *collect);

#endif
