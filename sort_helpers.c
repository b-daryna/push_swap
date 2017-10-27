/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 13:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 11:38:38 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_middle_element(t_list *lst, int len, t_stack *stack)
{
	t_list	*ptr;
	int		arr[len];
	int		i;
	int		j;

	i = 0;
	ptr = lst;
	while (i < len)
	{
		arr[i++] = *(int*)ptr->content;
		ptr = ptr->next;
	}
	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
	stack->mid_div = arr[len / 4];
	stack->div = arr[len / 2];
}

void	bring_up_sorted_elems(t_data *data, int size, char *str)
{
	while (size > 0)
	{
		execute(str, data, 1);
		size--;
	}
}

int		next_elems_are_smaller(int len, int divider, t_list *stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack;
	while (i < len)
	{
		if (*(int*)tmp->content < divider)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int		next_elems_are_bigger(int len, int divider, t_list *stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack;
	while (i < len)
	{
		if (*(int*)tmp->content > divider)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
