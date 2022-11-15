#include "so_long.h"

//  w : 13
//  a : 0
//  s : 1
//  d : 2
// int	deal_key(int key, void *param)
// {
// 	ft_printf("\n D: press : {%d} {%d}", key, param);
// 	return (0);
// }

// int main(void) {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();

// 	win_ptr = mlx_new_window(mlx_ptr, W_MAX, H_MAX, "Hello world!");

// 	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
// 	mlx_key_hook(win_ptr, deal_key, (void *)0);
// 	mlx_loop(mlx_ptr);
// }

int	main(void)
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Create Image");

	void *image = mlx_new_image(mlx, 640, 360);

	// The following code goes here.
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

	int color = 0xABCDEF;

	if (pixel_bits != 32)
		color = mlx_get_color_value(mlx, color);

	for (int y = 0; y < 360; ++y)
		for (int x = 0; x < 640; ++x)
		{
			int pixel = (y * line_bytes) + (x * 4);

			if (endian == 1) // Most significant (Alpha) byte first
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color)&0xFF;
			}
			else if (endian == 0) // Least significant (Blue) byte first
			{
				buffer[pixel + 0] = (color)&0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
		}
	mlx_put_image_to_window(mlx, win, image, 0, 0);

	mlx_loop(mlx);
}