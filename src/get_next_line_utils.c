/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:21:02 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/31 12:27:51 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	char	search;

	search = c;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == search)
			return ((char *)(str));
		str++;
	}
	if (search == '\0')
		return ((char *)(str));
	return (0);
}

char	*ft_joinlines(char *linejoined, char *newstr, char *buff)
{
	int	i;

	i = 0;
	while (linejoined[i])
	{
		newstr[i] = linejoined[i];
		i++;
	}
	while (*buff)
	{
		newstr[i] = *buff;
		i++;
		buff++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char *linejoined, char *buff)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!linejoined)
	{
		linejoined = (char *) malloc(sizeof (char) * 1);
		if (!linejoined)
			return (NULL);
		linejoined[0] = '\0';
	}
	if (!buff)
		return (NULL);
	newstr = malloc(ft_strlen(linejoined) + ft_strlen(buff) + 1);
	if (!newstr)
		return (NULL);
	newstr = ft_joinlines(linejoined, newstr, buff);
	free(linejoined);
	return (newstr);
}

char	*ft_splitline(char *linejoined)
{
	char	*line;
	int		i;

	i = 0;
	if (!linejoined || linejoined[0] == '\0')
		return (NULL);
	while (linejoined[i] && linejoined[i] != '\n')
		i++;
	line = malloc(sizeof (char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (linejoined[i] && linejoined[i] != '\n')
	{
		line[i] = linejoined[i];
		i++;
	}
	if (linejoined[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}
