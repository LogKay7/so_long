/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:37:10 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:13 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

void	check_mapsize(char **map, int i, int sizerow)
{
	while (map[i])
	{
		if (sizerow == new_strlen(map[i]))
			i++;
		else
			exit_free("Incorrect map dimensions. Rows have \135 sizes", map);
	}
	if (i == sizerow)
		exit_free("Incorrect map dimensions. Map can't be a square\n", map);
}

void	check_walls(char **map, int i, int j, int sizerow)
{
	while (map[i])
	{
		j = 0;
		sizerow = new_strlen(map[i]) - 1;
		if (i == 0 || i == get_mapsize(map) - 1)
		{
			while (map[i][j])
			{
				if (map[i][j] != '1')
					exit_free("Incorrect value in map. Check the walls\n", map);
				j++;
			}
		}
		else
		{
			if (map[i][0] != '1' || map[i][sizerow] != '1')
				exit_free("Incorrect value in map. Check the walls\n", map);
		}
		i++;
	}
}

void	check_values(char **map, int i, int j, int mapsize)
{
	while (i < mapsize)
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
			&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				exit_free("Unknown value(s) found in map\n", map);
			j++;
		}
		i++;
	}
}

void	check_gameplay(char **map, int i, int j, int mapsize)
{
	t_mapdata	mapdata;

	mapdata.nbexit = 0;
	mapdata.nbitem = 0;
	mapdata.nbstart = 0;
	while (i < mapsize)
	{
		j = 1;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mapdata.nbexit++;
			else if (map[i][j] == 'E')
				mapdata.nbitem++;
			else if (map[i][j] == 'P')
				mapdata.nbstart++;
			j++;
		}
		i++;
	}
	if (!(mapdata.nbexit > 0 && mapdata.nbitem >= 1 && mapdata.nbstart == 1))
		exit_free("Game is not playable with these parameters\n", map);
}

void	check_mapdata(char **map)
{
	int	i;
	int	j;
	int	mapsize;
	int	sizerow;

	i = 0;
	j = 0;
	mapsize = get_mapsize(map) - 1;
	sizerow = new_strlen(map[0]);
	check_mapsize(map, i, sizerow);
	check_walls(map, i, j, sizerow);
	i = 1;
	check_values(map, i, j, mapsize);
	check_gameplay(map, i, j, mapsize);
}
