/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:38:19 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:22 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	closewindow(t_vars *vars)
{
	exit_msg(vars->nbmoves);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	exit(0);
}

int	key_pressed(int keycode, t_vars *vars)
{
	if (keycode == 13 || (keycode >= 0 && keycode <= 2))
		move_player(keycode, vars, &vars->player);
	else if (keycode == 53)
	{
		closewindow(vars);
	}
	return (0);
}

void	check_filename(char *mapname, char *ext)
{
	while (*mapname && *mapname != *ext)
		mapname++;
	while (*mapname == *ext && *mapname && *ext)
	{
		mapname++;
		ext++;
	}
	if (*mapname || *ext)
		exit_errmsg("Invalid map extension : Use .ber extension");
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		exit_errmsg("Error : Invalid number of arguments. Send a .ber file\n");
	check_filename(argv[1], ".ber");
	vars.map = parsingdata(argv[1]);
	check_mapdata(vars.map);
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr,
			get_widthsize(vars.map), get_heightsize(vars.map), "So_long");
	init_game(vars.map, &vars, &vars.player);
	mlx_key_hook(vars.win_ptr, key_pressed, &vars);
	mlx_hook(vars.win_ptr, 17, 0L, closewindow, &vars);
	mlx_loop(vars.mlx_ptr);
}
