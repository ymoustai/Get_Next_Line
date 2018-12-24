/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoustai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 05:41:56 by ymoustai          #+#    #+#             */
/*   Updated: 2018/10/08 05:45:18 by ymoustai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*start;
	char	*end;
	char	tmp;

	start = str;
	end = str + ft_strlen(str) - 1;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = *start;
		start++;
		end--;
	}
	return (str);
}
