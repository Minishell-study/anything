/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:11:14 by inyang            #+#    #+#             */
/*   Updated: 2021/07/02 20:11:50 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main(int ac, char **av)
{
	int		i;
	int	*changed;
	char	*line;
	int		length;

	line = av[1];
	length = px_strlen(line);
	changed = ((int *)malloc(sizeof(int) * length));
	i = 0;
	while (i < length)
		changed[i++] = 5;
	printf("%s\n", line);
	printf("%d\n", length);
	i = 0;
	while (line[i])
	{
		printf("i = %d, %c\n", i, line[i]);
		if (line[i] >= 'a' && line[i] <= 'z')
			changed[i] = 0;
		else if (line[i] == ' ' || line[i] == '\t')
			changed[i] = 2;
		else if (line[i] == 34)
		{
			changed[i] = 3;
			while (line[++i])
			{
				if (line[i + 1] != 34)
					changed[i] = 1;
				else if (line[i + 1] == 34)
				{
					changed[i] = 1;
					changed[i + 1] = 3;
					i += 2;
					break;
				}
			}
		}
		else 
			changed[i] = 9;
		i++;
	}
	printf("fin?\n");
	i = 0;
	while (i < length)
		printf("%d ", changed[i++]);
	return (0);
}
