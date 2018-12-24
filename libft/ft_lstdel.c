/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoustai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 03:45:43 by ymoustai          #+#    #+#             */
/*   Updated: 2018/10/08 03:55:44 by ymoustai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*buf;

	buf = *alst;
	if (del)
	{
		while (buf)
		{
			tmp = buf->next;
			del(buf->content, buf->content_size);
			free(buf);
			buf = tmp;
		}
		*alst = NULL;
	}
}
