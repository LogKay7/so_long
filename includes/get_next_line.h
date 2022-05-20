/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:42:26 by lkailany          #+#    #+#             */
/*   Updated: 2022/03/16 15:41:52 by lkailany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_splitline(char *linejoined);
char	*ft_strjoin(char *linejoined, char *buff);
char	*ft_joinlines(char *linejoined, char *newstr, char *buff);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*ft_save_endline(char *linejoined);
char	*ft_read_to_newline(int fd, char *linejoined);
#endif
