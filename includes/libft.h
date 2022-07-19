/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2022/07/19 23:10:55 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>


# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"


# include <stdio.h> // A SUPPRIMER

# define BUFFER_SIZE 32 // gnl

# define KEY_MOVE_FRONT 119 // 13 // old 122 ?
# define KEY_MOVE_BACK 115 // 1 // old 100 ?
# define KEY_MOVE_LEFT 97 // 0 // old 113 ?
# define KEY_MOVE_RIGHT 100 // 2 // old 115 ?
# define KEY_ROTATE_LEFT 65361 // 123 // old 65361 ?
# define KEY_ROTATE_RIGHT 65363 // 124 // old 65363 ?
# define KEY_ECHAP 65307 // 53 // old 65307 ?
# define MOVE_SIZE 8
# define FOV_SIZE 60
# define ANG_SIZE 45

typedef struct	s_point
{
	va_list				ap;
	int					ret;
	int					i;
	int					u;
	int					wdh;
	int					pco;
	int					siz;
	char				*str;
	char				*fmt;
	char				c;
	char				typ;
	char				fag;
	char				d[64];
	int					t;
	unsigned long long	ull;
	int					b;
	int					maj;
	int					g;
	unsigned int		ui;
}				t_point;

typedef struct	j_point
{
	int		error; // pas d'erreurs : 0, erreurs : >0
	int 	rx; // résolution : largeur
	int		ry; // résolution : hauteur
	int		x; // tete de lecture utilisé dans : file, 
	char	*file; // contien une copie fichier à lire.
	int 	res; // de base res = 0, si la résolution est définie alors res = 1
	int		fr; // Floor : Red
	int		fg; // Floor : Green
	int		fb; // Floor : Blue
	int		floor; // de base floor = 0, si la couleur du sol est définie alors floor = 1
	int		cr; // Ceiling : Red
	int		cg; // Ceiling : Green
	int		cb; // Ceiling : Blue
	int		ceiling; // de base ceiling = 0, si la couleur du sol est définie alors ceiling = 1
	char	*no; // ./path_to_the_north_texture
	char	*so; // ./path_to_the_south_texture
	char	*we; // ./path_to_the_west_texture
	char	*ea; // ./path_to_the_east_texture
	char	*s; // ./path_to_the_sprite_texture
	char	spawn; // Position de spawn du joueur
	char	**map; // La map mdrr
	int		l; // nombre de lignes de la map
}				m_point;

typedef	struct v_point // structure de calcul : ca
{
	double x; // position dans la map corrigée
	double y; // position dans la map corrigée

	double fvcs; // first vertical calc size;
	double fvcx; // first vertical calc x
	double fvcy; // first vertical calc y

	double vcs; // vertical calc size;
	double vcx; // vertical calc x
	double vcy; // vertical calc y

	double vs; // vertical size;
	double vx; // vertical x
	double vy; // vertical y

	double fhcs; // first horizontal calc size;
	double fhcx; // first horizontal calc x
	double fhcy; // first horizontal calc y

	double hcs; // horizontal calc size;
	double hcx; // horizontal calc x
	double hcy; // horizontal calc y

	double hs; // horizontal size;
	double hx; // horizontal x
	double hy; // horizontal y

	double cx; // calc x
	double cy; // calc y
	double cr; // calc range

	double ox; // original x
	double oy; // original y
	double phx; // horizontal position x
	double phy; // horizontal position y
	double pvx; // vertical position x
	double pvy; // vertical position y
	double deg; // variable degree
	double rad; // variable radians
	double hray; // variable horizontal rayon
	double ohray; // variable old horizontal rayon
	double vray; // variable vertical rayon
	double ovray; // variable old vertical rayon
}				c_point;

typedef struct k_point
{
	void	*mlx; // Le mlx requis pour utiliser la mlx
	void	*win1; // Première fenetre d'affichage
	int		error; // Pas d'erreurs = 0, erreurs = >0
	m_point	*map; // Lien direct vers la structure map
	int		pos_x; // position dans la case en x du perso
	int		pos_y; // position dans la case en y du perso
	// char	**casa; // position globale sur la map ( la case ) // old
	int		x; // position sur la map du perso
	int		y; // position sur la map du perso
	double	d; // angle où se situe la vue du perso (d pour degré) : entre 0 et 359, où 0 regarde totalement direction nord
	int		move_size; // définis la taille d'un déplacement dans une case /!\ move_size < 100 && > 0 !
	int		d_size; // définis la taille de degrés de rotation de d lorsque la touche est pressée
	int		screen_range; // distance entre la camera et lecran.
	int		max_x; // max de x dans la ligne
	int		max_y; // max de y dans la map
	c_point *ca; // struct de calculs
}				w_point;


/*	main.c	*/
int		main(int argc, char **argv);


/*	******	*/
/*	 CALC	*/
/*	******	*/

/*	ft_range.c	*/
double	ft_pytha(double x, double y); // rend la distance
void	ft_reset_ca(w_point *w);
int		ft_is_wall(m_point *map, double x, double y); // renvoie 1 sur mur, sinon 0
double	ft_inf_one(double i); // renvoie ce qui est apres la virgule

double	ft_right_angle(w_point *w, double d);
double	ft_ret_range(double x, double y, double xx, double yy); // renvoie la distance des deux points
double	ft_abs(double i); // renvoie la valeur absolue dun double


/*	ft_thales.c	*/
void	ft_set_ca(w_point *win);
double	ft_converte_angle(double d, double a, int sig); // sig = addition 1 ou soustraction 0
double	ft_found_angle(w_point *win, double d);
void	ft_thales(w_point *win, double a, int c, int i);

/*	ft_vc.c	*/
void	ft_vc_add(w_point *w, double d); // rajoute les zones de calculs au point en question
void	ft_vc_pytha(w_point *w, double d);
void	ft_first_vc_pytha(w_point *w, double d);
void	ft_first_vc(w_point *w, double d);
double	ft_while_vc(w_point *w, double d);

/*	ft_hc.c	*/

void	ft_hc_add(w_point *w, double d); // rajoute les zones de calculs au point en question
void	ft_hc_pytha(w_point *w, double d);
void	ft_first_hc_pytha(w_point *w, double d);
void	ft_first_hc(w_point *w, double d);
double	ft_while_hc(w_point *w, double d);


/*	******	*/
/*	 DISP	*/
/*	******	*/

/*	ft_screen.c	*/
void	ft_screen(w_point *win);
void	ft_set_screen(w_point *win);
void	ft_disp_screen(w_point *win);

/*	ft_windows.c	*/
void	ft_init_win(w_point *win, m_point *mapi, c_point *cal); // mapi = map
int		ft_is_worldspawn(char c);
void	ft_found_worldspawn(w_point *win);
void	ft_exit_free_all(w_point *win, int ret);
void	ft_windows(m_point *map);


/*	******	*/
/*	 MOVE	*/
/*	******	*/

/*	ft_entry_key.c	*/
int		ft_entry_keyboard(int key, void *p);

/*	ft_position.c	*/
void	ft_map_disp_pos(w_point *win);
void	ft_move_in_casa(w_point *win);
int		ft_move_zqsd(int key, w_point *win);

/*	trigo.c	*/
//int		convert_to_radian(int degree);
//int		find_x(int d, int h);
//int		find_y(int d, int h);
double	convert_to_radian(double degree);
double	find_x(double d, double h);
double	find_y(double d, double h);


/*	*******	*/
/*	 UTILS	*/
/*	*******	*/

/*	ft_error_1.c	*/
int		ft_exor_nfn(int error);
void	ft_map_disp_error(m_point *map, int l, int x, int erreur);
void	ft_show_error_file(m_point *map);
void	ft_error_detected(m_point *map);

/*	ft_utils.c	*/
double	ft_degrees_to_radian(double deg);
double	ft_radian_to_degrees(double rad);
void	ft_red_pixel(w_point *win, int h, int x);
int		ft_str_size(char *str);
int		ft_is_entier(double a); // retourne 1 si le nombre n'est pa entier sinon 0


/*	**********	*/
/*	 PARSING	*/
/*	**********	*/

/*	ft_check_file_name.c	*/
int	ft_check_open(char *argv); // renvoie 0 si fd ok, 1 si erreur.
int	ft_check_file_name(char *argv, int extension);

/*	ft_parsing_map_data.c	*/
void ft_parsing_resolution(m_point *map);
void    ft_parsing_floor(m_point *map);
void    ft_parsing_ceiling(m_point *map);
char    *ft_parsing_get_path(m_point *map, int z);
void    ft_parsing_path_to(m_point *map);

/*	ft_parsing_map_map.c	*/
void    ft_create_mapping(m_point *map);
void    ft_found_map(m_point *map);
void    ft_fill_map(m_point *map);
void    ft_fill_line_map(m_point *map, int l); // l est la ligne à malloc :)
void    ft_parse_map(m_point *map);
void    ft_check_map(m_point *map); // call toutes les merdes pour la map

/*	ft_parsing_map_utils.c	*/
void    ft_set_world_spawn(m_point *map, int u);
int     ft_is_not_map(char c, int one);
int     ft_next_zero_char(char c);
void     ft_next_zero_map(m_point *map, int l, int x);

/*	ft_parsing_map.c	*/
void    ft_check_file_half(m_point *map);
void	ft_strfreejoin_newline(m_point *map, char *buff);
void    ft_parsing_open_fd(m_point *map, char *argv);
int		ft_parsing_map(m_point *map, char *argv);

/*	ft_parsing_utils.c	*/
int		ft_incre_spaces(m_point *map, int backn, int h); // retourne u espaces rencontré dans map->fil[map->x + h] ou h est un head
int		ft_is_space(char c, int backn, int end, m_point *map);
int		ft_is_color(int color); // Si color faux return 1, sinon 0

/*	ft_structs.c	*/
void	ft_init_map(m_point *map);
void	ft_disp_verif(m_point *map);
int		ft_exit_free_map(m_point *map, int ret);



int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset (void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char	*source, const char *objet, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t destsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
int				ft_gnl_strlen(char *str);
char			*ft_gnl_strnew(int *error);
int				ft_gnl_strchr(char *str);
int				ft_gnl_strcount(char *str);
void			ft_gnl_strjoin
(char **str, const char *buff, int buff_size, int *error);
int				ft_gnl_exerror(char **str, int error);
void			ft_gnl_strdel(char **as);
char			*ft_gnl_strsub
(char const *s, unsigned int start, size_t len, int **error);
void			ft_gnl_read(char **str, char **line, int ret, int *error);
int				ft_get_next_line(int fd, char **line);

int				ft_printf(const char *format, ...);
void			ft_init_ptf(t_point	*ptf, char *format);
void			ft_putchar_printf(char c, t_point *ptf);
void			ft_putstr_printf(char *str, t_point *ptf);
void			ft_know_flags(t_point *ptf);
void			ft_know_width(t_point *ptf);
void			ft_know_precision(t_point *ptf);
void			ft_ana_types(t_point *ptf);
int				ft_make_type(char type, t_point *ptf);
int				ft_find_type(t_point *ptf);
void			ft_ana_flags(t_point *ptf);
void			ft_printf_s(t_point *ptf);
void			ft_clear_ptf(t_point *ptf);
int				ft_printf_strlen(char *str);
void			ft_printf_percent(t_point *ptf);
void			ft_printf_c(t_point *ptf);
void			ft_printf_d(t_point *ptf);
void			ft_printf_itoa(t_point *ptf);
void			ft_printf_d_disp(t_point *ptf);
void			ft_printf_itoa_init(t_point *ptf);
void			ft_printf_d_incre(int x, t_point *ptf);
void			ft_printf_d_suite(t_point *ptf);
int				ft_printf_d_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			ft_printf_p(t_point *ptf);
void			ft_printf_p_suite(t_point *ptf);
void			ft_printf_p_incre(int x, t_point *ptf);
void			ft_printf_itoa_ull(t_point *ptf);
void			ft_printf_p_disp(t_point *ptf);
void			ft_printf_p_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			ft_printf_u(t_point *ptf);
void			ft_printf_u_suite(t_point *ptf);
void			ft_printf_itoa_u(t_point *ptf);
int				ft_printf_u_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			ft_printf_u_disp(t_point *ptf);
void			ft_printf_x(t_point *ptf);
void			ft_printf_x_suite(t_point *ptf);
void			ft_printf_itoa_x(t_point *ptf);
void			ft_printf_x_disp(t_point *ptf);
void			ft_printf_x_disp_suite(int *m, int *a, int *u, t_point *ptf);
int				ft_false_type(t_point *ptf);
void			ft_printf_itoa_ll(t_point *ptf);

#endif
