#include "pia.h"

int		ft_check_args(int argc, char **argv)
{
	int i;

	if (argc != 5)
	{
		printf("ERROR: wrong quantity of files\n");
		return (1);
	}	
	i = 1;
	while (argv[i] != NULL)
	{
		if ((strcmp(argv[i], "ordinats.DAT") != 0)
			&& (strcmp(argv[i], "SERV_FILE.DAT") != 0)
			&& (strcmp(argv[i], "Deplacement.RES") != 0)
			&& (strcmp(argv[i], "VV35.DAT") != 0))
		{
			printf("ERROR: wrong file name: <%s>. Replace file.\n", argv[i]);
			return (1);
		}	
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_cmn_strct	cmn_strct;
	
	if (ft_check_args(argc, argv))
		return (0);
	ft_mlx_struct_init(&cmn_strct);
	ft_parcer(argv, &cmn_strct);
	ft_max_rsltn(&cmn_strct);
	cmn_strct.mlx_strct.mlx = mlx_init();
	ft_main_mlx(&cmn_strct);
	mlx_loop(cmn_strct.mlx_strct.mlx);
	return(0);
}
