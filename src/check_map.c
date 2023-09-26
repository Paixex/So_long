/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:34:18 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 12:20:03 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define VALID_ENTITIES "ECP01"

static void	open_errors(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		errors(game, INVALID_NBR_EXITS);
	if (game->map.collectibles == 0)
		errors(game, NO_COLLECTIBLES);
	if (game->map.player == 0 || game->map.player > 1)
		errors(game, INVALID_NBR_PLAYERS);
}

static void	check_elements(t_game *game)
{
	int	i;
	int	k;
	
	i = -1;
	while (++i < game->map.rows)
	{
		k = -1;
		while (++k < game->map.columns)
		{
			if (!is_onstr(VALID_ENTITIES, game->map.map[i][k]))
				errors(game, INVALID_ENTITY);
			if (game->map.map[i][k] == EXIT)
				game->map.exit += 1;
			else if (game->map.map[i][k] == COLLECTIBLE)
				game->map.collectibles += 1;
			else if (game->map.map[i][k] == PLAYER)
			{
				game->map.player += 1;
				game->map.player_pos = (t_point){k, i};
			}
		}
	}
	open_errors(game);
}

static bool	is_closed(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		if (map->map[i][0] != WALL || map->map[i][map->columns - 1] != WALL)
			return (false);
	i = -1;
	while (++i < map->columns)
		if (map->map[0][i] != WALL || map->map[map->rows - 1][i] != WALL)
			return (false);
	return (true);
}

static bool check_form(t_game *game)
{
	size_t	len;
	size_t	i;

	len = game->map.columns;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (len != ft_strlen(game->map.map[i]))
			return (false);
		i += 1;
	}
	return (true);
}

void	check_map(t_game *game)
{
	if (!check_form(game))
		errors(game, INVALID_FORMAT);
	check_elements(game);
	if (!is_closed(&game->map))
		errors(game, MAP_NOT_CLOSED);
	check_path(game);
}
