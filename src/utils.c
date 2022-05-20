/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:40:30 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:30 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	new_strlen(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '\n' || str[j] == '\0')
			return (j);
		j++;
	}
	return (j);
}

int	get_mapsize(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_heightsize(char **map)
{
	int	size;

	size = get_mapsize(map) * ASSETS_SIZE;
	return (size);
}

int	get_widthsize(char **map)
{
	int	size;

	size = new_strlen(map[0]) * ASSETS_SIZE;
	return (size);
}
