/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:12:36 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 10:14:39 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_background_color(t_game *game)
{
	void *image;
	int pixel_bits;
	int line_bytes;
	int endian;
	int y;
	int x;
	char *buffer;
	int color = 0xABCDEF;

	image = mlx_new_image(game->mlx, game->with, game->heith);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	y = -1;
	while (++y < game->heith)
	{
		x = -1;
		while (++x < game->with)
		{
			int pixel = (y * line_bytes) + (x * 4);
			if (endian == 1)
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color)&0xFF;
			}
			else if (endian == 0)
			{
				buffer[pixel + 0] = (color)&0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, image, 0, 0);
}

void ft_put_img(t_game *game, int x, int y, char *relative_path)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, x*H_MAX, y*H_MAX);
}


void ft_control_imgs(t_game *game, int x, int y, char c)
{
	if (c == '0')
		ft_put_img(game, x, y, "./img/cellule/20x20.xpm");
	else if (c == '1')
		ft_put_img(game, x, y, "./img/obstacle/20x20.xpm");
	else if (c == 'C')
		ft_put_img(game, x, y, "./img/points/20x20.xpm");
	else if (c == 'E')
		ft_put_img(game, x, y, "./img/exit/20x20.xpm");
	else if (c == 'P')
		ft_put_img(game, x, y, "./img/dog/20x20.xpm");
}

void	ft_add_imgs(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game->t_game[y])
	{
		x = 0;
		while (game->t_game[y][x])
		{
			ft_control_imgs(game, x, y,game->t_game[y][x]);
			x++;
		}
		y++;
	}
}

void	ft_create_map(t_game *game)
{
	ft_background_color(game);
	ft_add_imgs(game);
}
