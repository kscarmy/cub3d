/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2022/07/23 09:03:16 by guderram         ###   ########.fr       */
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
# include <stdio.h>
# include "../libft/libft.h"

# include "../mlx/mlx.h"
// # include "../mlx/mlx_int.h" // LINUX UNIQUEMENT
# define BUFFER_SIZE_GNL 32


# define KEY_MOVE_FRONT 119 // 13 // old 122 ?
# define KEY_MOVE_BACK 115 // 1 // old 100 ?
# define KEY_MOVE_LEFT 97 // 0 // old 113 ?
# define KEY_MOVE_RIGHT 100 // 2 // old 115 ?
# define KEY_ROTATE_LEFT 65361 // 123 // old 65361 ?
# define KEY_ROTATE_RIGHT 65363 // 124 // old 65363 ?
# define KEY_ECHAP 65307 // 53 // old 65307 ?
# define MOVE_SIZE 8
# define FOV_SIZE 60
# define ANG_SIZE 5


/*	******	*/
/*	 GNL	*/
/*	******	*/

/*	get_next_line.c	*/
char	*ft_strsub_bis(int **error);
char	*ft_strsub(char const *s, unsigned int start, size_t len, int **error);
void	ft_read(char **str, char **line, int ret, int *error);
int		get_next_line_bis(int error, int ret, char *str);
int		get_next_line(int fd, char **line);

/*	get_next_line_bis.c	*/
int		ft_exerror(char **str, int error);
void	ft_strdel(char **as);

/*	get_next_line_utils.c	*/
int		ft_strlen(char *str);
char	*ft_strnew(int *error);
int		ft_strchr(char *str);
int		ft_strcount(char *str);
void	ft_strjoin(char **str, const char *buff, int buff_size, int *error);

typedef struct	j_point
{
	int		er; // pas d'erreurs : 0, erreurs : >0
	int 	rx; // résolution : largeur
	int		ry; // résolution : hauteur
	int		x; // tete de lecture utilisé dans : file,
	char	*fl; // contien une copie fichier à lire.
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
	int	i;
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
	int		orient; // orientation de langle de vue
}				w_point;









/*	main.c	*/
int		main(int argc, char **argv);




/*	******	*/
/*	 MOVE	*/
/*	******	*/

/*	ft_entry_key.c	*/
int		ft_entry_keyboard(int key, void *p);

/*	ft_position.c	*/
void	ft_map_disp_pos(w_point *win);
void	ft_move_in_casa(w_point *win);
int		ft_move_zqsd(int key, w_point *win);


/*	*******	*/
/*	 UTILS	*/
/*	*******	*/

/*	ft_error_1.c	*/
int		ft_exor_nfn(int error);
void	ft_map_disp_error(m_point *m, int l, int x, int erreur);
void	ft_show_error_file_bis(m_point *m, int u, int i, int j);
void	ft_show_error_file(m_point *m);
void	ft_error_detected(m_point *m);

/*	ft_utils.c	*/
double	ft_degrees_to_radian(double deg);
double	ft_radian_to_degrees(double rad);
void	ft_red_pixel(w_point *w, int h, int x);
int		ft_str_size(char *str);
int		ft_is_entier(double a); // retourne 1 si le nombre n'est pa entier sinon 0


/*	**********	*/
/*	 PARSING	*/
/*	**********	*/

/*	ft_check_file_name.c	*/
int	ft_check_open(char *argv); // renvoie 0 si fd ok, 1 si erreur.
int	ft_check_file_name_end(int extension, int exist, int u);
int	ft_check_file_name(char *argv, int extension);

/*	ft_parsing_map_data.c	*/
void	ft_parsing_resolution(m_point *m);
int		ft_parsing_while(m_point *m, int z);
void    ft_parsing_floor(m_point *m);
void    ft_parsing_ceiling(m_point *m);
char    *ft_parsing_get_path(m_point *m, int z);

/*	ft_parsing_map_data_bis.c	*/
void	ft_parsing_path_to_bis(m_point *m, int y, int z);
void    ft_parsing_path_to(m_point *m);

/*	ft_parsing_map_map.c	*/
void ft_create_mapping_bis(m_point *m, int u);
void    ft_create_mapping(m_point *m);
void	ft_found_map_bis(m_point *m, int u);
void    ft_found_map(m_point *m);
void    ft_fill_map(m_point *m);

/*	ft_parsing_map_map_bis.c	*/
void    ft_fill_line_map(m_point *m, int l); // l est la ligne à malloc :)
void	ft_parse_map_bis(m_point *m, int l, int x);
void    ft_parse_map(m_point *m);
void    ft_check_map(m_point *m); // call toutes les merdes pour la map

/*	ft_parsing_map_utils.c	*/
void    ft_set_world_spawn(m_point *m, int u);
int     ft_is_not_map(char c, int one);
int     ft_next_zero_char(char c);
void     ft_next_zero_map(m_point *m, int l, int x);

/*	ft_parsing_map.c	*/
void    ft_check_fl_half(m_point *m);
void	ft_strfreejoin_newline_bis(m_point *m, char *buff, int i, int u);
void	ft_strfreejoin_newline(m_point *m, char *buff);
void    ft_parsing_open_fd(m_point *m, char *argv);
int	ft_parsing_map_bis(m_point *m);
int		ft_parsing_map(m_point *m, char *argv);

/*	ft_parsing_utils.c	*/
int		ft_incre_spaces(m_point *m, int backn, int h); // retourne u espaces rencontré dans map->fil[map->x + h] ou h est un head
int		ft_is_space(char c, int backn, int end, m_point *m);
int		ft_is_color(int color); // Si color faux return 1, sinon 0

/*	ft_structs.c	*/
void	ft_init_map(m_point *m);
void	ft_disp_verif(m_point *m);
void	ft_exit_free_map_paths(m_point *m);
int		ft_exit_free_map(m_point *m, int ret);


#endif