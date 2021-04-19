/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:49:55 by wbryon            #+#    #+#             */
/*   Updated: 2021/04/16 15:00:19 by wbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (0);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, len + 1);
	if (start > ft_strlen(s))
		return (dest);
	else
		ft_memmove(dest, (char *)s + start, len);
	return (dest);
}
