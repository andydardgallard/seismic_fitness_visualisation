#include "pia.h"

void	draw(t_cmn_strct *cmn_strct)
{
	int	y;
	int	x;
	
    y = 0;
	while (y < cmn_strct->mlx_strct.height)
	{
		x = 0;
		while (x < cmn_strct->mlx_strct.width)
		{
			cmn_strct->img_strct.data[y * cmn_strct->mlx_strct.width + x] = cmn_strct->mlx_strct.buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, cmn_strct->img_strct.img, 0, 0);
	if (cmn_strct->f_strct.menu_f == 1)
		print_menu(cmn_strct);
}
