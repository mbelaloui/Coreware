/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:01:25 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 19:31:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

static void	run_option(t_option *op, t_player *player)
{
	if (op->q)
		ft_put_bin_source(player);
	if (op->w)
		ft_put_decimal_source(player);
	if (op->r)
		ft_put_hexa_source(player);
	if (op->p)
	{
		ft_put_player(player);
		exit(0);
	}
}

static void	run(t_charlist *file, char *url_output, t_option *op)
{
	t_player		player;
	t_charlist		*file_clean;
	t_op			*op_tab[NBR_OP];

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
	run_option(op, &player);
	ft_make_out_put(&player);
	ft_dell_list_charlist(&file_clean);
	ft_free_optab(op_tab);
	ft_free_player(&player);
}

static void	message(char *name, t_option *op)
{
	t_op			*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	if (op->d)
		ft_put_desc_param(op_tab);
	if (op->h)
		ft_put_help(name, op);
	if (op->o)
		ft_put_op(op_tab);
	if (op->u)
		ft_put_usage(name, op);
	if (op->t)
		ft_put_type_param(op_tab);
	if (op->y)
		ft_put_size_label(op_tab);
	ft_free_optab(op_tab);
	exit(0);
}

static void	process(char *param, t_option *op)
{
	char		*url_output;
	t_charlist	*file;

	file = NULL;
	url_output = ft_manage_url(param);
	if (!ft_read_url_file(param, &file))
		ft_error_reading_file(ERROR_READING_FILE);
	run(file, url_output, op);
	ft_dell_list_charlist(&file);
}

int			main(int argc, char **argv)
{
	char		*param;
	int			pt;
	t_option	op;

	ft_init_asm_option(&op);
	if (!(param = ft_mat_to_str(argv, 1)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	if (argc == 1)
		ft_error_param(ERROR_NO_PARAM, param);
	else
	{
		pt = ft_extract_asm_options(param, &op, argv[0]);
		if (op.d || op.h || op.o || op.u || op.t || op.y)
			message(argv[0], &op);
		process(param + pt, &op);
		ft_strdel(&param);
	}
	return (0);
}
