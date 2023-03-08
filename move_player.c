/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:25:35 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/08 14:06:17 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y - 1][game->player_x] = 'P';
		help_up(game);
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y - 1][game->player_x] = 'P';
		game->collect_count--;
		help_up(game);
	}
	else if ((game->map[game->player_y - 1][game->player_x] == 'E'
		&& game->collect_count == 0)
				|| game->map[game->player_y - 1][game->player_x] == 'X')
	{
		help_up(game);
		free_all(game);
		exit(0);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y + 1][game->player_x] = 'P';
		help_down(game);
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y + 1][game->player_x] = 'P';
		game->collect_count--;
		help_down(game);
	}
	else if ((game->map[game->player_y + 1][game->player_x] == 'E'
		&& game->collect_count == 0)
			|| game->map[game->player_y + 1][game->player_x] == 'X')
	{
		help_down(game);
		free_all(game);
		exit(0);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x - 1] = 'P';
		help_left(game);
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x - 1] = 'P';
		game->collect_count--;
		help_left(game);
	}
	else if ((game->map[game->player_y][game->player_x - 1] == 'E'
		&& game->collect_count == 0)
			|| game->map[game->player_y][game->player_x - 1] == 'X')
	{
		help_left(game);
		free_all(game);
		exit(0);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x + 1] = 'P';
		help_right(game);
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[game->player_y][game->player_x + 1] = 'P';
		game->collect_count--;
		help_right(game);
	}
	else if ((game->map[game->player_y][game->player_x + 1] == 'E'
		&& game->collect_count == 0)
			|| game->map[game->player_y][game->player_x + 1] == 'X')
	{
		help_right(game);
		free_all(game);
		exit(0);
	}
}
