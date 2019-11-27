/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:24:24 by jsalmi            #+#    #+#             */
/*   Updated: 2019/10/23 10:40:02 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	while ((*alst)->next != NULL)
	{
		temp = (*alst)->next;
		ft_lstdelone(&*alst, del);
		*alst = temp;
	}
	ft_lstdelone(&*alst, del);
	*alst = NULL;
}
