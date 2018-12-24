/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoustai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 03:19:51 by ymoustai          #+#    #+#             */
/*   Updated: 2018/10/08 03:34:40 by ymoustai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_sign(const char **str)
{
	int sign;

	sign = 1;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		*str += 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		*str += 1;
	}
	while (**str == '0')
		*str += 1;
	return (sign);
}

int			ft_atoi(const char *str)
{
	unsigned long int	res;
	int					sign;
	int					i;

	res = 0;
	i = 0;
	sign = ft_get_sign(&str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if ((res > 9223372036854775807 || i > 19) && sign == 1)
		return (-1);
	else if ((res > 9223372036854775807 || i > 19) && sign == -1)
		return (0);
	return ((int)(res * sign));
}
