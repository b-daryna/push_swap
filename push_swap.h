/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:52:00 by dbessmer          #+#    #+#             */
/*   Updated: 2017/10/18 11:21:12 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

# define RED        "\x1b[31;1m"
# define PINK       "\x1b[91m"
# define BLUE       "\x1b[34;1m"
# define CYAN       "\x1b[36m"
# define GREEN       "\x1b[92m"
# define RESET      "\x1b[0m"

typedef struct	s_instr
{
	char	**swap;
}				t_instr;

typedef struct	s_data
{
	t_list	*a;
	t_list	*b;
	int		v_flag;
	int		l_flag;
	int		c_flag;
	int		v_amount;
	int		l_amount;
	int		c_amount;
	int		flag_amount;
	int		total_amount;
	int		first_go;
	int		stack_size;
	int		print_instr;
	char	*push_i;
}				t_data;

/*
** m_d = moved_down
*/

typedef struct	s_stack
{
	int unsorted_size;
	int m_d;
	int div;
	int mid_div;
	int prev_num;
}				t_stack;

/*
** -------- validity functions for both programs ----------
*/

int				read_args(int argc, char **argv);
int				check_argument_validity(char *arg);
int				check_duplicate(int a, t_list *lst);
int				can_add_element(t_data *data, int argc, char **argv);
int				call_error(int a);
int				stack_is_sorted(t_list *lst, int len);

/*
** -------- functions for push_swap ----------
*/

void			set_data(t_data *data);
int				check_for_flags_end(int argc, char **argv, t_data *data);
int				check_for_flags_start(t_data *data, char **argv);

void			get_middle_element(t_list *lst, int len, t_stack *stack);
int				three_elems_not_sorted(t_list *lst, char stack, int len);
void			three_in_a(int a, int b, int c, t_data *data);
void			three_in_b(int a, int b, int c, t_data *data);
void			stack_3_elems(t_data *data, int len, char stack, t_list *lst);
void			bring_up_sorted_elems(t_data *data, int size, char *str);

int				stack_length(t_list *lst);
int				sort_by_half_a(t_data *data, int len, t_stack *stack);
char			*make_rr(t_data *data, int len, t_stack *st, char *prev_com);
int				sort_by_half_b(t_data *data, int len, t_stack *stack);
int				next_elems_are_smaller(int len, int divider, t_list *stack);
int				next_elems_are_bigger(int len, int divider, t_list *stack);
void			sort_three(int a, int b, int c, t_data *data);
void			sort_three_b(int a, int b, int c, t_data *data);
void			sort_stack_a(t_data *data, int len);
void			sort_a_helper(t_data *data, int len, t_stack *stack_a);
void			sort_stack_b(t_data *data, int len, int unsorted, int mid_div);
void			sort_b(int unsorted, int len, t_data *data, t_stack *stack_b);

/*
** -------- functions for checker -----------
*/

int				flags_start(int argc, char **argv, t_data *data);
int				flags_end(int argc, char **argv, t_data *data);
int				check_instruction_validity(char *line, t_instr instruction);
void			create_instructions(t_instr *instruction);
int				correct_num(t_list *lst, t_data data);
int				call_sorted(int i, t_data *data);

/*
** -------- execution for both-----------
*/

void			execute(char *str, t_data *data, int flag);
void			print_result(char *line, t_data *data, int flag);
void			print_prev_push_instr(int flag, t_data *data, char *line);
void			final_print(int flag, t_data *data, char *line);
void			print(t_list *a, t_list *b, t_data *data);
void			print_rest_of_stack(t_list *a, t_list *b, t_data *data);
void			swap_first(char *instr, t_data *data);
void			push_elem(char *instr, t_data *data);
void			rotate_stack(char *instr, t_data *data);
void			reverse_rotate(char *instr, t_data *data);
void			swap(int *a, int *b);
void			swap_first_two(t_list *head);
t_list			*move_first(t_list *lst, t_list *elem);
t_list			*move_last(t_list *lst);
void			push(t_list **from, t_list **to);

#endif
