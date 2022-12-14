/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:43:13 by vagevorg          #+#    #+#             */
/*   Updated: 2022/11/27 17:07:35 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

int	simple_built_in(t_pars *pars, t_env *env_, char ***env)
{
	int	_exit;

	if (there_is_builtin(pars->cmd))
	{
		*env = change_under_score(env_, pars->cmd, *env);
		if (pars->errfile)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(pars->errfile, 2);
			ft_putendl_fd(strerror(pars->errnum), 2);
			return (1);
		}
		if (pars->outfilefd == -1)
			return (1);
		check_out_or_input(pars);
		_exit = there_is_builtin(pars->cmd);
		if (_exit == IS_EXIT)
			printf("exit\n");
		g_status = call_builtin(pars, pars->cmd,
				there_is_builtin(pars->cmd), env_);
		save_std();
		return (1);
	}
	return (0);
}

int	some_checks(char **promt_, t_env *env_, char ***env, int *count)
{
	char	*promt;

	promt = *promt_;
	*env = list_to_env(env_);
	signal(SIGINT, handle1);
	if (!promt)
		free_and_exit(env_, *env);
	if ((!promt || promt[0] == '\0') && fret(NULL, promt, *env))
		return (1);
	add_history(promt);
	if ((not_found_second_quote(promt) || only_pipe(promt)
			|| check_redirections(promt) || check_pipes_count(promt_, count))
		&& fret(NULL, promt, *env))
		return (1);
	return (0);
}

int	some_stuff(char **promt, t_env *env_, t_pars **pars, int *gr)
{
	if (openheredoc(*promt, pars))
	{
		*gr = 1;
		signal(SIGINT, handle0);
		return (1);
	}
	do_expand(promt, env_, 0);
	if (lexer(promt, pars))
		return (1);
	return (0);
}

t_env	*signal_env_std(int argc, char **argv, char **env, int *gr)
{
	t_env	*env_;

	(void)argc;
	(void)argv;
	*gr = 0;
	set_signal();
	env_ = env_initialization(env);
	save_std();
	return (env_);
}

int	main(int argc, char **argv, char **env)
{
	int		gr;
	char	*promt;
	t_pars	**pars;
	int		count;
	t_env	*env_;

	env_ = signal_env_std(argc, argv, env, &gr);
	while (1)
	{
		set_setting(gr);
		promt = readline("Minishell$ ");
		if (some_checks(&promt, env_, &env, &count))
			continue ;
		pars = init_struct(count, &env_);
		if (some_stuff(&promt, env_, pars, &gr) && fret(pars, promt, env))
			continue ;
		if (count == 1 && simple_built_in(pars[0], env_, &env)
			&& fret(pars, promt, env))
			continue ;
		env = change_under_score(env_, promt, env);
		open_processes(count, pars, env, env_);
		fret(NULL, promt, env);
		gr = 0;
	}
	return (0);
}
