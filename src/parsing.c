/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:39:02 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:27 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

static int	get_colsize(int fd)
{
	int		size;
	char	*str;

	size = 0;
	str = get_next_line(fd);
	if (str)
		size++;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (str)
			size++;
	}
	free(str);
	return (size);
}

static char	*set_rowdata(char *map, char *str)
{
	int	j;
	int	size;

	j = 0;
	size = new_strlen(str);
	while (j < size)
	{
		if (str[j] != '\n')
			map[j] = str[j];
		else
			break ;
		j++;
	}
	map[j] = '\0';
	return (map);
}

static char	**set_mapdata(char **map, int nbrow, int fd)
{
	int		i;
	char	*str;

	i = 0;
	while (i < nbrow)
	{
		str = get_next_line(fd);
		map[i] = (char *) malloc(sizeof(char) * new_strlen(str));
		if (!map[i])
			exit_errmalloc("Malloc failed\n", map, i);
		map[i] = set_rowdata(map[i], str);
		free(str);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**parsingdata(char *file)
{
	char	**map;
	int		fd;
	int		nbrow;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_errmsg("File opening failed\n");
	nbrow = get_colsize(fd);
	if (nbrow == 0)
		exit_errmsg(".ber file is empty\n");
	map = (char **) malloc(sizeof(char *) * (nbrow + 1));
	if (!map)
		exit_errmsg("Malloc failed\n");
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_free("File opening failed\n", map);
	map = set_mapdata(map, nbrow, fd);
	close(fd);
	return (map);
}
