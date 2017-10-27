/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 11:39:23 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_length(t_list *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	stack_3_elems(t_data *data, int len, char stack, t_list *lst)
{
	int i;

	i = 0;
	if (three_elems_not_sorted(lst, stack, len))
	{
		if (len == 2 && stack == 'a')
			execute("sa", data, 1);
		else if (len == 2 && stack == 'b')
			execute("sb,pa,pa", data, 1);
		else if (len == 3 && stack == 'a')
			three_in_a(*(int*)data->a->content, *(int*)data->a->next->content,\
					*(int*)data->a->next->next->content, data);
		else if (len == 3 && stack == 'b')
			three_in_b(*(int*)data->b->content, *(int*)data->b->next->content,\
					*(int*)data->b->next->next->content, data);
	}
	else if (stack == 'b')
	{
		while (i++ < len)
			execute("pa", data, 1);
	}
}

int		three_elems_not_sorted(t_list *lst, char stack, int len)
{
	int i;

	i = 1;
	if (stack == 'a')
	{
		while (i < len)
		{
			if (*(int*)lst->content > *(int*)lst->next->content)
				return (1);
			lst = lst->next;
			i++;
		}
		return (0);
	}
	else
	{
		while (i < len)
		{
			if (*(int*)lst->content < *(int*)lst->next->content)
				return (1);
			lst = lst->next;
			i++;
		}
		return (0);
	}
}

void	three_in_b(int a, int b, int c, t_data *data)
{
	if (a > b)
	{
		if (a > c)
			execute("pa,sb,pa,pa", data, 1);
		else
			execute("rb,sb,pa,rrb,pa,pa", data, 1);
	}
	else
	{
		if (a > c)
			execute("sb,pa,pa,pa", data, 1);
		else if (b > c)
			execute("sb,pa,sb,pa,pa", data, 1);
		else
			execute("rb,sb,pa,pa,rrb,pa", data, 1);
	}
}

void	three_in_a(int a, int b, int c, t_data *data)
{
	if (a > b)
	{
		if (a < c)
			execute("sa", data, 1);
		else if (b < c)
			execute("sa,pb,sa,pa", data, 1);
		else
			execute("ra,sa,pb,rra,sa,pa", data, 1);
	}
	else
	{
		if (a > c)
			execute("pb,sa,pb,sb,pa,pa", data, 1);
		else
			execute("pb,sa,pa", data, 1);
	}
}
