/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:55:43 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/21 15:23:28 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "ft_21sh.h"

int		main(int ac, char **av, char **env)
{
	char	**envd;

	(void)ac;
	(void)av;
	envd = ft_cpy_db_tab(env);
	ft_21sh(envd);
	return (0);
}
