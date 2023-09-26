/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:10:02 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/26 00:07:54 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_player_tile(t_game *game)
{
	char	*moves;

	game->moves += 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
		TILE_SIZE * game->map.player_pos.x, TILE_SIZE * game->map.player_pos.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->tiles.wall, 0, 0);
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 10, 1, moves);
	free(moves);
}

void	which_tile(t_game *game)
{
	if (game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] == COLLECTIBLE)
	{
		game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] = OPEN_SPACE;
		game->map.collectibles -= 1;
		return ;
	}
	if (game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] == EXIT && game->map.collectibles == 0)
	{
		ft_printf(WIN_MSG);
		end_game(game);
	}
}

static void	update_left_behind_tile(t_game *game)
{
	if (game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] == EXIT)
	{
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->tiles.exit,
			TILE_SIZE * game->map.player_pos.x,
			TILE_SIZE * game->map.player_pos.y);
	}
	else
	{
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->tiles.floor,
			TILE_SIZE * game->map.player_pos.x,
			TILE_SIZE * game->map.player_pos.y);
	}
}

void	update_pos_player(t_game *game, bool horizontal, int length)
{
	if (horizontal)
	{
		if (game->map.map[game->map.player_pos.y]
			[game->map.player_pos.x + length] == WALL)
			return ;
		update_left_behind_tile(game);
		game->map.player_pos.x += length;
	}
	else
	{
		if (game->map.map[game->map.player_pos.y + length]
			[game->map.player_pos.x] == WALL)
			return ;
		update_left_behind_tile(game);
		game->map.player_pos.y += length;
	}
	which_tile(game);
	put_player_tile(game);
}
