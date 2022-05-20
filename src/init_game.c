/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:25:38 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:19 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_walls(char **map, t_vars *vars, int i, int j)
{
	t_asset	walls;
	t_asset	floor;

	i = 0;
	walls.img = mlx_xpm_file_to_image
		(vars->mlx_ptr, WALLPATH, &walls.width, &walls.height);
	floor.img = mlx_xpm_file_to_image
		(vars->mlx_ptr, FLOORPATH, &walls.width, &walls.height);
	while (map[i])
	{
		j = 0;
		while (map [i][j])
		{
			if (map[i][j] == '1' && ((i == 0 || i == get_mapsize(map) - 1)
				|| (j == 0 || j == new_strlen(map[0]) - 1)))
				mlx_put_image_to_window
					(vars->mlx_ptr, vars->win_ptr, walls.img, j * 32, i * 32);
			else
				mlx_put_image_to_window
					(vars->mlx_ptr, vars->win_ptr, floor.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	init_items(char **map, t_vars *vars, int i, int j)
{
	t_asset	item;
	t_asset	barrel;

	item.img = mlx_xpm_file_to_image
		(vars->mlx_ptr, ITEMPATH, &item.width, &item.height);
	barrel.img = mlx_xpm_file_to_image
		(vars->mlx_ptr, BARRELPATH, &barrel.width, &barrel.height);
	while (i < get_mapsize(map) - 1)
	{
		j = 1;
		while (j < new_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'C')
			{
				vars->nbitemsleft++;
				mlx_put_image_to_window
					(vars->mlx_ptr, vars->win_ptr, item.img, j * 32, i * 32);
			}
			else if (map[i][j] == '1')
				mlx_put_image_to_window
					(vars->mlx_ptr, vars->win_ptr, barrel.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	init_gameplay(char **map, t_vars *vars, t_character *player)
{
	int		i;
	int		j;

	i = 1;
	player->img = mlx_xpm_file_to_image
		(vars->mlx_ptr, PLAYERDOWNPATH, &player->width, &player->height);
	vars->nbmoves = 0;
	while (i < get_mapsize(map) - 1)
	{
		j = 1;
		while (j < new_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'P')
			{
				mlx_put_image_to_window(vars->mlx_ptr,
					vars->win_ptr, player->img, (j * 32) - 10, (i * 32) - 6);
				player->posx = j;
				player->posy = i;
			}
			j++;
		}
		i++;
	}
}

void	init_exit(char **map, t_vars *vars, int i, int j)
{
	t_asset	exit;

	exit.img = mlx_xpm_file_to_image
		(vars->mlx_ptr, EXITPATH, &exit.width, &exit.height);
	while (i < get_mapsize(map) - 1)
	{
		j = 1;
		while (j < new_strlen(map[i]) - 1)
		{
			if (map[i][j] == 'E')
				mlx_put_image_to_window
					(vars->mlx_ptr, vars->win_ptr, exit.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	init_game(char **map, t_vars *vars, t_character *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	vars->nbitemsleft = 0;
	init_walls(map, vars, i, j);
	i = 1;
	init_items(map, vars, i, j);
	init_exit(map, vars, i, j);
	init_gameplay(map, vars, player);
	ft_printf("Score : %d\n", vars->nbmoves);
}
