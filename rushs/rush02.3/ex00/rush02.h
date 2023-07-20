/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryanik <eryanik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:34:23 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/16 23:16:29 by eryanik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H 
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict	t_dict;

struct s_dict
{
	int		n;
	char	*str;
	t_dict	*nxt;
};

typedef struct s_list
{
	t_dict	*first;
}	t_list;

int		ft_check_ln(char *ln);
t_dict	*ft_last_dict(t_dict *current);
t_dict	*ft_create_dict(char *ln, t_list dict);
int		ft_strlen(char *str);
int		ft_test_free(char *to_test, char *to_free);
char	*ft_init_ln(char *src, char	*dst);
char	*ft_copy(char *dst, char *src);
t_list	*ft_dict_parsing(int file);
int		ft_check_double(int n, t_dict *current);
int		ft_atoi(char *str);

#endif
