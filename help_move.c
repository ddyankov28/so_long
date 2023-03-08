/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:51:48 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/08 14:06:31 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_up(t_game *game)
{
	game->player_y -= 1;
	game->move_count++;
	ft_printf(GREEN "Moves = %d\n", game->move_count);
}

void	help_down(t_game *game)
{
	game->player_y += 1;
	game->move_count++;
	ft_printf(GREEN "Moves = %d\n", game->move_count);
}

void	help_left(t_game *game)
{
	game->player_x -= 1;
	game->move_count++;
	ft_printf(GREEN "Moves = %d\n", game->move_count);
}

void	help_right(t_game *game)
{
	game->player_x += 1;
	game->move_count++;
	ft_printf(GREEN "Moves = %d\n", game->move_count);
}
