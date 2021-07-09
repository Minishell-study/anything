/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:17:22 by inyang            #+#    #+#             */
/*   Updated: 2021/07/09 17:43:38 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	ft_cnt(int *s, int c)
{
	size_t	cnt;
	int		*tmp;
	int		i;

	cnt = 0;
	tmp = s;
	i = 0;
	while (tmp)
	{
		printf("%d, ", *tmp);
		tmp++;
		i++;
	}
	printf("*****************\n");
	printf("%d", i);
	while (*s)
	{
		printf("<<<<<<<<<<<<<<<<<\n");
		printf("ft_cnt // *s : %d ,  c : %d\n", *s, c);
		if (*s == c)
			s++;
		else
		{
			while (*s && *s != c)
				s++;
			cnt++;
		}
	}
	return (cnt);
}

static int		ft_n_malloc(char **all, size_t k, size_t cnt)
{
	if (!(all[k] = malloc(sizeof(char) * (cnt + 1))))
	{
		while (k > 0)
		{
			k--;
			free(all[k]);
		}
		free(all);
		return (1);
	}
	return (0);
}

static size_t	ft_index(size_t *i, int *s, int c)
{
	size_t	cnt;

	cnt = 0;
	while (s[*i] != c && s[*i])
	{
		(*i)++;
		cnt++;
	}
	return (cnt);
}

static int		ft_fill(int *int_line, char const *s, int c, char **all)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	size_t	cnt;

	i = 0;
	k = 0;
	while (int_line[i])
	{
		while (int_line[i] == c)
			i++;
		if (!int_line[i])
			break ;
		cnt = ft_index(&i, int_line, c);
		if (ft_n_malloc(all, k, cnt))
			return (1);
		l = 0;
		j = i - cnt;
		while (j < i)
			all[k][l++] = (char)s[j++];
		all[k++][l] = '\0';
	}
	return (0);
}

char			**ft_split(int *int_line, char *s, int c)
{
	size_t	len;
	char	**all;

	if (!s)
		return (NULL);
	len = ft_cnt(int_line, c);
	printf("\n\n******ft_cnt return %zu\n", len);
	if (!(all = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	int check;
	if ((check = ft_fill(int_line, s, c, all)) != 0)
	{
		printf("\n\n*****ft_fill return %d\n", check);
		return (NULL);
	}
	all[len] = NULL;
	return (all);
}

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
	// while (b->line_cut[i])
	// {
	// 	if (b->line_cut[i] == 2)
	// 		cnt_two++;
	// 	i++;
	// }
	// line_dup_zip = ft_calloc(sizeof(char *), (cnt_two + 1);
	// i = 0;
	// j = 0;
	// k = 0;
	while (b)
	{
		b->arg = ft_split(b->int_line_cut, b->line_cut, 2);
		printf("엥ㅇㅇ레노매돌ㄴㅁ디럼니댜ㅜㄹ미\n");
		printf("arg[0] %s\n", b->arg[0]);
		// while (int_line_cut[i])
		// {
		// 	if (int_line_cut[i] == 2)
		// 	{
		// 		line_dup[i] = '\0';
		// 		line_dup_zip[k] = ft_strdup(&line_dup[j]);
		// 		j = i + 1;
		// 		k++;
		// 	}
		// 	i++;
		// }
		// k = 0;
		// while (k)
		// 	printf("*******************************%s\n", b->arg[k++]);
		b = b->next;
	}
}
