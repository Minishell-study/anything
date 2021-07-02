/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:11:14 by inyang            #+#    #+#             */
/*   Updated: 2021/07/02 22:07:27 by ylee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int redir_name(char *line, int *changed, int i)
{
	if (line[i] == '<')
	{
		changed[i] = 6;
	}
	else if (line[i] == '>')
	{
		changed[i] = 7;
	}
	else
		printf("error redir_name\n");
	return (i);
}

int	env_name(char *line, int *changed, int i)
{
	changed[i] = 5;
	while (line[++i])
	{
		if ((line[i] >= 'A' && line[i] <= 'Z') ||
				(line[i] >= 'a' && line[i] <= 'z') ||
				(line[i] >= '0' && line[i] <= '9') ||
				(line[i] == '_'))
			changed[i] = 5;
		else
			break ;
	}
	return (i - 1);
}

int	s_quote(char *line, int *changed, int i)
{
	changed[i] = 4;
	while (line[++i])
	{
		if (line[i + 1] != '\'')
			changed[i] = 1;
		else if (line[i + 1] == '\'')
		{
			changed[i] = 1;
			changed[i + 1] = 4;
			i++;
			break;
		}
	}
	return (i);
}

int	d_quote(char *line, int *changed, int i)
{
	changed[i] = 3;
	while (line[++i])
	{
		if (line[i] == '$')
			i = env_name(line, changed, i);
		else if (line[i + 1] != '\"')
			changed[i] = 1;
		else if (line[i + 1] == '\"')
		{
			changed[i] = 1;
			changed[i + 1] = 3;
			i++;
			break;
		}
	}
	return (i);
}

int	parsing(char *line)
{
	int		i;
	int		*changed;
	int		length;

	length = px_strlen(line);
	changed = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
		changed[i++] = 1111111;
	printf("%s\n", line);
	printf("%d\n", length);
	i = 0;
	while (line[i])
	{
		if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
			changed[i] = 0;
		else if (line[i] == ' ' || line[i] == '\t')
			changed[i] = 2;
		else if (line[i] == '\"')
			i = d_quote(line, changed, i);
		else if (line[i] == '\'')
			i = s_quote(line, changed, i);
		else if (line[i] == '$')
			i = env_name(line, changed, i);
		else if (line[i] == '<' || line[i] == '>')
			i = redir_name(line, changed, i);
		else if (line[i] == '|') 
			changed[i] = 8;
		else 
			changed[i] = 9;
		i++;
	}
	printf("fin?\n");
	i = 0;
	while (i < length)
	{
		printf("%c : %d\n", line[i], changed[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	if (argc != 1 || !argv || !envp)
		return (0);
	printf("test1\n");
	line = "hello \"inyang\". I`m \'ylee\'. good bye~ $PWD";
	parsing(line);
	printf("test2\n");
	line = "echo \'$PWD is here\' and \"$PWD is here\" | cat << ylee | wc -l";
	parsing(line);
	return (0);
}
