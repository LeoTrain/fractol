#include "../../includes/fractol.h"

t_errors	my_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return (ERROR_NONE);
	dest = img->address + (y * img->line_length + x * (img->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
	return (ERROR_NONE);
}
