/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 11:06:57 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first(char *instr, t_data *data)
{
	if (ft_strcmp(instr, "sa") == 0)
	{
		if (data->a != NULL && data->a->next != NULL)
			swap_first_two(data->a);
	}
	else if (ft_strcmp(instr, "sb") == 0)
	{
		if (data->b != NULL && data->b->next != NULL)
			swap_first_two(data->b);
	}
	else if (ft_strcmp(instr, "ss") == 0)
	{
		if (data->a != NULL && data->a->next != NULL)
			swap_first_two(data->a);
		if (data->b != NULL && data->b->next != NULL)
			swap_first_two(data->b);
	}
}

void	push_elem(char *instr, t_data *data)
{
	if (ft_strcmp(instr, "pa") == 0)
	{
		if (data->b != NULL)
			push(&data->b, &data->a);
	}
	else if (ft_strcmp(instr, "pb") == 0)
	{
		if (data->a != NULL)
			push(&data->a, &data->b);
	}
}

void	rotate_stack(char *instr, t_data *data)
{
	if (!ft_strcmp(instr, "ra") || !ft_strcmp(instr, "rr"))
		data->a = move_first(data->a, data->a);
	if (!ft_strcmp(instr, "rb") || !ft_strcmp(instr, "rr"))
		data->b = move_first(data->b, data->b);
}

void	reverse_rotate(char *instr, t_data *data)
{
	if (!ft_strcmp(instr, "rra") || !ft_strcmp(instr, "rrr"))
		data->a = move_last(data->a);
	if (!ft_strcmp(instr, "rrb") || !ft_strcmp(instr, "rrr"))
		data->b = move_last(data->b);
}
