/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:01:28 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/08 12:07:40 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	find_path(t_game *game, int y, int x, int *collect)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'c'
		|| game->map[y][x] == 'o' || game->map[y][x] == 'e'
		|| game->map[y][x] == 'E')
	{
		if (game->map[y][x] == 'E')
			game->exit_flag = 1;
		return ;
	}
	if (game->map[y][x] == 'C')
	{
		(*collect)--;
		game->map[y][x] = 'c';
	}
	else if (game->map[y][x] == '0')
		game->map[y][x] = 'o';
	find_path(game, (y + 1), x, collect);
	find_path(game, (y - 1), x, collect);
	find_path(game, y, (x + 1), collect);
	find_path(game, y, (x - 1), collect);
}

void	restore_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'c')
				game->map[y][x] = 'C';
			else if (game->map[y][x] == 'e')
				game->map[y][x] = 'E';
			else if (game->map[y][x] == 'o')
				game->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	valid_path(t_game *game)
{
	int	collect;

	collect = game->collect_count;
	find_path(game, game->player_y, game->player_x, &collect);
	if (collect != 0)
	{
		ft_printf(RED "Error : No valid path to a ball\n");
		free_game_map(game);
		exit(1);
	}
	restore_map(game);
	if (game->exit_flag == 0)
	{
		ft_printf(RED "Error: No valid path to Exit\n");
		free_game_map(game);
		exit(1);
	}
}
