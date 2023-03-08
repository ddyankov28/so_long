/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:25:19 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/08 12:06:09 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	count_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_count++;
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'C')
				game->collect_count++;
			else if (game->map[y][x] == 'E')
				game->exit_count++;
			x++;
		}
		y++;
	}
}

void	count_error(t_game *game)
{
	if (game->player_count != 1 || game->exit_count != 1)
	{
		ft_printf(RED "Error: You need 1 Exit and 1 Player to start!! \n");
		free_game_map(game);
		exit(1);
	}
	if (game->collect_count < 1)
	{
		ft_printf(RED "Error: You need collectibles to start!!\n");
		free_game_map(game);
		exit(1);
	}
}

int	check_char_and_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] != 'P' && game->map[y][x] != 'C'
				&& game->map[y][x] != '1' && game->map[y][x] != '0'
				&& game->map[y][x] != 'E' && game->map[y][x] != 'X')
				return (1);
			if (y == 0 || y == game->height - 1 || x == 0 || x == game->width
				- 1)
			{
				if (game->map[y][x] != '1')
					return (2);
			}
			x++;
		}
		y++;
	}
	return (0);
}
/* We check at the same time if there are some illegal characters in the 
map and we check if it is surrounded only by walls */

int	rectangle(t_game *game)
{
	int	y;

	y = 1;
	while (y < game->height)
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[y]))
			return (1);
		y++;
	}
	return (0);
}
/* We check if the lengt of the first line is equal to all the others
for checking if it the map is rectangle*/

void	check(t_game *game)
{
	count_check(game);
	count_error(game);
	if (rectangle(game) == 1)
	{
		ft_printf(RED "Error: Map is NOT rectangle\n");
		free_game_map(game);
		exit(1);
	}
	if (check_char_and_wall(game) == 1)
	{
		ft_printf(RED "Error: Map has illegal character\n");
		free_game_map(game);
		exit(1);
	}
	if (check_char_and_wall(game) == 2)
	{
		ft_printf(RED "Error: Map NOT surrounded by WALLS\n");
		free_game_map(game);
		exit(1);
	}
}
