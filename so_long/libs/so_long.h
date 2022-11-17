/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:06:55 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 17:29:19 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_img
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		y;
	int		x;
	char	*buffer;
	int		color;
	int		pixel;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**t_game;
	char	**t_copy_game;
	int		with;
	int		heith;
	int		p_x;
	int		p_y;
	int		n_keys;
	int		n_collec;
}			t_game;

typedef struct s_error_map
{
	int		wiht;
	int		height;
	int		n_exit;
	int		n_colec;
	int		n_position;
}			t_e_map;

typedef struct s_info_recursive
{
	int		n_collec;
	int		x_max;
	int		y_max;
	char	**table;
	char	is_path_exit;
	char	is_posible;
}			t_recursive;

# define H_MAX 20

void		ft_read_file(t_game *game, char **str, int num_arg);
void		ft_create_map(t_game *game);
int			ft_exit_x(t_game *game);
void		ft_free_table(char **str);

// Error
void		ft_error_message(char *str, int error);
void		ft_error_check_table(t_game *game, t_e_map *error, int i);

// ft_move_caracter
void		ft_move_caracter_up(t_game *game);
void		ft_move_caracter_dow(t_game *game);
void		ft_move_caracter_righ(t_game *game);
void		ft_move_caracter_left(t_game *game);

// ft_read_file
int			ft_valid_info(char c);
void		ft_check_arguments(char **str, int num_arg);
void		ft_save_content(t_game *game, char **str);

// ft_map_posible
int			ft_map_posible(t_game *game);
void		ft_recursive_table(t_recursive *info, int x, int y);

// ft_create_map
void		ft_background_color(t_game *game);
void		ft_put_img(t_game *game, int x, int y, char *relative_path);

#endif