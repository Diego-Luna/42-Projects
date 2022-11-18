/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:03:00 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 16:11:10 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_background_color_procces(t_img *im)
{
	im->pixel = (im->y * im->line_bytes) + (im->x * 4);
	if (im->endian == 1)
	{
		im->buffer[im->pixel + 0] = (im->color >> 24);
		im->buffer[im->pixel + 1] = (im->color >> 16) & 0xFF;
		im->buffer[im->pixel + 2] = (im->color >> 8) & 0xFF;
		im->buffer[im->pixel + 3] = (im->color) & 0xFF;
	}
	else if (im->endian == 0)
	{
		im->buffer[im->pixel + 0] = (im->color) & 0xFF;
		im->buffer[im->pixel + 1] = (im->color >> 8) & 0xFF;
		im->buffer[im->pixel + 2] = (im->color >> 16) & 0xFF;
		im->buffer[im->pixel + 3] = (im->color >> 24);
	}
}

void	ft_background_color(t_game *game)
{
	t_img	im;

	im.color = 0xABCDEF;
	im.image = mlx_new_image(game->mlx, game->with, game->heith);
	im.buffer = mlx_get_data_addr(im.image, &im.pixel_bits, \
		&im.line_bytes, &im.endian);
	im.y = -1;
	while (++im.y < game->heith)
	{
		im.x = -1;
		while (++im.x < game->with)
		{
			ft_background_color_procces(&im);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, im.image, 0, 0);
}

void	ft_put_img(t_game *game, int x, int y, char *relative_path)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(game->mlx, relative_path, &img_width,
			&img_height);
	mlx_put_image_to_window(game->mlx, game->win, img, x * H_MAX, y * H_MAX);
}
