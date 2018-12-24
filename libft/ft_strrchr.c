/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoustai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 05:35:10 by ymoustai          #+#    #+#             */
/*   Updated: 2018/10/08 05:41:16 by ymoustai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	smb;
	size_t			len;

	smb = (unsigned char)c;
	len = ft_strlen(s);
	while (len > 0 && s[len] != smb)
		len--;
	if (s[len] == smb)
		return ((char *)&s[len]);
	else
		return (NULL);
}
