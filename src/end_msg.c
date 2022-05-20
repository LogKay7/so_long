/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:41:41 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:17 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_errmsg(char *err)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (err[i])
	{
		write(2, &err[i], 1);
		i++;
	}
	exit(-1);
}

void	exit_free(char *err, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	exit_errmsg(err);
}

void	exit_errmalloc(char *err, char **map, int pos)
{
	pos--;
	while (pos >= 0)
	{
		free(map[pos]);
		pos--;
	}
	free(map);
	exit_errmsg(err);
}

void	exit_msg(int score)
{
	ft_printf("Game closed. Final score : %d\n", score);
}

void	end_free(char **map, int score)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_printf("You win!! Final score : %d\n", score);
	exit(0);
}
