/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:13:39 by viclucas          #+#    #+#             */
/*   Updated: 2018/05/28 20:44:43 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_21SH_H
# define FT_21SH_H

extern int g_window;

#include <termios.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct s_dlist
{
	char			*content;
	struct s_dlist	*next;
} t_dlist;

//elem = le contenue
//type = 1 si commande, 2 si token
//split = 1 si splitable, 2 si non splitable (car quotes, ect);

typedef struct  s_tab
{
	int 	flag1;
	int		flag2;
	int		i;
	int		o;
	char	**board;
}				t_tab;


typedef struct		s_storage
{
	int		nb_char;
	int		pos;
	int		value;
	int		bolean;
	int		length;
	int		end;
	char	*buffer_cpy;
	int		check;
}					t_storage;
int		ft_output3(char **flag);
int		ft_output2(char **flag);
int		ft_open(char **board, char **flag, char **opn_dir, char **opn_err);
int			ft_first_redir(char **board, char *name, char *opn_err, char *opn_dir);
int			ft_sec_redir(char **board, char *name, char *opn_dir);
int		ft_check_dup(char **board);
int		ft_output(char **flag);
int ft_redirection(char *name, char **board, char **env);
char	**ft_cut_tab(char **board, char **flag);
int ft_check_char(char **board);
char **ft_flag(char **board);
char	**ft_find_option(char *line, char **env, char **board);
char		**ft_realloc_for_re(char **env, char *board);
char		**ft_realloc_for_exe(char **env, char *board, char **cpy);
int				ft_run_exec(char **boar, char **env);
int			ft_pipe_exec1(char **board, char **flag, char **env);








int		ft_check_char(char **board);
int		ft_very_first_check(char *line);
void	ft_quotes_check(t_tab *x, char c);
int		ft_tokens(char *line, int i);
char	**ft_create_good_board(char *line, int number);
char	**ft_create_board(char *line, char c, int number);
char		***ft_exec_tab(char **board);
char	**ft_allocate_tokens(void);
//ft_term_signaux
void	ft_stop(int nb);
void		ft_change_length(int nb);
int			ft_signaux(int window, t_storage *x, char *line);


//parseur
char	*ft_put_some_blanks(char *line);
char		**ft_parsing(char **board);
int		ft_parsing_redirection(char *s);
char **ft_parseur(char *line, char **env, char **tokens);
//end of add

//ft_term_tools.c
int		fct(int c);
char	*ft_change_this_int(char c);
char	*ft_error_hist(t_storage *x, char *line, char *buffer);
int		ft_put_cursor_down();
void	ft_go_to(t_storage *x, int goal);
void	ft_move_to(t_storage *x, int goal);

void	ft_get_back(t_storage *x, int goal);
void	ft_suply_include(t_storage *x, char *reprint);
int		ft_put_cursor_up(t_storage *x);
void	ft_jump_line(t_storage *x, char *buffer);
void	ft_jump_words(t_storage *x, char *buffer, char *line);
char	*ft_get_cpy(t_storage *x, char *buffer, char *line);
char	*ft_past_buffer(t_storage *x, char *line);
char		*which_khey(t_dlist *hist);
//ft_back_delee.c
char	*ft_back_delete(t_storage *x, char *line);

//ft_history
t_dlist		*ft_lst_new(t_dlist *history, char *line);
char	*ft_history_arrow(t_dlist *p, t_storage *x, char *line, char *buffer);

//ft_basic_char
char	*ft_clean_buffer(char *s);
char	*ft_delete_basic_char(char *line, t_storage *x);
char	*ft_basic_char(char *line, t_storage *x, char *buffer);

//ft_fonctions_stockage.c
char			*ft_delete_char_in_string(char *s, int nb_char, int pos);
char			*ft_add_char(char *c, char *s, int pos, int nb_char);
int				ft_include_the_char(char *c, char *line, t_storage *x);
int				ft_delete_char(t_storage *x, char *line);
int		ft_clean_lines(int i, t_storage *x);

//ft_fonctions_gestion_de_ligne.c
int		ft_arrow(char *buffer, t_storage *x);
int		ft_error_term(char *s);
void	ft_home_end(t_storage *x, char *buffer);

//ft_termcaps.c
char		*which_khey(t_dlist *histo);
int			ft_get_length(void);

//ft_access
void			ft_echo(char **board);
int				ft_error(char *s1, char *name);
char			*ft_acces(char *s);
int				ft_access_exec(char *test, char *board);

//ft_cd.c
char			**ft_cd(char *s, char **env, char **board);
char			**ft_dir_changing(char **env);
int				ft_change_dir(char *s, char **env);

//ft_execute_cmd.c
char			**ft_tests_exec(char **tests, char **env, char **board);

//ft_fcts_environnement
char			**ft_realloc_for_setenv(char **env, char *board);
char			**ft_realloc_for_unset(char **env, int value);

//ft_environnement
char			**ft_set_env(char **board, char **env);
char			**ft_unset_env(char **board, char **env);

///ft_check_env
char			**ft_check_old(char **env);
char			**ft_check_pwd(char **env);
char			**ft_get_into_env(char **env, char *s);

////ft_allocate_parsing
char			*ft_allocate_parsing(char **tests, char **board);
char			**ft_allocate(char **env);

////ft_21sh
void			ft_21sh(char **env);

int				main(int ac, char **av, char **env);

#endif
