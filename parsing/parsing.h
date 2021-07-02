/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inyang <inyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:09:50 by inyang            #+#    #+#             */
/*   Updated: 2021/07/02 19:34:54 by inyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_flag{
	int			double_quote;
	int			single_quote;
	int			pipe;
	int			redirection;
	int			double_redirection;
}				t_flag;

typedef struct	s_token{
	char		*token;
	int			token_len;
	t_flag		is_in;
}				t_token;

typedef	struct	s_all{
	t_token		pipe_token;
	
}				t_all;


char			**ft_split(char const *s, char c);
int				px_gnl(char **line);
int				px_strlen(char *s);

#endif