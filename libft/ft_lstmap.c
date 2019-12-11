/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:56:00 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/29 13:46:32 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *holder;

	if (!(holder = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	newlst = f(lst);
	holder = newlst;
	lst = lst->next;
	while (lst)
	{
		newlst->next = f(lst);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (holder);
}
