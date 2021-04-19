/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:45:22 by wbryon            #+#    #+#             */
/*   Updated: 2021/04/16 14:59:05 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	begin;

	begin = 0;
	if (s1 == 0 || set == 0)
		return (0);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	begin = ft_strlen(s1);
	while (begin != 0 && ft_strrchr(set, s1[begin]))
		begin--;
	strtrim = ft_substr((char *)s1, 0, begin + 1);
	return (strtrim);
}
