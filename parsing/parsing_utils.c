/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:33:58 by inyang            #+#    #+#             */
/*   Updated: 2021/07/02 19:34:02 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	ft_cnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
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
	if (!(all[k] = malloc(cnt + 1)))
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

static size_t	ft_index(size_t *i, char const *s, char c)
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

static int		ft_fill(char const *s, char c, char **all)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;
	size_t	cnt;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		cnt = ft_index(&i, s, c);
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

char			**ft_split(char const *s, char c)
{
	size_t	len;
	char	**all;

	if (!s)
		return (NULL);
	len = ft_cnt(s, c);
	if (!(all = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	if (ft_fill(s, c, all))
		return (NULL);
	all[len] = NULL;
	return (all);
}

int		px_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*px_strjoin(char *s1, char *s2)
{
	int		i;
	char	*buf;

	if (!(buf = malloc(sizeof(char) * (px_strlen(s1) + px_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		buf[i++] = *s1++;
	while (*s2)
		buf[i++] = *s2++;
	buf[i] = '\0';
	return (buf);
}

int		px_gnl(char **line)
{
	int		size;
	char	buf[2];
	char	*store;
	char	*temp;

	size = 1;
	store = px_strjoin("", "");
	buf[size] = '\0';
	while (size && buf[0] != '\n')
	{
		size = read(0, buf, 1);
		if (size <= 0)
			return (0);
		if (buf[0] != '\n' && size != 0)
		{
			temp = px_strjoin(store, buf);
			free(store);
			store = temp;
		}
	}
	*line = store;
	return (size);
}
