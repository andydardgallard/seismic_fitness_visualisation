#include "pia.h"

void    print_menu(t_cmn_strct *cmn_strct)
{
    int		y;
    char    c[10];

	y = 0;
	mlx_string_put(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, 15, y += 30, 0xC2B280, "Move: Up | Down | Left | Right");
	mlx_string_put(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, 15, y += 30, 0xC2B280, "Zoom In | Out: 1 | 2");
	mlx_string_put(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, 15, y += 30, 0xC2B280, "Simulation Forward: Q");
    mlx_string_put(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, 15, y += 30, 0xC2B280, "Simulation Backward: W");
    mlx_string_put(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, 15, y += 30, 0xC2B280, "Simulation Stop: S");
	mlx_string_put(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, 15, y += 30, 0xC2B280, "Exit: ESC");
	mlx_string_put(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, 15, y += 30, 0xC2B280, "Reset: E");
    mlx_string_put(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, 15, y += 30, 0xC2B280, "Show | Hide Menu: R");
    if (cmn_strct->f_strct.sim != -1)
    {
        gcvt(cmn_strct->d_file[cmn_strct->f_strct.sim].s * 100, 4, c);
        mlx_string_put(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.win, 15, y += 30, 0xC2B280, c);
    }
}
