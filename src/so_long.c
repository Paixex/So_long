/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:03:13 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 16:11:52 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	av_checker(int ac, char **av)
{
	if (ac != 2)
		errors(NULL, INVALID_NBR_ARGS);
	if (*av[1] == '\0')
		errors(NULL, NULL_MAP);
}

int	main(int ac, char **av)
{
	t_game	game;

	av_checker(ac, av);
	game = init_game();
	get_map(av[1], &game);
	check_map(&game);
	init_mlx(&game);
	map_render(&game);
	hook_n_run(&game);
	return (EXIT_SUCCESS);
}
