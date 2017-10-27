/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 11:35:55 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_data *data, int len)
{
	t_stack *stack_a;

	if (stack_is_sorted(data->a, len))
		return ;
	if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
		return ;
	if (len <= 3)
	{
		if (stack_length(data->a) == 3)
			sort_three(*(int*)data->a->content, *(int*)data->a->next->content,\
					*(int*)data->a->next->next->content, data);
		else
			stack_3_elems(data, len, 'a', data->a);
		free(stack_a);
	}
	else
		sort_a_helper(data, len, stack_a);
}

void	sort_a_helper(t_data *data, int len, t_stack *stack_a)
{
	int piece_size;
	int stack_size;
	int mid_div;
	int unsorted;

	stack_size = stack_length(data->a);
	get_middle_element(data->a, len, stack_a);
	piece_size = sort_by_half_a(data, len, stack_a);
	if (!data->first_go && len != stack_size)
		bring_up_sorted_elems(data, stack_a->m_d, "rra");
	unsorted = stack_a->unsorted_size;
	mid_div = stack_a->mid_div;
	free(stack_a);
	sort_stack_a(data, len - piece_size);
	if (data->b != NULL)
		sort_stack_b(data, piece_size, unsorted, mid_div);
}

int		sort_by_half_a(t_data *data, int len, t_stack *stack)
{
	int		i;
	int		piece_size;
	char	*prev_command;

	i = 0;
	prev_command = "rr";
	stack->prev_num = 0;
	piece_size = 0;
	stack->unsorted_size = 0;
	stack->m_d = 0;
	while (i++ < len)
	{
		if (*(int*)data->a->content < stack->div)
		{
			stack->prev_num = *(int*)data->a->content;
			prev_command = "pb";
			execute("pb", data, 1);
			piece_size++;
			stack->unsorted_size++;
		}
		else if (next_elems_are_smaller(len - piece_size - stack->m_d,\
					stack->div, data->a))
			prev_command = make_rr(data, len, stack, prev_command);
	}
	return (piece_size);
}

char	*make_rr(t_data *data, int len, t_stack *st, char *prev_com)
{
	char *command;

	command = prev_com;
	if (st->prev_num < st->mid_div && data->b != NULL && data->b->next\
			!= NULL && ft_strcmp(prev_com, "rr") && len > 6)
	{
		execute("rr", data, 1);
		command = "rr";
		st->unsorted_size--;
	}
	else
		execute("ra", data, 1);
	st->m_d++;
	return (command);
}

void	sort_three(int a, int b, int c, t_data *data)
{
	if (a < b && b < c)
		return ;
	if (a > b)
	{
		if (a < c)
			execute("sa", data, 1);
		else if (b < c)
			execute("ra", data, 1);
		else
			execute("ra,sa", data, 1);
	}
	else
	{
		if (a > c)
			execute("rra", data, 1);
		else if (b > c)
			execute("sa,ra", data, 1);
	}
}
