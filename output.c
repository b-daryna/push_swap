/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 15:06:10 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		call_error(int a)
{
	if (a == 1)
		ft_putstr("Error\n");
	else if (a == 2)
		ft_putstr("Error: Incorrect flag usage!\n");
	return (0);
}

void	print(t_list *a, t_list *b, t_data *data)
{
	int a_num;
	int b_num;

	if (data->c_flag)
		ft_printf(RED "%10s" BLUE "%10s\n" RESET, "STACK A", "STACK B");
	else
		ft_printf("%10s%10s\n", "STACK A", "STACK B");
	while (a != NULL && b != NULL)
	{
		a_num = *(int*)a->content;
		b_num = *(int*)b->content;
		if (data->c_flag)
			ft_printf(PINK "%10d" CYAN "%10d\n" RESET, a_num, b_num);
		else
			ft_printf("%10d%10d\n", a_num, b_num);
		a = a->next;
		b = b->next;
	}
	print_rest_of_stack(a, b, data);
}

void	print_rest_of_stack(t_list *a, t_list *b, t_data *data)
{
	while (a != NULL)
	{
		if (data->c_flag)
			ft_printf(PINK "%10d\n" RESET, *(int*)a->content);
		else
			ft_printf("%10d\n", *(int*)a->content);
		a = a->next;
	}
	while (b != NULL)
	{
		if (data->c_flag)
			ft_printf(CYAN "%20d\n" RESET, *(int*)b->content);
		else
			ft_printf("%20d\n", *(int*)b->content);
		b = b->next;
	}
}

int		stack_is_sorted(t_list *lst, int len)
{
	int *ptr;
	int *ptr1;
	int i;

	i = 1;
	while (i < len && lst != NULL && lst->next != NULL)
	{
		ptr = lst->content;
		ptr1 = lst->next->content;
		if (*ptr > *ptr1)
			return (0);
		i++;
		lst = lst->next;
	}
	return (1);
}
