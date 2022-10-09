#include "pia.h"

void	ft_mlx_struct_init(t_cmn_strct *cmn_strct)
{
    cmn_strct->mlx_strct.mlx = NULL;
    cmn_strct->mlx_strct.win = NULL;
    cmn_strct->mlx_strct.width = 2000;
    cmn_strct->mlx_strct.height = 1000;
	cmn_strct->mlx_strct.floor_r = 255;
	cmn_strct->mlx_strct.floor_g = 255;
	cmn_strct->mlx_strct.floor_b = 255;
	cmn_strct->mlx_strct.dfr_r = 255;
	cmn_strct->mlx_strct.dfr_g = 0;
	cmn_strct->mlx_strct.dfr_b = 0;
	cmn_strct->img_strct.img_height = -1;
	cmn_strct->img_strct.img_width = -1;
	cmn_strct->f_strct.zoom_f = 2;
	cmn_strct->f_strct.menu_f = 1;
	cmn_strct->f_strct.shift_up = 0;
	cmn_strct->f_strct.shift_rl = 0;
	cmn_strct->f_strct.sim = -1;
	cmn_strct->f_strct.q_is_pressed = 0;
	cmn_strct->f_strct.w_is_pressed = 0;
	cmn_strct->mlx_strct.x_max = 0;
	cmn_strct->mlx_strct.x_min = 0;
	cmn_strct->mlx_strct.y_min = 0;
	cmn_strct->mlx_strct.y_max = 0;
	cmn_strct->mlx_strct.clr_base = cmn_strct->mlx_strct.floor_b;
	cmn_strct->mlx_strct.clr_base = cmn_strct->mlx_strct.clr_base | cmn_strct->mlx_strct.floor_g << 8;
	cmn_strct->mlx_strct.clr_base = cmn_strct->mlx_strct.clr_base | cmn_strct->mlx_strct.floor_r << 16;
	cmn_strct->mlx_strct.clr_dfr = cmn_strct->mlx_strct.dfr_b;
	cmn_strct->mlx_strct.clr_dfr = cmn_strct->mlx_strct.clr_dfr | cmn_strct->mlx_strct.dfr_g << 8;
	cmn_strct->mlx_strct.clr_dfr = cmn_strct->mlx_strct.clr_dfr | cmn_strct->mlx_strct.dfr_r << 16;
	
}

void	ft_sim_buf_crt(t_cmn_strct *cmn_strct)
{
	int i;
	int j;

	i = 0;
	while (i < cmn_strct->serv_file[4].val)
	{
		cmn_strct->ord_file[i].ord_data = (int **)malloc(sizeof(int *) * cmn_strct->ord_file[i].grps[1]);
		j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			cmn_strct->ord_file[i].ord_data[j] = (int *)malloc(sizeof(int) * 3);
			j++;
		}
		i++;
	}
	int k = 0;
	while (k < cmn_strct->serv_file[1].val)
	{
		i = 0;
		while (i < cmn_strct->serv_file[4].val)
		{
			j = 0;
			while (j < cmn_strct->ord_file[i].grps[1])
			{
				if (cmn_strct->d_file[cmn_strct->f_strct.sim].s_data[k][0] == cmn_strct->ord_file[i].o_data[j][0])
				{
					cmn_strct->ord_file[i].ord_data[j][1] = cmn_strct->ord_file[i].o_data[j][1] + (cmn_strct->d_file[cmn_strct->f_strct.sim].s_data[k][1] * cmn_strct->serv_file[2].val);
					cmn_strct->ord_file[i].ord_data[j][2] = cmn_strct->ord_file[i].o_data[j][2] + (cmn_strct->d_file[cmn_strct->f_strct.sim].s_data[k][2] * cmn_strct->serv_file[2].val);
				}
				j++;
			}
			i++;
		}
		k++;
	}
}

void	ft_max_rsltn(t_cmn_strct *cmn_strct)
{
	int	max_size_x;
	int	max_size_y;

	mlx_get_screen_size(&max_size_x, &max_size_y);
	cmn_strct->mlx_strct.width = max_size_x - 80;
	cmn_strct->mlx_strct.height = max_size_y - 140;
}

void	ft_max_x(t_cmn_strct *cmn_strct)
{
	int i;
	int j;

	cmn_strct->mlx_strct.x_max = 0;
	i = 0;
	while (i < cmn_strct->serv_file[4].val)
	{
		j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (cmn_strct->mlx_strct.x_max <= cmn_strct->ord_file[i].o_data[j][1])
				cmn_strct->mlx_strct.x_max = cmn_strct->ord_file[i].o_data[j][1];
			j++;
		}
		i++;
	}
}

void	ft_max_x_sim(t_cmn_strct *cmn_strct)
{
	int i;
	int j;

	cmn_strct->mlx_strct.x_max = 0;
	i = 0;
	while (i < cmn_strct->serv_file[4].val)
	{
		j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (cmn_strct->mlx_strct.x_max <= cmn_strct->ord_file[i].ord_data[j][1])
				cmn_strct->mlx_strct.x_max = cmn_strct->ord_file[i].ord_data[j][1];
			j++;
		}
		i++;
	}
}

void	ft_min_x(t_cmn_strct *cmn_strct)
{
	int i = 0;

	cmn_strct->mlx_strct.x_min = cmn_strct->ord_file[0].o_data[0][1];
	while (i < cmn_strct->serv_file[4].val)
	{
		int j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (cmn_strct->mlx_strct.x_min >= cmn_strct->ord_file[i].o_data[j][1])
				cmn_strct->mlx_strct.x_min = cmn_strct->ord_file[i].o_data[j][1];
			if (cmn_strct->mlx_strct.x_min <= -50)
				cmn_strct->mlx_strct.x_min = 0;
			j++;
		}
		i++;
	}
}

void	ft_min_x_sim(t_cmn_strct *cmn_strct)
{
	int i = 0;

	cmn_strct->mlx_strct.x_min = cmn_strct->ord_file[0].ord_data[0][1];
	while (i < cmn_strct->serv_file[4].val)
	{
		int j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (cmn_strct->mlx_strct.x_min >= cmn_strct->ord_file[i].ord_data[j][1])
				cmn_strct->mlx_strct.x_min = cmn_strct->ord_file[i].ord_data[j][1];
			if (cmn_strct->mlx_strct.x_min <= -50)
				cmn_strct->mlx_strct.x_min = 0;
			j++;
		}
		i++;
	}
}

void	ft_min_y(t_cmn_strct *cmn_strct)
{
	int i = 0;

	cmn_strct->mlx_strct.y_min = cmn_strct->ord_file[0].o_data[0][2];
	while (i < cmn_strct->serv_file[4].val)
	{
		int j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (cmn_strct->mlx_strct.y_min >= cmn_strct->ord_file[i].o_data[j][2])
				cmn_strct->mlx_strct.y_min = cmn_strct->ord_file[i].o_data[j][2];
			if (cmn_strct->mlx_strct.y_min <= 0)
				cmn_strct->mlx_strct.y_min = 0;
			j++;
		}
		i++;
	}
}

void	ft_min_y_sim(t_cmn_strct *cmn_strct)
{
	int i = 0;

	cmn_strct->mlx_strct.y_min = cmn_strct->ord_file[0].ord_data[0][2];
	while (i < cmn_strct->serv_file[4].val)
	{
		int j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (cmn_strct->mlx_strct.y_min >= cmn_strct->ord_file[i].ord_data[j][2])
				cmn_strct->mlx_strct.y_min = cmn_strct->ord_file[i].ord_data[j][2];
			if (cmn_strct->mlx_strct.y_min <= 0)
				cmn_strct->mlx_strct.y_min = 0;
			j++;
		}
		i++;
	}
}

void	ft_max_y(t_cmn_strct *cmn_strct)
{
	int i = 0;

	cmn_strct->mlx_strct.y_max = 0;
	while (i < cmn_strct->serv_file[4].val)
	{
		int j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (cmn_strct->mlx_strct.y_max <= cmn_strct->ord_file[i].o_data[j][2])
				cmn_strct->mlx_strct.y_max = cmn_strct->ord_file[i].o_data[j][2];
			j++;
		}
		i++;
	}
}

void	ft_max_y_sim(t_cmn_strct *cmn_strct)
{
	int i = 0;

	cmn_strct->mlx_strct.y_max = 0;
	while (i < cmn_strct->serv_file[4].val)
	{
		int j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (cmn_strct->mlx_strct.y_max <= cmn_strct->ord_file[i].ord_data[j][2])
				cmn_strct->mlx_strct.y_max = cmn_strct->ord_file[i].ord_data[j][2];
			j++;
		}
		i++;
	}
}

void	ft_buf_zero(t_cmn_strct *cmn_strct)
{
	int i;
	int	j;

	i = 0;
	while (i < cmn_strct->mlx_strct.height)
	{
		j = 0;
		while (j < cmn_strct->mlx_strct.width)
		{
			cmn_strct->mlx_strct.buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	calc(t_cmn_strct *cmn_strct)
{
	if (cmn_strct->f_strct.sim == -1)
		ft_base_cast(cmn_strct);
	else
	{
		ft_sim_buf_crt(cmn_strct);
		ft_sim_cast(cmn_strct);
	}
}

void	ft_sim_forward(t_cmn_strct *cmn_strct)
{
	if (cmn_strct->f_strct.sim < cmn_strct->serv_file[0].val - 1)
		cmn_strct->f_strct.sim++;
}

void	ft_sim_back(t_cmn_strct *cmn_strct)
{
	if (cmn_strct->f_strct.sim > 0)
		cmn_strct->f_strct.sim--;
}

int		main_loop(t_cmn_strct *cmn_strct)
{	
	static int i = 0;
	if ((i++ < cmn_strct->serv_file[0].val - 1) && (cmn_strct->f_strct.q_is_pressed == 1))
	{
		ft_sim_forward(cmn_strct);
		usleep(cmn_strct->serv_file[3].val);
	}
	else
		cmn_strct->f_strct.q_is_pressed = 0;

	if ((i-- > 0) && (cmn_strct->f_strct.w_is_pressed == 1))
	{
		ft_sim_back(cmn_strct);
		usleep(cmn_strct->serv_file[3].val);
	}
	else
		cmn_strct->f_strct.w_is_pressed = 0;
	calc(cmn_strct);
	draw(cmn_strct);
	return (0);
}

void	ft_zoom_in(t_cmn_strct *cmn_strct)
{
	int i = 0;
	int j;

	while (i < cmn_strct->serv_file[4].val)
	{
		j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			cmn_strct->ord_file[i].o_data[j][1] = cmn_strct->ord_file[i].o_data[j][1] / cmn_strct->f_strct.zoom_f;
			cmn_strct->ord_file[i].o_data[j][2] = cmn_strct->ord_file[i].o_data[j][2] / cmn_strct->f_strct.zoom_f;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < cmn_strct->serv_file[0].val)
	{
		j = 0;
		while (j < cmn_strct->serv_file[1].val)
		{
			cmn_strct->d_file[i].s_data[j][1] = cmn_strct->d_file[i].s_data[j][1] / cmn_strct->f_strct.zoom_f;
			cmn_strct->d_file[i].s_data[j][2] = cmn_strct->d_file[i].s_data[j][2] / cmn_strct->f_strct.zoom_f;
			j++;
		}
		i++;
	}
	cmn_strct->mlx_strct.x_max = 0;	
}

void	ft_zoom_out(t_cmn_strct *cmn_strct)
{
	int i = 0;
	int j;

	while (i < cmn_strct->serv_file[4].val)
	{
		j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			cmn_strct->ord_file[i].o_data[j][1] = cmn_strct->ord_file[i].o_data[j][1] * cmn_strct->f_strct.zoom_f;
			cmn_strct->ord_file[i].o_data[j][2] = cmn_strct->ord_file[i].o_data[j][2] * cmn_strct->f_strct.zoom_f;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < cmn_strct->serv_file[0].val)
	{
		j = 0;
		while (j < cmn_strct->serv_file[1].val)
		{
			cmn_strct->d_file[i].s_data[j][1] = cmn_strct->d_file[i].s_data[j][1] * cmn_strct->f_strct.zoom_f;
			cmn_strct->d_file[i].s_data[j][2] = cmn_strct->d_file[i].s_data[j][2] * cmn_strct->f_strct.zoom_f;
			j++;
		}
		i++;
	}
}

void	ft_menu_flag(t_cmn_strct *cmn_strct)
{
	if (cmn_strct->f_strct.menu_f == 1)
		cmn_strct->f_strct.menu_f = 0;
	else
		cmn_strct->f_strct.menu_f = 1;
}

int		key_press(int key, t_cmn_strct *cmn_strct)
{
	if (key == 53)
		exit(0);
	if (key == 18)
		ft_zoom_in(cmn_strct);
	if (key == 19)
		ft_zoom_out(cmn_strct);
	if (key == 126)
		cmn_strct->f_strct.shift_up += 50;
	if (key == 125)
		cmn_strct->f_strct.shift_up -= 50;;
	if (key == 123)
		cmn_strct->f_strct.shift_rl -= 50;
	if (key == 124)
		cmn_strct->f_strct.shift_rl += 50;
	if (key == 12)
		cmn_strct->f_strct.q_is_pressed = 1;	
	if (key == 13)
		cmn_strct->f_strct.w_is_pressed = 1;
	if (key == 14)
	{
		cmn_strct->f_strct.sim = -1;
		cmn_strct->f_strct.shift_rl = 0;
		cmn_strct->f_strct.shift_up = 0;
		cmn_strct->f_strct.q_is_pressed = 0;
		cmn_strct->f_strct.w_is_pressed = 0;
	}
	if (key == 15)
		ft_menu_flag(cmn_strct);
	if (key == 1)
	{
		cmn_strct->f_strct.q_is_pressed = 0;
		cmn_strct->f_strct.w_is_pressed = 0;
	}
		
	return (0);
}

void	ft_buf_crt(t_cmn_strct *cmn_strct)
{
	int i;

	cmn_strct->mlx_strct.buf = (int **)malloc(sizeof(int *) * cmn_strct->mlx_strct.height);
	if (!(cmn_strct->mlx_strct.buf))
		exit(0);
	i = 0;
	while (i < cmn_strct->mlx_strct.height)
	{
		cmn_strct->mlx_strct.buf[i] = (int *)malloc(sizeof(int) * cmn_strct->mlx_strct.width);
		if (!(cmn_strct->mlx_strct.buf[i]))
			exit(0);
		i++;
	}
	ft_buf_zero(cmn_strct);
}

int		close_wind(void)
{
	exit(0);
	return (0);
}

void	ft_main_mlx(t_cmn_strct *cmn_strct)
{
	cmn_strct->mlx_strct.win = mlx_new_window(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.width, cmn_strct->mlx_strct.height, "pia");  
	cmn_strct->img_strct.img = mlx_new_image(cmn_strct->mlx_strct.mlx, cmn_strct->mlx_strct.width, cmn_strct->mlx_strct.height);
	cmn_strct->img_strct.data = (int *)mlx_get_data_addr(cmn_strct->img_strct.img, &cmn_strct->img_strct.bpp, &cmn_strct->img_strct.size_l, &cmn_strct->img_strct.endian);
	ft_buf_crt(cmn_strct);
	mlx_hook(cmn_strct->mlx_strct.win, 2, (1L << 0), &key_press, cmn_strct);
	mlx_hook(cmn_strct->mlx_strct.win, 17, (1L << 0), &close_wind, cmn_strct);
	mlx_loop_hook(cmn_strct->mlx_strct.mlx, &main_loop, cmn_strct);
}
