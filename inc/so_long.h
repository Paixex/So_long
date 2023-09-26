/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:54:50 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 11:49:37 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*------------------------------------------------------------*/

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include "Libft/libft.h"
# include "errors.h"
# include "tiles.h"
# include "keys.h"

/*-------------------------Constants--------------------------*/

# define OPEN_SPACE '0'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

# define KEYPRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define WIN_MSG "You won!\n"

/*--------------------------Structs---------------------------*/

typedef struct	s_point
 {
	int	x;
	int	y;
}				t_point;

typedef	struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		collectibles;
	int		exit;
	int		player;
	t_point	player_pos;
}				t_map;

typedef struct s_tiles
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_tiles;

typedef struct s_game
{
	t_map	map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_tiles	tiles;
	int		moves;
}				t_game;

static inline	t_game	init_game(void)
{
	return ((t_game){
		.map.map = NULL,
		.map.rows = 0,
		.map.columns = 0,
		.map.collectibles = 0,
		.map.exit = 0,
		.map.player = 0,
		.tiles.collectible = NULL,
		.tiles.exit = NULL,
		.tiles.floor = NULL,
		.tiles.player = NULL,
		.tiles.wall = NULL,
		.moves = -1,
	});
}

/*---------------------------Buffer---------------------------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif 

/*-------------------------Prototypes-------------------------*/

//GNL
bool		is_onstr(const char *str, int ch);
char		*get_next_line(int fd);

//Map & Checkers
void		check_map(t_game *game);
void		check_path(t_game *game);
char		*free_trim(char *s1, char const *set);
void		get_map(char *map_file, t_game *game);

//Error handling
void		errors(t_game *game, char *error_msg);

//Destroying
void		free_array(char **array);
void		destroy_tiles(t_game *game);
void		destroy(t_game *game);

//Hook
int			key_pressing(int key, t_game *game);
void		hook_n_run(t_game *game);

//Player
void		update_pos_player(t_game *game, bool horizontal, int length);
void		put_player_tile(t_game *game);

//Render
void		tiles_render(t_game *game);
void		map_render(t_game *game);

//MLX
void		init_mlx(t_game *game);

//End
int			end_game(t_game *game);
#endif