/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:43:30 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/06 11:40:35 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	set_values(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->map = malloc(10000);
	game->go_up = 0;
	game->go_down = 0;
	game->go_left = 0;
	game->go_right = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->player_count = 0;
	game->collect_count = 0;
	game->exit_count = 0;
	game->move_count = 0;
	game->exit_flag = 0;
}

int	valid_extension(char *av)
{
	char	*extension;

	extension = ft_strrchr(av, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
	{
		ft_printf(RED "Map must end with < .ber >\n");
		return (1);
	}
	return (0);
}

int	close_x(t_game *game)
{
	free_all(game);
	exit(0);
	return (0);
}

void	args(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		ft_printf(RED "Error: Enter 2 arguments(the exe and a map) please!\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	args(ac, av);
	if (valid_extension(av[1]) == 0)
	{
		game = (t_game *)malloc(sizeof(t_game));
		set_values(game);
		get_map(game, av[1]);
		check(game);
		valid_path(game);
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->width * 100, game->height
				* 100, "SO_LONG");
		display_game(game);
		mlx_hook(game->win, 2, 1L << 0, key_press, game);
		mlx_hook(game->win, 3, 1L << 1, key_release, game);
		mlx_hook(game->win, 17, 1L << 17, close_x, game);
		mlx_loop(game->mlx);
	}
	return (0);
}
