/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:17:22 by inyang            #+#    #+#             */
/*   Updated: 2021/07/13 03:40:50 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	ft_cnt(int *s, int c, int strlen)
{
	size_t	cnt;
	int		*tmp;
	int		i;

	cnt = 0;
	tmp = s;
	i = 0;
	while (i < strlen)
	{
		if (tmp[i] == c)
			i++;
		else
		{
			while (i <= strlen && tmp[i] != c)
				i++;
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

static size_t	ft_index(size_t i, int *s, int c, int strlen)
{
	size_t	cnt;

	cnt = 0;
	while (s[i] != c && i < strlen)
	{
		i++;
		cnt++;
	}
	return (cnt);
}

static int		ft_fill(int *int_line, char const *s, int c, char **all, int strlen)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	size_t	cnt;

	i = 0;
	k = 0;
	/* 무슨 문장 들어왔나 체크용 */
	printf("command line : %s\n",s);
	/* 여기까지 */
	while (i <= strlen)
	{
		while (int_line[i] == c && i < strlen)
			i++;
		if (i >= strlen)
			break ;
		cnt = ft_index(i, int_line, c, strlen);
		i += cnt;
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

char			**split_args(int *int_line, char *s, int c)
{
	size_t	len;
	char	**all;
	int		strlen;

	if (!s)
		return (NULL);
	strlen = px_strlen(s);
	len = ft_cnt(int_line, c, strlen);
	if (!(all = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	int check;
	if ((check = ft_fill(int_line, s, c, all, strlen)) != 0)
		return (NULL);
	all[len] = NULL;
	return (all);
}

void		check_arguments(t_all *a)
{
	int		i;
	int		j;
	t_all	*b;

	b = a;
	while (b)
	{
		printf("\n->->-> split start point <-<-<-\n");
		b->cmd = NULL; // 초기화를 여기서 하지 않고 init에서 하면 세그폴트가 남 왜??
		b->arg = split_args(b->int_line_cut, b->line_cut, 2);
		i = -1;
		while (b->arg[++i])
		{
			j = 0;
			if (b->arg[i][j] == '>')
			{
				if (b->arg[i][j + 1] == '>' && b->arg[i][j + 2] == ' ')
				{
					j = j + 3;
					b->redir_list->redir_flag = 4;
				}
				else if (b->arg[i][j + 1] == ' ')
				{
					j = j + 2;
					b->redir_list->redir_flag = 2;
				}
				b->redir_list->file = ft_strdup(&b->arg[i][j]);
			}
			else if (b->arg[i][j] == '<')
			{
				if (b->arg[i][j + 1] == '<' && b->arg[i][j + 2] == ' ')
				{
					j = j + 3;
					b->redir_list->redir_flag = 3;
				}
				else if (b->arg[i][j + 1] == ' ')
				{
					j = j + 2;
					b->redir_list->redir_flag = 1;
				}
				b->redir_list->file = ft_strdup(&b->arg[i][j]);
			}
			else
				b->cmd = b->arg[0];
		}
			// else if (b->arg[0][i] == '<')
		/* 잘 들어갔나 체크용 */
		printf("********* result *********\n");
		printf("b->cmd = %s\n", b->cmd);
		int k = 0;
		while (b->arg[k])
		{
			printf("arg[%d] %s\n", k, b->arg[k]);
			k++;
			printf("%d %s\n",b->redir_list->redir_flag, b->redir_list->file);
		}
		/* 여기까지 지우기 */
		b = b->next;
	}
	printf("\n\n");
}
