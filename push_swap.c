/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 15:10:19 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->v_flag = 0;
	data->c_flag = 0;
	data->v_amount = 0;
	data->c_amount = 0;
	data->flag_amount = 0;
	data->total_amount = 0;
	data->first_go = 1;
	data->push_i = ft_strnew(3);
}

int		check_for_flags_start(t_data *data, char **argv)
{
	int i;

	i = 1;
	while (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-c") ||\
			!ft_strcmp(argv[i], "-l"))
	{
		if (!ft_strcmp(argv[i], "-l"))
			return (0);
		if (!ft_strcmp(argv[i], "-v"))
		{
			data->v_flag = 1;
			data->v_amount++;
		}
		if (!ft_strcmp(argv[i++], "-c"))
		{
			data->c_flag = 1;
			data->c_amount++;
		}
		data->flag_amount++;
        if (!argv[i])
            break ;
	}
	if (data->v_amount > 1 || data->c_amount > 1)
		return (0);
	return (1);
}

int		check_for_flags_end(int argc, char **argv, t_data *data)
{
	int i;

	i = argc - 1;
	while (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-c") ||\
			!ft_strcmp(argv[i], "-l"))
	{
		if (!ft_strcmp(argv[i], "-l"))
			return (0);
		if (!ft_strcmp(argv[i], "-v"))
		{
			data->v_flag = 1;
			data->v_amount++;
		}
		if (!ft_strcmp(argv[i--], "-c"))
		{
			data->c_flag = 1;
			data->c_amount++;
		}
		data->flag_amount++;
        if (!argv[i])
            break ;
	}
	if (data->v_amount > 1 || data->c_amount > 1)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data data;

	if (argc == 1)
		return (0);
	set_data(&data);
	if (!check_for_flags_start(&data, argv) || data.flag_amount == argc - 1)
		return (call_error(2));
	if (!check_for_flags_end(argc, argv, &data))
		return (call_error(2));
	argc -= (data.flag_amount + 1);
	data.stack_size = argc;
	if (!read_args(argc, argv))
		return (call_error(1));
	if (!can_add_element(&data, argc, argv))
		return (call_error(1));
    sort_stack_a(&data, data.stack_size);
	if (ft_strcmp(data.push_i, "") != 0)
	{
		ft_printf("%s\n", data.push_i);
		push_elem(data.push_i, &data);
		if (data.v_flag == 1)
			print(data.a, data.b, &data);
	}
	return (0);
}
