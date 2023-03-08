/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:06:59 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/01 11:15:35 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	get_map(t_game *game, char *map_name)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile does not exist\n");
		free_game_map(game);
		exit(1);
	}
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			break ;
		i++;
		game->height++;
	}
	game->width = ft_strlen(game->map[0]) - 1;
	close (fd);
}
