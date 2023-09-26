/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:29:40 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/19 12:32:16 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		errors(game, MLX_INIT_ERR);
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map.columns * TILE_SIZE, game->map.rows * TILE_SIZE,
			"so_long");
	if (!game->win_ptr)
		errors(game, MLX_NEW_WINDOW_ERR);
}
