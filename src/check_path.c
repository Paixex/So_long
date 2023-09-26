/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:55:55 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 10:07:40 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	**b_grid(t_game *game)
{
	int		i;
	char	**grid;

	i = 0;
	grid = ft_calloc((game->map.rows + 1), sizeof(char *));
	if (!grid)
		errors(game, MALLOC_ERR);
	while (i < game->map.rows)
	{
		grid[i] = ft_strdup(game->map.map[i]);
		if (!grid[i])
		{
			free_array(grid);
			errors(game, MALLOC_ERR);
		}
		i += 1;
	}
	return (grid);
}

static bool	fill_grid(t_map *map, t_point current, char **s_grid)
{
	static int		wheel = 0;
	static bool		exit = false;

	if (s_grid[current.y][current.x] == WALL)
		return (false);
	else if (s_grid[current.y][current.x] == COLLECTIBLE)
		wheel += 1;
	else if (s_grid[current.y][current.x] == EXIT)
		exit = true;
	s_grid[current.y][current.x] = WALL;
	fill_grid(map, (t_point){current.x + 1, current.y}, s_grid);
	fill_grid(map, (t_point){current.x - 1, current.y}, s_grid);
	fill_grid(map, (t_point){current.x, current.y + 1}, s_grid);
	fill_grid(map, (t_point){current.x, current.y - 1}, s_grid);
	return (wheel == map->collectibles && exit);
}

void	check_path(t_game *game)
{
	char	**s_grid;

	s_grid = b_grid(game);
	if (!fill_grid(&game->map, game->map.player_pos, s_grid))
	{
		free_array(s_grid);
		errors(game, UNACHIEVABLE_ENTITIES);
	}
	free_array(s_grid);
}
