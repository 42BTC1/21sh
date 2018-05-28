/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_soudeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:03:55 by viclucas          #+#    #+#             */
/*   Updated: 2018/04/05 15:11:48 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_souder(char *s1, char *s2, char *s3)
{
	char	*name;
	char	*ret;

	name = ft_strjoin(s1, s3);
	ret = ft_strjoin(name, s2);
	ft_strdel(&name);
	return (ret);
}
