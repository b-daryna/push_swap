/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 11:12:15 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		read_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-l")\
			|| !ft_strcmp(argv[i], "-c"))
		i++;
	while (j < argc)
	{
        if (!check_argument_validity(argv[i]))
            return (0);
        i++;
		j++;
	}
    return (1);
}

int		can_add_element(t_data *data, int argc, char **argv)
{
	int		i;
	int		j;
	int		x;
	t_list	*elem;

	i = 1;
	j = 0;
	while (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-l")\
			|| !ft_strcmp(argv[i], "-c"))
		i++;
	while (j < argc)
	{
		if (check_duplicate(ft_atoi(argv[i]), data->a))
			return (0);
		x = ft_atoi(argv[i]);
		elem = ft_lstnew((void*)&x, sizeof(int));
		ft_lst_push_back(&data->a, elem);
		i++;
		j++;
	}
	return (1);
}

int		check_argument_validity(char *arg)
{
	int		i;
	char	*str;

	i = 0;
	while (arg[i])
	{
        if (arg[i] == '-' && i == 0)
			i++;
		if (!ft_isdigit(arg[i]))
            return (0);
		i++;
	}
    str = ft_itoa(ft_atoi(arg));
	if (ft_strcmp(str, arg) != 0)
	{
		free(str);
        return (0);
	}
	free(str);
	return (1);
}

int		check_duplicate(int a, t_list *lst)
{
	int *tmp;

	while (lst != NULL)
	{
		tmp = lst->content;
		if (a == *tmp)
			return (1);
		lst = lst->next;
	}
	return (0);
}