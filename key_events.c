/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:09:00 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/08 13:46:21 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_game(t_game *game)
{
	if (game->go_up != 0)
		move_up(game);
	else if (game->go_down != 0)
		move_down(game);
	else if (game->go_left != 0)
		move_left(game);
	else if (game->go_right != 0)
		move_right(game);
	mlx_destroy_image(game->mlx, game->xpm.player);
	mlx_destroy_image(game->mlx, game->xpm.coll);
	mlx_destroy_image(game->mlx, game->xpm.exit);
	mlx_destroy_image(game->mlx, game->xpm.wall);
	mlx_destroy_image(game->mlx, game->xpm.space);
	mlx_destroy_image(game->mlx, game->xpm.enemy);
	display_game(game);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == ESCAPE)
	{
		free_all(game);
		exit(0);
		return (0);
	}
	if (key == W)
		game->go_up = 1;
	if (key == S)
		game->go_down = 1;
	if (key == A)
		game->go_left = 1;
	if (key == D)
		game->go_right = 1;
	update_game(game);
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == W)
		game->go_up = 0;
	if (key == S)
		game->go_down = 0;
	if (key == A)
		game->go_left = 0;
	if (key == D)
		game->go_right = 0;
	update_game(game);
	return (0);
}
