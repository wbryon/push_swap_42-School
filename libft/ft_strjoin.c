/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:14:12 by wbryon            #+#    #+#             */
/*   Updated: 2021/04/16 14:49:00 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;

	if (!s1 || !s2)
		return (0);
	strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoin)
		return (0);
	ft_strlcpy(strjoin, s1, ft_strlen(s1) + 1);
	ft_strlcat(strjoin, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (strjoin);
}
