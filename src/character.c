/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:06:46 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:26:30 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_tonewpos(t_vars *vars, t_character
*player, int newposx, int newposy)
{
	t_asset	floor;
	t_asset	exit;
	int		posx;
	int		posy;

	floor.img = mlx_xpm_file_to_image
		(vars->mlx_ptr, FLOORPATH, &floor.width, &floor.height);
	exit.img = mlx_xpm_file_to_image
		(vars->mlx_ptr, EXITPATH, &exit.width, &exit.height);
	posx = player->posx;
	posy = player->posy;
	if (vars->map[posy][posx] != 'E')
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, floor.img, posx * 32, posy * 32);
	else
		mlx_put_image_to_window
			(vars->mlx_ptr, vars->win_ptr, exit.img, posx * 32, posy * 32);
	mlx_put_image_to_window(vars->mlx_ptr,
		vars->win_ptr, player->img, (newposx * 32) - 10, (newposy * 32) - 6);
	player->posy = newposy;
	player->posx = newposx;
}

void	check_newpos(t_vars *vars,
	t_character *player, int newposx, int newposy)
{
	if (vars->map[newposy][newposx] != '1')
	{
		vars->nbmoves++;
		move_tonewpos(vars, player, newposx, newposy);
		ft_printf("Score : %d\n", vars->nbmoves);
		if (vars->map[newposy][newposx] == 'C')
		{
			vars->nbitemsleft--;
			vars->map[newposy][newposx] = '0';
		}
		else if (vars->map[newposy][newposx] == 'E')
		{
			if (vars->nbitemsleft == 0)
			{
				end_free(vars->map, vars->nbmoves);
			}
			else
				ft_printf("Not yet... %d item(s) left!\n", vars->nbitemsleft);
		}
	}
	else
		move_tonewpos(vars, player, player->posx, player->posy);
}

void	move_player(int keycode, t_vars *vars, t_character *player)
{
	if (keycode == 13)
	{
		player->img = mlx_xpm_file_to_image
			(vars->mlx_ptr, PLAYERUPPATH, &player->width, &player->height);
		check_newpos(vars, player, player->posx, player->posy - 1);
	}
	else if (keycode == 0)
	{
		player->img = mlx_xpm_file_to_image
			(vars->mlx_ptr, PLAYERLEFTPATH, &player->width, &player->height);
		check_newpos(vars, player, player->posx - 1, player->posy);
	}
	else if (keycode == 1)
	{
		player->img = mlx_xpm_file_to_image
			(vars->mlx_ptr, PLAYERDOWNPATH, &player->width, &player->height);
		check_newpos(vars, player, player->posx, player->posy + 1);
	}
	else if (keycode == 2)
	{
		player->img = mlx_xpm_file_to_image
			(vars->mlx_ptr, PLAYERRIGHTPATH, &player->width, &player->height);
		check_newpos(vars, player, player->posx + 1, player->posy);
	}
}
