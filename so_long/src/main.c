/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:31:47 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/16 17:56:43 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_caracter_up(t_game *game)
{
	if (game->t_game[game->p_y - 1][game->p_x] == 'C')
		game->n_collec--;
	if (game->t_game[game->p_y - 1][game->p_x] == 'E')
		ft_exit_x(game);
	if (game->t_game[game->p_y - 1][game->p_x] == '0' ||
		game->t_game[game->p_y - 1][game->p_x] == 'C')
	{
		game->t_game[game->p_y][game->p_x] = '0';
		game->p_y -= 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_create_map(game);
	}
}
void	ft_move_caracter_dow(t_game *game)
{
	if (game->t_game[game->p_y + 1][game->p_x] == 'C')
		game->n_collec--;
	if (game->t_game[game->p_y + 1][game->p_x] == 'E')
		ft_exit_x(game);
	if (game->t_game[game->p_y + 1][game->p_x] == '0' ||
		game->t_game[game->p_y + 1][game->p_x] == 'C')
	{
		game->t_game[game->p_y][game->p_x] = '0';
		game->p_y += 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_create_map(game);
	}
}
void	ft_move_caracter_righ(t_game *game)
{
	if (game->t_game[game->p_y][game->p_x + 1] == 'C')
		game->n_collec--;
	if (game->t_game[game->p_y][game->p_x + 1] == 'E')
		ft_exit_x(game);
	if (game->t_game[game->p_y][game->p_x + 1] == '0' ||
		game->t_game[game->p_y][game->p_x + 1] == 'C')
	{
		game->t_game[game->p_y][game->p_x] = '0';
		game->p_x += 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_create_map(game);
	}
}
void	ft_move_caracter_left(t_game *game)
{
	if (game->t_game[game->p_y][game->p_x - 1] == 'C')
		game->n_collec--;
	if (game->t_game[game->p_y][game->p_x - 1] == 'E')
		ft_exit_x(game);
	if (game->t_game[game->p_y][game->p_x - 1] == '0' ||
		game->t_game[game->p_y][game->p_x + 1] == 'C')
	{
		game->t_game[game->p_y][game->p_x] = '0';
		game->p_x -= 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_create_map(game);
	}
}

void	ft_move_caracter(t_game *game, int direction)
{
	if (direction == 1)
	{
		ft_move_caracter_up(game);
	}
	if (direction == 2)
	{
		ft_move_caracter_dow(game);
	}
	if (direction == 3)
	{
		ft_move_caracter_righ(game);
	}
	if (direction == 4)
	{
		ft_move_caracter_left(game);
	}
}

int	deal_key(int key, t_game *game)
{
	if (key == 53)
	{
		free(game->t_game);
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	if (key == 13)
	{
		game->n_keys++;
		ft_move_caracter(game, 1);
		ft_printf("\n press: %i", game->n_keys);
	}
	if (key == 1)
	{
		game->n_keys++;
		ft_move_caracter(game, 2);
		ft_printf("\n press: %i", game->n_keys);
	}
	if (key == 2)
	{
		game->n_keys++;
		ft_move_caracter(game, 3);
		ft_printf("\n press: %i", game->n_keys);
	}
	if (key == 0)
	{
		game->n_keys++;
		ft_move_caracter(game, 4);
		ft_printf("\n press: %i", game->n_keys);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_read_file(&game, argv, argc);
	game.n_keys = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.with, game.heith, "so_long");
	ft_create_map(&game);
	mlx_key_hook(game.win, deal_key, &game);
	mlx_hook(game.win, 17, 0, ft_exit_x, &game);
	mlx_loop(game.mlx);
	return (0);
}

// Seccion de graficos

// las images de maneja desde la exquina superior izquierda

//  w : 13
//  a : 0
//  s : 1
//  d : 2

// int	deal_key(int key, void *param)
// {
// 	ft_printf("\n D: press : {%d} {%d}", key, param);
// 	return (0);
// }

// int	main(void)
// {
// 	void *mlx = mlx_init();
// 	void *win = mlx_new_window(mlx, 640, 360, "so_long");

// 	void *image = mlx_new_image(mlx, 640, 360);

// 	// The following code goes here.
// 	int pixel_bits;
// 	int line_bytes;
// 	int endian;
// 	char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

// 	int color = 0xABCDEF;

// 	if (pixel_bits != 32)
// 		color = mlx_get_color_value(mlx, color);

// 	for (int y = 0; y < 360; ++y)
// 		for (int x = 0; x < 640; ++x)
// 		{
// 			int pixel = (y * line_bytes) + (x * 4);

// 			if (endian == 1) // Most significant (Alpha) byte first
// 			{
// 				buffer[pixel + 0] = (color >> 24);
// 				buffer[pixel + 1] = (color >> 16) & 0xFF;
// 				buffer[pixel + 2] = (color >> 8) & 0xFF;
// 				buffer[pixel + 3] = (color)&0xFF;
// 			}
// 			else if (endian == 0) // Least significant (Blue) byte first
// 			{
// 				buffer[pixel + 0] = (color)&0xFF;
// 				buffer[pixel + 1] = (color >> 8) & 0xFF;
// 				buffer[pixel + 2] = (color >> 16) & 0xFF;
// 				buffer[pixel + 3] = (color >> 24);
// 			}
// 		}
// 	mlx_put_image_to_window(mlx, win, image, 0, 0);

// 	// test corgi
// 	void	*img_corgi;
// 	char	*relative_path = "./img/dog/20x20.xpm";
// 	// char	*relative_path = "./img/cellule/20x20.xpm";
// 	// char	*relative_path = "./img/obstacle/20x20.xpm";
// 	// char	*relative_path = "./img/points/20x20.xpm";
// 	// char	*relative_path = "./img/exit/20x20.xpm";
// 	int		img_width;
// 	int		img_height;
// 	img_corgi = mlx_xpm_file_to_image(mlx, relative_path, &img_width,
			// &img_height);

// 	mlx_put_image_to_window(mlx, win, img_corgi, 0, 0);

// 	mlx_key_hook(win, deal_key, (void *)0);

// 	mlx_loop(mlx);
// }