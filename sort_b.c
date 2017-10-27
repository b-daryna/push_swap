/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 11:37:40 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_b(t_data *data, int len, int unsorted, int mid_div)
{
	t_stack	*stack_b;
	int		stack_size;
	int		piece_size;
	int		divider;

	if (!(stack_b = (t_stack*)malloc(sizeof(t_stack))))
		return ;
	data->first_go = 0;
	if (len <= 3)
		sort_b(unsorted, len, data, stack_b);
	else
	{
		stack_size = stack_length(data->b);
		stack_b->div = mid_div;
		piece_size = sort_by_half_b(data, unsorted, stack_b);
		if (len != stack_size)
			bring_up_sorted_elems(data, len - unsorted + stack_b->m_d, "rrb");
		get_middle_element(data->b, len - piece_size, stack_b);
		divider = stack_b->div;
		free(stack_b);
		sort_stack_a(data, piece_size);
		sort_stack_b(data, len - piece_size, len - piece_size, divider);
	}
}

void	sort_b(int unsorted, int len, t_data *data, t_stack *stack_b)
{
	if (unsorted != len)
		bring_up_sorted_elems(data, len - unsorted, "rrb");
	if (stack_length(data->b) == 3)
		sort_three_b(*(int*)data->b->content, *(int*)data->b->next->content,\
				*(int*)data->b->next->next->content, data);
	else
		stack_3_elems(data, len, 'b', data->b);
	free(stack_b);
}

int		sort_by_half_b(t_data *data, int len, t_stack *st)
{
	int i;
	int piece_size;

	i = 0;
	piece_size = 0;
	st->m_d = 0;
	while (i++ < len)
	{
		if (*(int *)data->b->content >= st->div)
		{
			execute("pa", data, 1);
			piece_size++;
		}
		else if (next_elems_are_bigger(len - piece_size - st->m_d,\
					st->div, data->b))
		{
			execute("rb", data, 1);
			st->m_d++;
		}
	}
	return (piece_size);
}

void	sort_three_b(int a, int b, int c, t_data *data)
{
	if (a < b || b < c)
	{
		if (a > b)
		{
			if (a < c)
				execute("rrb", data, 1);
			else
				execute("rrb,sb", data, 1);
		}
		else
		{
			if (b < c)
				execute("sb,rrb", data, 1);
			else if (a < c)
				execute("rb", data, 1);
			else
				execute("sb", data, 1);
		}
	}
	execute("pa,pa,pa", data, 1);
}
