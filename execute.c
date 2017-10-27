/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 14:45:51 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute(char *str, t_data *data, int flag)
{
	int		i;
	char	**command;

	i = 0;
	command = ft_strsplit(str, ',');
	while (command[i])
	{
		print_result(command[i], data, flag);
		free(command[i]);
		i++;
	}
	free(command);
	data->total_amount++;
}

void	prev_push_helper(t_data *data, char *line)
{
	if (!ft_strcmp(data->push_i, ""))
		data->push_i = ft_strncpy(data->push_i, line, 4);
	else if ((!ft_strcmp(line, "pa") && !ft_strcmp(data->push_i, "pb")) || \
			(!ft_strcmp(line, "pb") && !ft_strcmp(data->push_i, "pa")))
		data->push_i = ft_strncpy(data->push_i, "", 4);
	else if ((!ft_strcmp(line, "pa") && !ft_strcmp(data->push_i, "pa")) || \
			(!ft_strcmp(line, "pb") && !ft_strcmp(data->push_i, "pb")))
	{
		ft_printf("%s\n", line);
		if (data->v_flag)
			print(data->a, data->b, data);
	}
}

void	print_prev_push_instr(int flag, t_data *data, char *line)
{
	if (flag && (ft_strcmp(line, "pa") == 0 || ft_strcmp(line, "pb") == 0))
		prev_push_helper(data, line);
	else if (flag && (!ft_strcmp(data->push_i, "pb") ||\
				!ft_strcmp(data->push_i, "pa")))
	{
		ft_printf("%s\n", data->push_i);
		data->push_i = ft_strncpy(data->push_i, "", 4);
		if (data->v_flag == 1)
			print(data->a, data->b, data);
	}
	if ((ft_strcmp(line, "pa") && ft_strcmp(line, "pb") &&\
				(flag || data->v_flag)) || ((!ft_strcmp(line, "pa") ||\
						!ft_strcmp(line, "pb")) && !flag && data->v_flag))
		data->print_instr = 1;
}

void	print_result(char *line, t_data *data, int flag)
{
	data->print_instr = 0;
	if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0 ||\
			ft_strcmp(line, "ss") == 0)
	{
		print_prev_push_instr(flag, data, line);
		swap_first(line, data);
	}
	else if (ft_strcmp(line, "pa") == 0 || ft_strcmp(line, "pb") == 0)
	{
		print_prev_push_instr(flag, data, line);
		push_elem(line, data);
	}
	else if (ft_strcmp(line, "ra") == 0 || ft_strcmp(line, "rb") == 0 ||\
			ft_strcmp(line, "rr") == 0)
	{
		print_prev_push_instr(flag, data, line);
		rotate_stack(line, data);
	}
	else if (ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0 ||\
			ft_strcmp(line, "rrr") == 0)
	{
		print_prev_push_instr(flag, data, line);
		reverse_rotate(line, data);
	}
	final_print(flag, data, line);
}

void	final_print(int flag, t_data *data, char *line)
{
	if ((data->print_instr && (flag || data->v_flag)))
		ft_printf("%s\n", line);
	if (data->v_flag && data->print_instr)
		print(data->a, data->b, data);
}
