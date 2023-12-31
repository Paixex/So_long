/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:03:25 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 11:42:07 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static bool valid_extension(char *map_file)
{
	size_t	i;
	
	i = ft_strlen(map_file) - 4;
	if (ft_strncmp(".ber", &map_file[i], 4) == 0)
		return (true);
	return (false);
}

static void nbr_rows(char *map_file, t_game *game)
{
	int		counter;
	int		map_fd;
	char	*temp;

	counter = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		errors(game, OPEN_MAP_FILE_ERR);
	temp = get_next_line(map_fd);
	while (temp)
	{
		counter += 1;
		free(temp);
		temp = get_next_line(map_fd);
	}
	if (counter == 0)
		errors(game, EMPTY_MAP_FILE);
	game->map.rows = counter;
	close(map_fd);
}

static void	get_lines(char *map_file, t_game *game)
{
	int	map_fd;
	int	i;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		errors(game, OPEN_MAP_FILE_ERR);
	i = 0;
	while (i < game->map.rows)
		game->map.map[i++] = get_next_line(map_fd);
	game->map.map[i] = NULL;
	close(map_fd);
	i = 0;
	while (i < (game->map.rows - 1))
	{
		game->map.map[i] = free_trim(game->map.map[i], "\n");
		if (!game->map.map[i])
			errors(game, MALLOC_ERR);
		i += 1;
	}
	game->map.columns = ft_strlen(game->map.map[0]);
}

void	get_map(char *map_file, t_game *game)
{
	if (!valid_extension(map_file))
		errors(game, INVALID_MAP_FILE);
	nbr_rows(map_file, game);
	game->map.map = malloc((game->map.rows + 1) * sizeof(char *));
	if (!game->map.map)
		errors(game, MALLOC_ERR);
	get_lines(map_file, game);
}
