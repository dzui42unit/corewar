/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:11:26 by ozabara           #+#    #+#             */
/*   Updated: 2017/09/29 12:44:08 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "op.h"

# define FILE argc - 1
# define OPTION argc - 2

# define REG_OCTET 1
# define IND_OCTET 2
# define DIR_OCTET 4
# define DIR_OCTET_INDEX 2
# define MEMORY_SIZE 10000

# define DEFAULT "\033[0m"
# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define B_RED "\x1b[1;31m"
# define GREEN "\x1b[32m"
# define B_GREEN "\x1b[1;32m"
# define YELLOW "\x1b[33m"
# define B_YELLOW "\x1b[1;33m"
# define BLUE "\x1b[34m"
# define B_BLUE "\x1b[1;34m"
# define PINK "\x1b[35m"
# define B_PINK "\x1b[1;35m"
# define CYAN "\x1b[36m"
# define B_CYAN "\x1b[1;36m"
# define WHITE "\x1b[37m"

# define GOLD "\x1b[38;5;214m"
# define BOLD "\x1b[1;m"
# define ITALIC "\x1b[3;m"
# define UNDERLINE "\x1b[4;m"
# define CLEAN "\033[H\033[2J"

typedef struct		s_in
{
	int				fd;
	char			file_name[128 + 1];
}					t_in;

typedef struct		s_out
{
	int				fd;
}					t_out;

typedef	struct		s_args
{
	char			*content;
	char			type;
	char			t_arg;
	int				value1;
	char			code;
	int				value2;
	char			*tag;
	struct s_args	*next;
}					t_args;

typedef struct		s_instr
{
	unsigned int	line_nbr;
	char			*tag_line;
	char			is_tag;
	char			*tag_name;
	char			*line_code;
	signed char		code;
	char			*args_line;
	int				param_byte;
	int				octet_index;
	t_args			*args_list;
	struct s_instr	*next;
}					t_instr;

typedef struct		s_parse
{
	unsigned int	line_nbr;
	char			*free_line;
	char			*tag_name;
	char			*tag_line;
	char			*line_code;
	char			*args_line;
	t_instr			*instr_list;
	char			saved_name;
	char			saved_comment;
	char			saved_comment_name;
}					t_parse;

typedef struct		s_data
{
	t_header		header;
	t_in			in;
	t_out			out;
	t_parse			parse;
}					t_data;

extern	t_op		g_op_tab[17];

int					cw_open_in(int argc, char **argv, t_in *data_in);
int					cw_free_and_exit(t_instr **instr_list, int type,
										t_data *data);
/*
** Parsing
*/

int					cw_parse_in(t_data *data);
void				cw_parse_struct_init(t_parse *parse);
void				cw_parse_struct_clean(t_parse *parse);
int					cw_parse_tags(t_parse *parse);
int					cw_parse_name_and_comment(t_parse *parse, t_header *header);
void				cw_parse_check_header(const char *str, unsigned int
							content_length, t_parse *parse, t_header *header);
int					cw_parse_add_instruction(t_instr **list_head,
												t_parse *content);
int					cw_parse_get_code(char *analyze, char **code_name);
int					cw_parse_save_code(t_instr **instr_list);
int					cw_parse_get_args(t_instr **inst_list);
int					cw_parse_save_args(t_instr **instr_list);
int					cw_parse_arg_dir_and_ind(t_args *current, char args_nbr,
											int line_nbr, t_instr *check_tag);
int					cw_parse_eval_expr(t_args *current, char args_nbr,
											int line_nbr);
int					cw_parse_eval_expr_tag(t_args *current, char args_nbr,
											int line_nbr, t_instr *check_tag);
int					cw_parse_validate_args(t_instr **instr_list);

/*
** Assembly
*/
int					cw_assembly_data(t_data *data);
int					cw_create_param_byte(t_instr **instr_list);
int					cw_get_program_data(t_instr **instr_list, t_header *header);
int					cw_set_tag_value(t_instr **instr_list);

/*
** Display
*/
void				cw_display_details(t_instr *instr_list, t_header header);
void				cw_display_hex(unsigned long long int nbr, int octet_nbr);

/*
** File creation
*/
int					cw_make_binary(t_data *data);
void				cw_write_byte(int fd, unsigned int value, char octet_nbr);
void				cw_write_header(int fd, t_header header);
int					cw_write_binary(t_instr **instr_list, t_out *out_file);

/*
** Reversing
*/
void				cw_reverse_binary(int argc, char **argv);
unsigned int		cw_reverse_header(size_t size, unsigned char buff[size]);
void				cw_reverse_instructions(unsigned int memory[MEMORY_SIZE],
											size_t program_size);

/*
** Other
*/

char				*cw_strcomment_trim(char *line, char comment_char);
int					cw_isprint_without_space(int c);
int					cw_nbr_of_letter_in_str(const char *str, char c);
void				cw_strtab_free(char **tab);
int					cw_isnumber_syntax(char *str, char sign);
long long int		cw_lltoi(const char *nptr);
size_t				cw_intlen(int nbr);
int					cw_free_and_exit_expr_tab(char **expr_tab);
int					cw_exist_label(t_instr *instr_list, char *tag_to_check);
size_t				cw_strtab_len(char **tab);
int					cw_strindex(const char *s, const char *to_check);
char				*cw_strjoin_and_free(char *s1, char *s2);

#endif
