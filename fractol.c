#include "fractol.h"

int	main()
{
	t_mlx mlx;


	mlx.mlx_connect = mlx_init();
	if (NULL == mlx.mlx_connect)
	{
		free(mlx.mlx_connect);
		return(1);
	}
	mlx.mlx_win = mlx_new_window(mlx.mlx_connect, SIZE_X, SIZE_Y, "fract-ol");


	mlx_destroy_window(mlx.mlx_connect, mlx.mlx_win);
	mlx_destroy_display(mlx.mlx_connect);
	free(mlx.mlx_connect);
}
//int	main()
//{
//	void	*mlx_connect;
//	void	*mlx_window;
//
//	mlx_connect = mlx_init();
//	if (mlx_connect == NULL)
//		return (1);
//	mlx_window = mlx_new_window(mlx_connect, 1280, 720, "fract-ol");
//	if (NULL == mlx_window)
//	{
//		mlx_destroy_display(mlx_connect);
//		free(mlx_connect);
//		return (1);
//	}
//	mlx_loop(mlx_connect);
//
//}
