/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:36:13 by vwaldon           #+#    #+#             */
/*   Updated: 2021/10/21 22:53:40 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *large, const char *small, size_t len)
{
	size_t	l;

	l = ft_strlen(small);
	if (*small == 0)
		return ((char *)large);
	while (*large && len >= l)
	{
		if (ft_strncmp(large, small, l) == 0)
			return ((char *)large);
		large++;
		len--;
	}
	return (NULL);
}
