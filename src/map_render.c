/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:13:05 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 16:24:53 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_xpm_error(t_game *game)
{
	if (!game->tiles.wall)
		errors(game, WALL_XPM_ERR);
	if (!game->tiles.floor)
		errors(game, PLAYER_XPM_ERR);
	if (!game->tiles.player)
		errors(game, PLAYER_XPM_ERR);
	if (!game->tiles.collectible)
		errors(game, COLLECTIBLE_XPM_ERR);
	if (!game->tiles.exit)
		errors(game, EXIT_XPM_ERR);
}

static void	open_xpm(t_game *game)
{
	int	size;
	
	size = TILE_SIZE;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_TILE, &size, &size);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR_TILE, &size, &size);
	game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_TILE, &size, &size);
	game->tiles.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &size, &size);
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_TILE, &size, &size);
	check_xpm_error(game);
}

void	tiles_render(t_game *game)
{
	int	i;
	int	k;

	i = -1;
	while (++i < game->map.rows)
	{
		k = -1;
		while (++k < game->map.columns)
		{
			if (game->map.map[i][k] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.wall, TILE_SIZE * k, TILE_SIZE * i);
			else if (game->map.map[i][k] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.collectible, TILE_SIZE * k, TILE_SIZE * i);
			else if (game->map.map[i][k] == EXIT)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.exit, TILE_SIZE * k, TILE_SIZE * i);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.floor, TILE_SIZE * k, TILE_SIZE * i);
		}
	}
	put_player_tile(game);
}

void	map_render(t_game *game)
{
	open_xpm(game);
	tiles_render(game);
}
