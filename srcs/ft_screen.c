#include "../includes/libft.h"

void	ft_screen(w_point *win)
{
	int r; // a supprimer

	r = 0; // a supprimer
	r = r;
	ft_set_screen(win);
	// ft_red_pixel(win, 50, 160); // test
	// ft_printf("r = '%d'\n");
	// ft_printf("r = '%d'\n", ft_found_range(win, 270)); // test
	// r = ft_found_range(win, 0); // a supprimer
	// ft_printf("r = '%d'\n");
}

void	ft_set_screen(w_point *win)
{
	float	tan;
	float	value;

	tan = 0.57735026919;
	// ft_printf
	value = ((win->map->rx / 2) / tan);
	printf("Value : %f\n", value);
	win->screen_range = (int)value;
	// win->screen_range = (value % 10 < 5) ? (int)value : (int)value + 1;
	printf("screen range : %d\n", win->screen_range);
	ft_printf("before disp screen\n");
	ft_disp_screen(win);
	ft_printf("after disp screen\n");
	// win->screen_range = ((win->map->rx / 2) / tan);


}

void	ft_disp_screen(w_point *win)
{
	int x;
	int i;
	int u;
	double ang; // angle entre deux colones en degrés

	x = win->map->rx; // =nombre colones
	i = 0; // compteur colones
	ang = 60 / (double)win->map->rx;
	printf("ang : '%lf'\n", ang);

	u = (x % 2 == 0) ? x / 2 + 1 : x / 2; // zone où se situe les colones
	u = u;
	// ft_thales(win, win->d, u); // test angle droit // A REMETTRE ET MODIFIER LA FONCTION SUREMENT
	//affichage colone milieu
	while (i < (x / 2))
	{
		ft_thales(win, (ang * i), i + u);
		// affichage colone droite
		// affichage colone gauche
		i++;
	}
	// affichage colone supplémentaire si rx est pair



}