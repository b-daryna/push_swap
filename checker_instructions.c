/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:42:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 14:28:16 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_instruction_validity(char *line, t_instr instruction)
{
	int i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(instruction.swap[i], line) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	create_instructions(t_instr *instruction)
{
	if (!(instruction->swap = (char**)malloc(sizeof(char*) * 11)))
		return ;
	instruction->swap[0] = "sa";
	instruction->swap[1] = "sb";
	instruction->swap[2] = "ss";
	instruction->swap[3] = "pa";
	instruction->swap[4] = "pb";
	instruction->swap[5] = "ra";
	instruction->swap[6] = "rb";
	instruction->swap[7] = "rr";
	instruction->swap[8] = "rra";
	instruction->swap[9] = "rrb";
	instruction->swap[10] = "rrr";
}

int		correct_num(t_list *lst, t_data data)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	if (i == data.stack_size)
		return (1);
	return (0);
}

int		call_sorted(int i, t_data *data)
{
	if (i == 1)
	{
		if (data->c_flag)
			ft_printf(GREEN "OK\n" RESET);
		else
			ft_putstr("OK\n");
		if (data->l_flag && data->c_flag)
			ft_printf(GREEN "№ of commands: %d\n" RESET, data->total_amount);
		else if (data->l_flag)
			ft_printf("№ of commands: %d\n", data->total_amount);
		return (1);
	}
	if (data->c_flag)
		ft_printf(GREEN "KO\n" RESET);
	else
		ft_putstr("KO\n");
	return (0);
}
