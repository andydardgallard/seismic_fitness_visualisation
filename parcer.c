#include "pia.h"

void	ft_serv_struct_init(t_serv_file	*serv_file)
{
	int	i;

	i = 0;
	serv_file[0].smb = 'S';
	serv_file[1].smb = 'U';
	serv_file[2].smb = 'M';
	serv_file[3].smb = 'F';
	serv_file[4].smb = 'O';
	serv_file[5].smb = '\0';
	while(serv_file[i].smb != '\0')
	{
		serv_file[i].val = 0;
		i++;
	}
}

void	ft_parse_serv_file(char	*str, t_serv_file *serv_file)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	if (strchr(str, 'S'))
	{
		str++;
		while (serv_file[i].smb != '\0')
		{
			if (serv_file[i].smb == 'S')
				break ;
			i++;
		}
		serv_file[i].val = atoi(str);
	}
	else if (strchr(str, 'U'))
	{
		str++;
		while (serv_file[i].smb != '\0')
		{
			if (serv_file[i].smb == 'U')
				break ;
			i++;
		}
		serv_file[i].val = atoi(str);
	}
	else if (strchr(str, 'M'))
	{
		str++;
		while(serv_file[i].smb != '\0')
		{
			if (serv_file[i].smb == 'M')
				break ;
			i++;
		}
		serv_file[i].val = atoi(str);
	}
	else if (strchr(str, 'F'))
	{
		str++;
		while(serv_file[i].smb != '\0')
		{
			if (serv_file[i].smb == 'F')
				break ;
			i++;
		}
		serv_file[i].val = atoi(str);
	}
	else if (strchr(str, 'O'))
	{
		str++;
		while(serv_file[i].smb != '\0')
		{
			if (serv_file[i].smb == 'O')
				break ;
			i++;
		}
		serv_file[i].val = atoi(str);
	}
}

void	ft_open_read_serv_file(char **argv, t_serv_file *serv_file)
{
	int		i;
	int		fd;
	char	*buf;
	int		text;

	i = 1;
	fd = 0;
	text = 0;
	buf = 0;
	while (argv[i] != NULL)
	{
		if (strcmp(argv[i], "SERV_FILE.DAT") == 0)
		{
			fd = open(argv[i], O_RDONLY);
			while ((text = get_next_line(fd, &buf)))
			{
				if (text == -1)
					break ;
				ft_parse_serv_file(buf, serv_file);
				free(buf);
			}
			free(buf);
			close(fd);
		}
		i++;
	}
}

int		ft_cnt_tkn(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		i++;
		
	return (i);
}

void	ft_free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_parse_dplcmnt_file(char *str, t_dplcmnt_file *d_file, int *cnt)
{
	char	**tmp;
	
	while (*str == ' ')
		str++;
	tmp = ft_split(str, ' ');
	if (ft_cnt_tkn(tmp) == 1)
	{
		d_file[(*cnt)].s = atof(tmp[0]);
		(*cnt)++;
	}
	else if (ft_cnt_tkn(tmp) == 3)
	{
		d_file[(*cnt) - 1].s_data[atoi(tmp[0]) - 1][0] = atof(tmp[0]);
		d_file[(*cnt) - 1].s_data[atoi(tmp[0]) - 1][1] = atof(tmp[1]);
		d_file[(*cnt) - 1].s_data[atoi(tmp[0]) - 1][2] = atof(tmp[2]);
	}
	ft_free_arr(tmp);
}

void	ft_dplcmnt_struct_init(t_serv_file *serv_file, t_dplcmnt_file **d_file)
{
	int i;
	int	j;
	int k;

	i = 0;
	(*d_file) = (t_dplcmnt_file *)malloc(sizeof(t_dplcmnt_file) * serv_file[0].val);
	while (i < serv_file[0].val)
	{
		j = 0;
		(*d_file)[i].s_data = (float **)malloc(sizeof(float *) * serv_file[1].val);
		while (j < serv_file[1].val)
		{
			(*d_file)[i].s_data[j] = (float *)malloc(sizeof(float) * 3);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < serv_file[0].val)
	{
		j = 0;
		while (j < serv_file[1].val)
		{
			k = 0;
			while (k < 3)
			{
				(*d_file)[i].s_data[j][k] = 0.0;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_open_read_dplcmnt_file(char **argv, t_dplcmnt_file *d_file)
{
	int		i;
	int		fd;
	char	*buf;
	int		text;
	int		cnt;

	i = 1;
	fd = 0;
	text = 0;
	buf = 0;
	cnt = 0;
	while (argv[i] != NULL)
	{
		if (strcmp(argv[i], "Deplacement.RES") == 0)
		{
			fd = open(argv[i], O_RDONLY);
			while ((text = get_next_line(fd, &buf)))
			{
				if (text == -1)
					break ;
				ft_parse_dplcmnt_file(buf, d_file, &cnt);
				free(buf);
			}
			free(buf);
			close(fd);
		}
		i++;
	}
}

void	ft_ordnts_struct_init_one(t_serv_file **serv_file, t_ordnts_file **ord_file)
{
	int i;

	i = 0;
	(*ord_file) = (t_ordnts_file *)malloc(sizeof(t_ordnts_file) * (*serv_file)[4].val);
	while (i < (*serv_file)[4].val)
	{
		(*ord_file)[i].grps = (int *)malloc(sizeof(int) * 2);
		i++;
	}
}

void	ft_parse_ordnts_file_one(char *str, t_ordnts_file **ord_file, int *cnt)
{
	char	**tmp;

	while (*str == ' ')
		str++;
	tmp = ft_split(str, ' ');
	if (ft_cnt_tkn(tmp) == 2)
	{
		(*ord_file)[*cnt].grps[0] = atoi(tmp[0]);
		(*ord_file)[*cnt].grps[1] = atoi(tmp[1]);
		(*cnt)++;
	}
	ft_free_arr(tmp);
}

void	ft_ordnts_struct_init_two(t_serv_file **serv_file, t_ordnts_file **ord_file)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < (*serv_file)[4].val)
	{
		(*ord_file)[i].o_data = (int **)malloc(sizeof(int *) * (*ord_file)[i].grps[1]);
		j = 0;
		while (j < (*ord_file)[i].grps[1])
		{
			(*ord_file)[i].o_data[j] = (int *)malloc(sizeof(int) * 3);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < (*serv_file)[4].val)
	{
		j = 0;
		while (j < (*ord_file)[i].grps[1])
		{
			k = 0;
			while (k < 3)
			{
				(*ord_file)[i].o_data[j][k] = 0.0;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_open_read_ordnts_file_one(char **argv, t_ordnts_file **ord_file)
{
	int		i;
	int		fd;
	char	*buf;
	int		text;
	int		cnt;

	i = 1;
	fd = 0;
	text = 0;
	buf = 0;
	cnt = 0;
	while (argv[i] != NULL)
	{
		if (strcmp(argv[i], "ordinats.DAT") == 0)
		{
			fd = open(argv[i], O_RDONLY);
			while ((text = get_next_line(fd, &buf)))
			{
				if (text == -1)
					break ;
				ft_parse_ordnts_file_one(buf, ord_file, &cnt);
				free(buf);
			}
			free(buf);
			close(fd);
		}
		i++;
	}
}

void	ft_parse_ordnts_file_two(char *str, t_ordnts_file **ord_file, int *cnt, int *cnt_grps)
{
	char	**tmp;

	while (*str == ' ')
		str++;
	tmp = ft_split(str, ' ');
	if (ft_cnt_tkn(tmp) == 2)
	{
		(*cnt)++;
		(*cnt_grps) = 0;
	}
	else if (ft_cnt_tkn(tmp) == 4)
	{
		(*ord_file)[(*cnt) - 1].o_data[*cnt_grps][0] = atoi(tmp[0]);
		(*ord_file)[(*cnt) - 1].o_data[*cnt_grps][1] = atoi(tmp[1]);
		(*ord_file)[(*cnt) - 1].o_data[*cnt_grps][2] = atoi(tmp[2]);
		(*cnt_grps)++;
	}
	ft_free_arr(tmp);
}

void	ft_open_read_ordnts_file_two(char **argv, t_ordnts_file **ord_file)
{
	int		i;
	int		fd;
	char	*buf;
	int		text;
	int		cnt;
	int		cnt_grps;

	i = 1;
	fd = 0;
	text = 0;
	buf = 0;
	cnt = 0;
	cnt_grps = 0;
	while (argv[i] != NULL)
	{
		if (strcmp(argv[i], "ordinats.DAT") == 0)
		{
			fd = open(argv[i], O_RDONLY);
			while ((text = get_next_line(fd, &buf)))
			{
				if (text == -1)
					break ;
				ft_parse_ordnts_file_two(buf, ord_file, &cnt, &cnt_grps);
				free(buf);
			}
			free(buf);
			close(fd);
		}
		i++;
	}
}

void	ft_ordnts_handler(t_cmn_strct *cmn_strct)
{
	int i = 0;
	while (i < cmn_strct->serv_file[4].val)
	{
		int j = 0;
		while (j < cmn_strct->ord_file[i].grps[1])
		{
			if (cmn_strct->ord_file[i].o_data[j][2] > cmn_strct->img_strct.img_height)
				cmn_strct->img_strct.img_height = cmn_strct->ord_file[i].o_data[j][2];
			if (cmn_strct->ord_file[i].o_data[j][1] > cmn_strct->img_strct.img_width)
				cmn_strct->img_strct.img_width = cmn_strct->ord_file[i].o_data[j][1];
			j++;
		}
		i++;
	}
}

void	ft_parse_vv_file(char *str, t_vv35_file **vv_file, int *cnt)
{
	char	**tmp;

	while (*str == ' ')
		str++;
	tmp = ft_split(str, ' ');
	if (ft_cnt_tkn(tmp) >= 2)
	{
		(*vv_file)[*cnt].s = atoi(tmp[0]);
		(*vv_file)[*cnt].data = atoi(tmp[1]);
		(*cnt)++;
	}
	ft_free_arr(tmp);
}

void	ft_open_read_vv_file(char **argv, t_vv35_file **vv_file)
{
	int		i;
	int		fd;
	char	*buf;
	int		text;
	int		cnt;

	i = 1;
	fd = 0;
	text = 0;
	buf = 0;
	cnt = 0;
	while (argv[i] != NULL)
	{
		if (strcmp(argv[i], "VV35.DAT") == 0)
		{
			fd = open(argv[i], O_RDONLY);
			while ((text = get_next_line(fd, &buf)))
			{
				if (text == -1)
					break ;
				ft_parse_vv_file(buf, vv_file, &cnt);
				free(buf);
			}
			free(buf);
			close(fd);
		}
		i++;
	}
}

void	ft_parcer(char **argv, t_cmn_strct *cmn_strct)
{
	cmn_strct->serv_file = (t_serv_file *)malloc(sizeof(t_serv_file) * 6);
    ft_serv_struct_init(cmn_strct->serv_file);
    ft_open_read_serv_file(argv, cmn_strct->serv_file);
	ft_dplcmnt_struct_init(cmn_strct->serv_file, &cmn_strct->d_file);
    ft_open_read_dplcmnt_file(argv, cmn_strct->d_file);
	ft_ordnts_struct_init_one(&cmn_strct->serv_file, &cmn_strct->ord_file);
	ft_open_read_ordnts_file_one(argv, &cmn_strct->ord_file);
	ft_ordnts_struct_init_two(&cmn_strct->serv_file, &cmn_strct->ord_file);
	ft_open_read_ordnts_file_two(argv, &cmn_strct->ord_file);
	ft_ordnts_handler(cmn_strct);
	cmn_strct->vv_file = (t_vv35_file *)malloc(sizeof(t_vv35_file) * (cmn_strct->serv_file)[4].val);
	ft_open_read_vv_file(argv, &cmn_strct->vv_file);
}
