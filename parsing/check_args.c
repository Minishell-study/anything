/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:17:22 by inyang            #+#    #+#             */
/*   Updated: 2021/07/08 17:00:30 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void		check_arguments(t_all *a)
{
	int		i;
	int		j;
	int		k;
	char	*line_dup;
	char	**line_dup_zip;
	t_all	*b;
	int		cnt_two;

	i = 0;
	b = a;
	while (b->line_cut[i])
	{
		if (b->line_cut[i] == 2)
			cnt_two++;
		i++;
	}
	line_dup_zip = ft_calloc(sizeof(char *), (cnt_two + 1);
	i = 0;
	j = 0;
	k = 0;
	while (b)
	{
		// temp = ft_split()
		while (int_line_cut[i])
		{
			if (int_line_cut[i] == 2)
			{
				line_dup[i] = '\0';
				line_dup_zip[k] = ft_strdup(&line_dup[j]);
				j = i + 1;
				k++;
			}
			i++;
		}
		
		printf("%s\n", line_dup_zip[k]);
		b = b->next;
	}
}
