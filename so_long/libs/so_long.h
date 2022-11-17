/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:06:55 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 13:10:36 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
#	include <unistd.h>
# include <stdio.h>
# include <mlx.h>

#include<fcntl.h>
#include<errno.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_game {
	void *mlx;
	void *win;
	char **t_game;
	char **t_copy_game;
	int	with;
	int	heith;
	int p_x;
	int p_y;
	int n_keys;
	int n_collec;
}				t_game;

typedef struct	s_error_map {
	int wiht;
	int height;
	int n_exit;
	int n_colec;
	int n_position;
}				t_e_map;

typedef struct	s_info_recursive {
	int x_max;
	int y_max;
	char **table;
	char is_posible;
}				t_recursive;

#define H_MAX 20

void	ft_read_file(t_game *game, char **str, int num_arg);
void	ft_create_map(t_game *game);
int ft_exit_x(t_game *game);
void ft_free_table(t_game *game);

void	ft_error_message(char *str, int error);

#endif