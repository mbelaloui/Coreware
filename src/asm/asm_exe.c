/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:01:25 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 15:03:08 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	run_option(t_option *op, t_player *player, t_op *op_tab[NBR_OP])
{
	if (op->B)
		ft_put_bin_source(player);
	if (op->D)
		ft_put_decimal_source(player);
	if (op->H)
		ft_put_hexa_source(player);
	if (op->d || op->o || op->p || op->t || op->S)
	{
		if (op->d)
			ft_put_desc_param(op_tab);
		if (op->o)
			ft_put_op(op_tab);
		if (op->p)
			ft_put_player(player);
		if (op->t)
			ft_put_type_param(op_tab);
		if (op->S)
			ft_put_size_label(op_tab);
		exit(0);
	}
}

void	run(t_charlist *file, char *url_output, t_option *op, char *name)
{
	t_player player;
	t_charlist *file_clean;
	t_op *op_tab[NBR_OP];

	if (op->h)
		ft_put_help(name, op);
	if (op->u)
		ft_put_usage(name, op);
	ft_bzero(&player, sizeof(player));
	player.url_output = url_output;
	file_clean = ft_clean_file(file);
	ft_get_op_tab(op_tab);
	if (!ft_extract_info_player(file_clean, &player, op_tab))
		ft_error_reading_file(ERROR_EMPTY_FILE);
	if (ft_get_size_program(player.src) > CHAMP_MAX_SIZE)
		ft_warning(WARNING_SIZE_CHAMP,
				ft_get_size_program(player.src), NULL, op);
	ft_translate_player(&player, op_tab, op);
	run_option(op, &player, op_tab);
	ft_make_out_put(&player);
	ft_dell_list_charlist(&file_clean);
	ft_free_optab(op_tab);
	ft_free_player(&player);
}

int	main(int argc, char **argv)
{
	t_charlist	*file;
	char		 *param;
	char		*url_output;
	int			pt;
	t_option	op;

	file = NULL;
	ft_init_asm_option(&op);
	param = ft_mat_to_str(argv, 1);
	if (argc == 1)
		ft_error_param(ERROR_NO_PARAM, param);
	else
	{
		pt = ft_extract_asm_options(param, &op, argv[0]);
		url_output = ft_manage_url(param + pt);
		if (!ft_read_url_file(param + pt, &file))
			ft_error_reading_file(ERROR_READING_FILE);
		ft_strdel(&param);
		run(file, url_output, &op, argv[0]);
		ft_dell_list_charlist(&file);
		//ft_put_option(&op);
	}
	return (0);
}
