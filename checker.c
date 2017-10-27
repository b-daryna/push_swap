/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 15:11:09 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->v_flag = 0;
	data->l_flag = 0;
	data->c_flag = 0;
	data->v_amount = 0;
	data->l_amount = 0;
	data->c_amount = 0;
	data->flag_amount = 0;
	data->total_amount = 0;
	data->push_i = ft_strnew(3);
}

void	flag_count(t_data *data, char **argv, int i)
{
	if (!ft_strcmp(argv[i], "-v"))
	{
		data->v_flag = 1;
		data->v_amount++;
	}
	if (!ft_strcmp(argv[i], "-l"))
	{
		data->l_flag = 1;
		data->l_amount++;
	}
	if (!ft_strcmp(argv[i], "-c"))
	{
		data->c_flag = 1;
		data->c_amount++;
	}
}

int		flags_start(int argc, char **a, t_data *data)
{
	int i;

	i = 1;
	while (!ft_strcmp(a[i], "-v") || !ft_strcmp(a[i], "-l")\
			|| !ft_strcmp(a[i], "-c"))
	{
		flag_count(data, a, i);
		i++;
		data->flag_amount++;
		if (!a[i])
			break ;
	}
    if (data->flag_amount == argc - 1)
		return (0);
	if (data->v_amount > 1 || data->l_amount > 1 || data->c_amount > 1)
		return (0);
	return (1);
}

int		flags_end(int argc, char **a, t_data *data)
{
	int i;

	i = argc - 1;
	while (!ft_strcmp(a[i], "-v") || !ft_strcmp(a[i], "-l")\
			|| !ft_strcmp(a[i], "-c"))
	{
		flag_count(data, a, i);
		i--;
		data->flag_amount++;
		if (!a[i])
			break ;
	}
    if (data->v_amount > 1 || data->l_amount > 1 || data->c_amount > 1)
		return (0);
	if (data->flag_amount == argc - 1)
		return (0);
	return (1);
}


int		main(int argc, char **argv)
{
	t_data	data;
	t_instr	instruction;
	char	*line;

	if (argc == 1)
		return (0);
	set_data(&data);
    if (!flags_start(argc, argv, &data) || !flags_end(argc, argv, &data))
		return (call_error(2));
	argc -= (data.flag_amount + 1);

    data.stack_size = argc;
    if (!read_args(argc, argv) || !can_add_element(&data, argc, argv))
		return (call_error(1));
	create_instructions(&instruction);
	while (get_next_line(0, &line))
	{
		if (!check_instruction_validity(line, instruction))
			return (call_error(1));
		execute(line, &data, 0);
		free(line);
	}
	if (stack_is_sorted(data.a, data.stack_size) && correct_num(data.a, data))
		return (call_sorted(1, &data));
	else
		return (call_sorted(0, &data));
}
