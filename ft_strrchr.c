/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:37:20 by vwaldon           #+#    #+#             */
/*   Updated: 2021/10/25 17:52:30 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = 0;
	while (*str)
	{
		if (*str == (char)c)
			ptr = (char *) str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *) str);
	return ((char *) ptr);
}
