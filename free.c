/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:48:37 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/08 13:43:02 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_all(t_game *game)
{
	int	y;

	mlx_destroy_image(game->mlx, game->xpm.player);
	mlx_destroy_image(game->mlx, game->xpm.coll);
	mlx_destroy_image(game->mlx, game->xpm.exit);
	mlx_destroy_image(game->mlx, game->xpm.wall);
	mlx_destroy_image(game->mlx, game->xpm.space);
	mlx_destroy_image(game->mlx, game->xpm.enemy);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	y = 0;
	while (y < game->height)
		free(game->map[y++]);
	free(game->map);
	free(game->mlx);
	free(game);
	exit(0);
}

void	free_game_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->height)
		free(game->map[y++]);
	free(game->map);
	free(game);
	exit(0);
}
/* Free in case of map error, free every single line, free map 
and free the game */
