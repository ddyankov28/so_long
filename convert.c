/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:43:20 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/08 12:09:20 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	convert_xpm(t_game *game)
{
	game->xpm.player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm",
			&game->xpm.width, &game->xpm.height);
	game->xpm.coll = mlx_xpm_file_to_image(game->mlx, "img/collect.xpm",
			&game->xpm.width, &game->xpm.height);
	game->xpm.exit = mlx_xpm_file_to_image(game->mlx, "img/exit.xpm",
			&game->xpm.width, &game->xpm.height);
	game->xpm.wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
			&game->xpm.width, &game->xpm.height);
	game->xpm.space = mlx_xpm_file_to_image(game->mlx, "img/space.xpm",
			&game->xpm.width, &game->xpm.height);
	game->xpm.enemy = mlx_xpm_file_to_image(game->mlx, "img/enemy.xpm",
			&game->xpm.width, &game->xpm.height);
}

void	img_to_win(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.player, x * 100,
			y * 100);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.coll, x * 100,
			y * 100);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.exit, x * 100,
			y * 100);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.wall, x * 100,
			y * 100);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.space, x * 100,
			y * 100);
	else if (game->map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->win, game->xpm.enemy, x * 100,
			y * 100);
}

int	display_game(t_game *game)
{
	int		x;
	int		y;
	char	*m;

	convert_xpm(game);
	m = ft_itoa(game->move_count);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			img_to_win(game, y, x);
			mlx_string_put(game->mlx, game->win, 0, 10, 0XF9DB24,
				"M O V E S  =");
			mlx_string_put(game->mlx, game->win, 90, 10, 0XF9DB24, m);
			mlx_string_put(game->mlx, game->win, 350, 10, 0XF9DB24,
				"H A V E   F U N");
			x++;
		}
		y++;
	}
	free(m);
	return (0);
}
