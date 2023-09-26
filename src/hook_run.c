/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:37:18 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 10:15:28 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	end_game(t_game *game)
{
	destroy(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	key_pressing(int key, t_game *game)
{
	if (key == ESC)
		end_game(game);
	else if (key == W || key == UP)
		update_pos_player(game, false, -1);
	else if (key == A || key == LEFT)
		update_pos_player(game, true, -1);
	else if (key == S || key == DOWN)
		update_pos_player(game, false, 1);
	else if (key == D || key == RIGHT)
		update_pos_player(game, true, 1);
	return (EXIT_SUCCESS);
}

void	hook_n_run(t_game *game)
{
	mlx_hook(game->win_ptr, KEYPRESS_EVENT, (1L << 0), key_pressing, game);
	mlx_hook(game->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), end_game, game);
	mlx_loop(game->mlx_ptr);
}
