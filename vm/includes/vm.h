/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:38:48 by dzui              #+#    #+#             */
/*   Updated: 2017/10/31 16:20:10 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_VM_H
# define VM_VM_H
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include "op.h"
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include <ncurses.h>

typedef struct			s_player
{
	unsigned char		magic[4];
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	unsigned char		prog_size[4];
	unsigned int		prog_size_nb;
	unsigned char		inctructions[CHAMP_MAX_SIZE + 1];
	struct s_player		*next;
	char				*number;
	uintmax_t			last_live;
	int					live_in_curr_period;
	unsigned int		nb_pl;
}						t_player;

typedef struct			s_process
{
	int					args[3];
	int					carry;
	int					live;
	int					instr_nb;
	int					last_live_ind;
	int					start_command;
	unsigned int		arg_1;
	unsigned int		arg_2;
	unsigned int		arg_3;
	intmax_t			cur_cycles;
	short				pc;
	short				index;
	unsigned int		proc_number;
	t_player			*pl_belongs;
	struct s_process	*next;
	int					correct_args;
	unsigned int		registers[REG_NUMBER];
}						t_process;

typedef struct			s_vm
{
	intmax_t			cycles;
	intmax_t			nbr_cycles;
	unsigned int		number[MAX_PLAYERS];
	unsigned char		memory[MEM_SIZE];
	int					color_map[MEM_SIZE];
	int					iter[MEM_SIZE];
	char				*name_files[MAX_PLAYERS];
	char				**argv;
	int					speed;
	int					cycle_to_die;
	int					processes;
	uintmax_t			total_lives;
	int					nbr_live;
	int					pl_index;
	unsigned int		avail_nb;
	int					check;
	int					play;
	int					visual;
	float				br_down_color[4];
	float				prev_br_down_color[4];
	t_player			*head_pl;
	int					ct;
}						t_vm;

t_process				*ft_create_process(t_process *head, t_player *pl,
						short pc);
t_process				*ft_add_process(t_process **head, t_player *pl,
						short pc);
t_player				*ft_create_player(int fd, t_vm *vm, int i);
unsigned int			ft_atoi_dec(char *nb);
unsigned int			ft_convert_dec(char	*prog_size_hex);
unsigned int			ft_convert_hex_to_dec(unsigned char *prog_size);
unsigned int			ft_pow(unsigned int nb, int pow);
void					ft_print_live_break_down(t_vm *vm, int y, int x);
void					ft_print_players(t_player *players);
void					ft_read_champions(t_vm *vm, t_player **head);
void					ft_player_short_check(t_player *pl, ssize_t bytes,
						char *name);
void					ft_assign_memory(t_vm *vm, t_player *head_pl,
						t_process **head);
void					ft_set_vm_default_parameters(t_vm *vm);
void					ft_add_player(t_player **head, int fd, t_vm *vm, int i);
void					ft_error(char *error_msg);
void					ft_process_args(t_vm *vm);
char					*ft_join(char *src, char *to_join);
char					*ft_itoa_base(unsigned int nb);
int						ft_count_numbers(unsigned int number);
int						ft_find_number(char ch);
int						ft_check_file_name(char *name);
int						ft_is_numberic_string(char *str);
int						ft_check_dump_flag(t_vm *vm);
int						ft_check_pl_number(t_vm *vm);
void					ft_visual(t_vm *vm, t_player *head, t_process *proc);
void					draw_vertical_border(int x);
void					draw_horizontal_border(int y);
void					draw_frame();
void					draw_data(t_vm *vm, t_player *pl);
void					ft_count_percentage(t_vm *vm, t_player *pl);
void					draw_memmory(t_vm *vm, t_process *proc);
void					ft_print_memory(t_vm *vm);
void					ft_total_lives(t_vm *vm, t_player *pl);
void					ft_print_pc(t_vm *vm, t_process *proc, int i);
void					ft_get_arguments(t_process *pr, int nb);
void					ft_count_cycles_state(t_vm *vm);
unsigned int			ft_get_value(t_vm *vm, t_process *pr, int label_size);
unsigned int			ft_t_reg_process(t_vm *vm, t_process *pr);
unsigned int			ft_t_ind_process(t_vm *vm, t_process *pr);
unsigned int			ft_t_dir_process(t_vm *vm, t_process *pr, int label);
void					ft_init_color_map(t_vm *vm, t_process *pr);
void					ft_clear_args(t_process *pr);
void					ft_process_instruction(t_process *pr, t_vm *vm,
						t_process **head);
void					ft_choose_instruction(t_vm *vm, t_process *pr,
						t_process **head);
int						ft_get_number_of_pl(t_player *pl, t_player *find);
void					ft_process_inval_args(t_vm *vm, t_process *pr);
void					ft_del_element(t_process **head, t_process *del);
void					ft_copy_value(t_vm *vm, t_process *pr, short start,
						unsigned int value);
unsigned int			ft_t_ind_process_long(t_vm *vm, t_process *pr);
int						ft_check_regs(t_vm *vm, t_process *proc, int reg_nb);
void					ft_sti(t_vm *vm, t_process *proc);
void					ft_and(t_vm *vm, t_process *proc);
void					ft_or(t_vm *vm, t_process *proc);
void					ft_xor(t_vm *vm, t_process *proc);
void					ft_st(t_vm *vm, t_process *proc);
void					ft_ld(t_vm *vm, t_process *proc);
void					ft_zjmp(t_vm *vm, t_process *proc);
void					ft_add(t_vm *vm, t_process *proc);
void					ft_sub(t_vm *vm, t_process *proc);
void					ft_ldi(t_vm *vm, t_process *proc);
void					ft_fork(t_vm *vm, t_process *proc,
						t_process **head_proc);
void					ft_lld(t_vm *vm, t_process *proc);
void					ft_lfork(t_vm *vm, t_process *proc,
						t_process **head_proc);
void					ft_lldi(t_vm *vm, t_process *proc);
void					ft_live(t_vm *vm, t_process *proc);
void					ft_aff(t_vm *vm, t_process *proc);
void					ft_run_visual_mode(t_vm *vm, t_process **process,
						t_player *players);
void					ft_run_normal_mode(t_vm *vm, t_process **process,
						t_player *players);
void					ft_print_champ(t_vm *vm, t_player *players);
void					ft_set_regs(t_process *new_one, t_process *proc);
void					draw_player_info(t_player *pl, int num);
void					ft_print_live_break_down_prev(t_vm *vm, int y, int x);
void					key_function(t_vm *vm);
void					draw_players(t_player *head);
void					ft_draw_init(t_vm *vm, t_process *proc);
void					ft_print_name(t_vm *vm, t_player *players, int nb);
void					draw_menu(void);
void					ft_delete_process(t_player *players,
							t_process **pr, t_vm *vm);
void					ft_size_error(char *ch_name);
void					ft_reset_live_in_period(t_player *players);

#endif
