#include "pia.h"

int		ft_max(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}

int		ft_min(int i, int j)
{
	if (i < j)
		return (i);
	else
		return (j);
}

void	ft_base_cast(t_cmn_strct *cmn_strct)
{
	int		diap_x = 0;
	int		diap_y = 0;
	int		step = 0;
	int		shift_x = 0;
	int		shift_y = 0;
	int		i = 0;
	int		j = 0;

	ft_buf_zero(cmn_strct);
	ft_max_x(cmn_strct);
	ft_min_x(cmn_strct);
	ft_min_y(cmn_strct);
	ft_max_y(cmn_strct);
	diap_x = cmn_strct->mlx_strct.x_max - cmn_strct->mlx_strct.x_min;
	diap_y = cmn_strct->mlx_strct.y_max - cmn_strct->mlx_strct.y_min;
	step = ft_max(diap_x / (cmn_strct->mlx_strct.width) + 1, diap_y / (cmn_strct->mlx_strct.height) + 1);
	shift_x = (cmn_strct->mlx_strct.width - cmn_strct->mlx_strct.x_max / step) / 2;
	shift_y = (cmn_strct->mlx_strct.height - cmn_strct->mlx_strct.y_max / step) / 2;
	while (i < cmn_strct->serv_file[4].val)
	{
		j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (j < cmn_strct->ord_file[i].grps[1] - 1)
			{
				int y_start = cmn_strct->ord_file[i].o_data[j][2] / step + shift_y + cmn_strct->f_strct.shift_up;
				int y_end = cmn_strct->ord_file[i].o_data[j + 1][2] / step + shift_y + cmn_strct->f_strct.shift_up;
				int x_start = cmn_strct->ord_file[i].o_data[j][1] / step + shift_x + cmn_strct->f_strct.shift_rl;
				int x_end = cmn_strct->ord_file[i].o_data[j + 1][1] / step + shift_x + cmn_strct->f_strct.shift_rl;
				if (cmn_strct->mlx_strct.x_max / step + shift_x + cmn_strct->f_strct.shift_rl < 10)
					cmn_strct->f_strct.shift_rl += 50;
				if (cmn_strct->mlx_strct.x_min / step + shift_x + cmn_strct->f_strct.shift_rl > cmn_strct->mlx_strct.width - 10)
					cmn_strct->f_strct.shift_rl -= 50;
				if (cmn_strct->mlx_strct.y_min / step + shift_y + cmn_strct->f_strct.shift_up > cmn_strct->mlx_strct.height - 10)
					cmn_strct->f_strct.shift_up -= 50;
				if (cmn_strct->mlx_strct.y_max / step + shift_y + cmn_strct->f_strct.shift_up < 10)
					cmn_strct->f_strct.shift_up += 50;
				int y = y_start;
				while (y <= y_end && y < cmn_strct->mlx_strct.height - 10 && y > 0)
				{
					int x = x_start;
					if (x_start == x_end && x < cmn_strct->mlx_strct.width - 10 && x > 0)
					{
						if (cmn_strct->vv_file[i].data == 0)
							cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
						else
							cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
					}
					while (x < x_end && x < cmn_strct->mlx_strct.width - 10 && x > 0)
					{
						if (cmn_strct->vv_file[i].data == 0)
							cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
						else
							cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
						x++;
					}
					y++;
				}
			}
			j++;
		}
		i++;
	}	
}

void	ft_sim_cast(t_cmn_strct *cmn_strct)
{
	int		diap_x = 0;
	int		diap_y = 0;
	int		step = 0;
	int		shift_x = 0;
	int		shift_y = 0;
	int		i = 0;
	int		j = 0;
	int		dir = 0;
	int 	y;
	int		x;
	double	a = 0.0;

	ft_buf_zero(cmn_strct);
	ft_max_x(cmn_strct);
	ft_min_x(cmn_strct);
	ft_min_y(cmn_strct);
	ft_max_y(cmn_strct);
	diap_x = cmn_strct->mlx_strct.x_max - cmn_strct->mlx_strct.x_min;
	diap_y = cmn_strct->mlx_strct.y_max - cmn_strct->mlx_strct.y_min;
	step = ft_max(diap_x / (cmn_strct->mlx_strct.width) + 1, diap_y / (cmn_strct->mlx_strct.height) + 1);
	shift_x = (cmn_strct->mlx_strct.width - cmn_strct->mlx_strct.x_max / step) / 2;
	shift_y = (cmn_strct->mlx_strct.height - cmn_strct->mlx_strct.y_max / step) / 2;
	while (i < cmn_strct->serv_file[4].val)
	{
		j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			
			if (j < cmn_strct->ord_file[i].grps[1] - 1)
			{
				int y1 = cmn_strct->ord_file[i].ord_data[j][2] /*/ step*/ + shift_y + cmn_strct->f_strct.shift_up;
				int y2 = cmn_strct->ord_file[i].ord_data[j + 1][2] /*/ step*/ + shift_y + cmn_strct->f_strct.shift_up;
				int x1 = cmn_strct->ord_file[i].ord_data[j][1] /*/ step*/ + shift_x + cmn_strct->f_strct.shift_rl;
				int x2 = cmn_strct->ord_file[i].ord_data[j + 1][1] /*/ step*/ + shift_x + cmn_strct->f_strct.shift_rl;
				if (x1 < x2 && y1 < y2)
					dir = 1;
				else if (x1 < x2 && y1 > y2)
					dir = 2;
				else if (x1 > x2 && y1 > y2)
					dir = 3;
				else if (x1 > x2 && y1 < y2)
					dir = 4;
				else if (x1 == x2 && y1 < y2)
					dir = 5;
				else if (x1 < x2 && y1 == y2)
					dir = 6;
				else if (x1 == x2 && y1 > y2)
					dir = 7;
				else if (x1 > x2 && y1 == y2)
					dir = 8;
				if (cmn_strct->mlx_strct.x_max / step + shift_x + cmn_strct->f_strct.shift_rl < 10)
					cmn_strct->f_strct.shift_rl += 50;
				if (cmn_strct->mlx_strct.x_min / step + shift_x + cmn_strct->f_strct.shift_rl > cmn_strct->mlx_strct.width - 10)
					cmn_strct->f_strct.shift_rl -= 50;
				if (cmn_strct->mlx_strct.y_min / step + shift_y + cmn_strct->f_strct.shift_up > cmn_strct->mlx_strct.height - 10)
					cmn_strct->f_strct.shift_up -= 50;
				if (cmn_strct->mlx_strct.y_max / step + shift_y + cmn_strct->f_strct.shift_up < 10)
					cmn_strct->f_strct.shift_up += 50;
				if (dir == 1)
				{
					a = ((double)y2 - (double)y1) / ((double)x2 - (double)x1);
					y = y1;
					while (y <= y2 && y < cmn_strct->mlx_strct.height - 10 && y > 0)
					{
						x = x1;
						while (x < x2 && x < cmn_strct->mlx_strct.width - 10 && x > 0)
						{
							double check = ((double)x - (double)x1) * a + (double)y1;
							if (y == (int)check)
							{
								if (cmn_strct->vv_file[i].data == 0)
									cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
								else
									cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
							}
							x++;
						}
						y++;
					}
				}
				if (dir == 2)
				{
					a = ((double)y1 - (double)y2) / ((double)x2 - (double)x1);
					y = y1;
					while (y >= y2 && y < cmn_strct->mlx_strct.height - 10 && y > 0)
					{
						x = x1;
						while (x < x2 && x < cmn_strct->mlx_strct.width - 10 && x > 0)
						{
							double check = ((double)y1 - ((double)x - (double)x1) * a);
							if (y == (int)check)
							{
								if (cmn_strct->vv_file[i].data == 0)
									cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
								else
									cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
							}
							x++;
						}
						y--;
					}
				}
				if (dir == 4)
				{
					a = ((double)y1 - (double)y2) / ((double)x1 - (double)x2);
					y = y1;
					while (y <= y2 && y < cmn_strct->mlx_strct.height - 10 && y > 0)
					{
						x = x2;
						while (x < x1 && x < cmn_strct->mlx_strct.width - 10 && x > 0)
						{
							double check = (((double)x - (double)x1) * a) + (double)y1; 
							if (y == (int)check)
							{
								if (cmn_strct->vv_file[i].data == 0)
									cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
								else
									cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
							}
							x++;
						}
						y++;
					}
				}
				if (dir == 3)
				{
					a = ((double)y1 - (double)y2) / ((double)x1 - (double)x2);
					y = y1;
					while (y >= y2 && y < cmn_strct->mlx_strct.height - 10 && y > 0)
					{
						x = x2;
						while (x < x1 && x < cmn_strct->mlx_strct.width - 10 && x > 0)
						{
							double check = (((double)x1 - (double)x) * a) + (double)y1;
							if (y == (int)check)
							{
								if (cmn_strct->vv_file[i].data == 0)
									cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
								else
									cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
							}
							x++;
						}
						y--;
					}
				}
				if (dir == 6)
				{
					y = y1;
					x = x1;
					while (x <= x2 && x < cmn_strct->mlx_strct.width - 10 && x > 0)
					{
						if (y < cmn_strct->mlx_strct.height - 10 && y > 0)
						{
							if (cmn_strct->vv_file[i].data == 0)
								cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
							else
								cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
						}
						
						x++;
					}
				}
				if (dir == 7)
				{
					y = y2;
					x = x1;
					while (y <= y1 && y < cmn_strct->mlx_strct.height - 10 && y > 0)
					{
						if (x1== x2 && x < cmn_strct->mlx_strct.width - 10 && x > 0)
						{
							if (cmn_strct->vv_file[i].data == 0)
								cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
							else
								cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
						}
						y++;
					}
				}
				if (dir == 8)
				{
					y = y1;
					x = x2;
					while (x <= x1 && x < cmn_strct->mlx_strct.width - 10 && x > 0)
					{
						if (y < cmn_strct->mlx_strct.height - 10 && y > 0)
						{
							if (cmn_strct->vv_file[i].data == 0)
								cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
							else
								cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
						}
						
						x++;
					}
				}
				if (dir == 5)
				{
					y = y1;
					x = x1;
					while (y <= y2 && y < cmn_strct->mlx_strct.height - 10 && y > 0)
					{
						if (x1== x2 && x < cmn_strct->mlx_strct.width - 10 && x > 0)
						{
							if (cmn_strct->vv_file[i].data == 0)
								cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_base;
							else
								cmn_strct->mlx_strct.buf[cmn_strct->mlx_strct.height - y - 1][x] = cmn_strct->mlx_strct.clr_dfr;
						}
						y++;
					}
				}
			}
			j++;
		}
		i++;
	}	
}
