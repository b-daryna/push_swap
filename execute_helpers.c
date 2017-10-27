/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 11:09:17 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_first_two(t_list *head)
{
	t_list *tmp;

	tmp = head;
	swap((int*)&tmp->content, (int*)&tmp->next->content);
}

t_list	*move_first(t_list *lst, t_list *elem)
{
	t_list *tmp;

	tmp = lst;
	if (tmp != NULL && tmp->next != NULL)
	{
		lst = lst->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = elem;
		elem->next = NULL;
	}
	return (lst);
}

t_list	*move_last(t_list *lst)
{
	t_list *last;
	t_list *prev;

	last = lst;
	prev = NULL;
	if (lst != NULL && lst->next != NULL)
	{
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = lst;
		lst = last;
	}
	return (lst);
}

void	push(t_list **from, t_list **to)
{
	t_list *tmp;
	t_list *tmp1;

	tmp = (*from)->next;
	tmp1 = *to;
	*to = *from;
	(*to)->next = tmp1;
	*from = tmp;
}
