#ifndef PIA_H
# define PIA_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "./gnl/get_next_line.h"
# include "./mlx/mlx.h"

typedef struct  	s_serv_file
{
    char			smb;
    int				val;
}               	t_serv_file;

typedef struct		s_dplcmnt_file
{
    float			s;
    float			**s_data;
}					t_dplcmnt_file;

typedef	struct 		s_ordnts_file
{
	int				*grps;
	int				**o_data;
	int				**ord_data;
}					t_ordnts_file;

typedef	struct		s_vv35_file
{
    int				s;
	int				data;
}					t_vv35_file;

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef struct  	s_mlx
{
    void	    	*mlx;
	void	    	*win;
	int				**buf;
    int				width;
	int				height;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				dfr_r;
	int				dfr_g;
	int				dfr_b;
	int				clr_base;
	int				clr_dfr;
	int				x_max;
	int				x_min;
	int				y_min;
	int				y_max;
}               	t_mlx;

typedef	struct		s_flags
{
	int				zoom_f;
	int				shift_up;
	int				shift_rl;
	int				sim;
	int				menu_f;
	int 			q_is_pressed;
	int				w_is_pressed;
}					t_flags;

typedef	struct		s_cmn_strct
{
	t_serv_file		*serv_file;
	t_dplcmnt_file	*d_file;
	t_ordnts_file	*ord_file;
	t_vv35_file		*vv_file;
	t_mlx			mlx_strct;
	t_img			img_strct;
	t_flags			f_strct;
}					t_cmn_strct;

char				**ft_split(char const *s, char c);
void				ft_parcer(char **argv, t_cmn_strct *cmn_strct);
void				ft_mlx_struct_init(t_cmn_strct *cmn_strct);
void				ft_main_mlx(t_cmn_strct *cmn_strct);
void				draw(t_cmn_strct *cmn_strct);
void				ft_base_cast(t_cmn_strct *cmn_strct);
void				ft_max_rsltn(t_cmn_strct *cmn_strct);
void				ft_buf_zero(t_cmn_strct *cmn_strct);
void				ft_max_x(t_cmn_strct *cmn_strct);
void				ft_min_x(t_cmn_strct *cmn_strct);
void				ft_min_y(t_cmn_strct *cmn_strct);
void				ft_max_y(t_cmn_strct *cmn_strct);
void				ft_max_x_sim(t_cmn_strct *cmn_strct);
void				ft_min_x_sim(t_cmn_strct *cmn_strct);
void				ft_min_y_sim(t_cmn_strct *cmn_strct);
void				ft_max_y_sim(t_cmn_strct *cmn_strct);
void				ft_sim_cast(t_cmn_strct *cmn_strct);
void				ft_ordnts_struct_copy(t_cmn_strct *cmn_strct);
void				ft_ord_plus_dplcmnt(t_cmn_strct *cmn_strct);
void    			print_menu(t_cmn_strct *cmn_strct);
int					main_loop(t_cmn_strct *cmn_strct);
#endif