/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:40:54 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:15:00 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WALLPATH "./assets/wall2.xpm"
# define FLOORPATH "./assets/floor_32.xpm"
# define ITEMPATH "./assets/item2.xpm"
# define BARRELPATH "./assets/barrel.xpm"
# define EXITPATH "./assets/exit.xpm"
# define PLAYERDOWNPATH "./assets/player_down.xpm"
# define PLAYERUPPATH "./assets/player_up.xpm"
# define PLAYERLEFTPATH "./assets/player_left.xpm"
# define PLAYERRIGHTPATH "./assets/player_right.xpm"
# define ASSETS_SIZE 32

typedef struct s_character {
	void	*img;
	int		width;
	int		height;
	int		posx;
	int		posy;
}				t_character;

typedef struct s_vars {
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			nbitemsleft;
	int			nbmoves;
	t_character	player;
}				t_vars;

typedef struct s_mapdata {
	int	nbexit;
	int	nbitem;
	int	nbstart;
}				t_mapdata;

typedef struct s_asset {
	void	*img;
	int		width;
	int		height;
}				t_asset;

char	**parsingdata(char *file);
void	check_mapdata(char **map);
int		new_strlen(char *str);
int		get_mapsize(char **map);
int		get_heightsize(char **map);
int		get_widthsize(char **map);
void	init_game(char **map, t_vars *vars, t_character *player);
void	move_player(int keycode, t_vars *vars, t_character *player);
void	ft_printf(const char *format, ...);
void	exit_errmsg(char *err);
void	check_arg(char *mapname, char *ext);
void	exit_free(char *err, char **map);
void	exit_msg(int score);
void	exit_errmalloc(char *err, char **map, int pos);
void	end_free(char **map, int score);

#endif
