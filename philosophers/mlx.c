#include <mlx.h>
// 5120 x 2880
int main()
{
	void *init = mlx_init();
	void *window = mlx_new_window (init, 5000, 2800, "multi_threading");
	int x = 0;
	int y = 0;

	while (y < 5000)
	{
		while (x < 2800)
		{
			mlx_pixel_put (init, window, x, y, 0x00FF0000);
			x++;
		}
		x = 0;
		y++;
	}
	(void)window;
	mlx_loop(init);
}
