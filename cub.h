/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:18:48 by mac               #+#    #+#             */
/*   Updated: 2024/06/14 21:32:24 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <signal.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define PIE 3.14
# define COS046 0.89438856137
# define SIN046 0.4472908464
# define DOF 50
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define SHIFT 257
# define BLUE "\033[34m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define RESET "\033[0m"
# define BOLD "\033[1m"
# ifndef CUB3D_H
#  define CUB3D_H

#  include <stdbool.h>

// Структура для хранения данных изображения
typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_data;

// Структура для хранения карты и её параметров
typedef struct map
{
	char			**points;
	char			**file_map;
	int				width;
	int				height;
	char			*t_n;
	char			*t_s;
	char			*t_e;
	char			*t_w;
	unsigned int	**i_n;
	unsigned int	**i_s;
	unsigned int	**i_e;
	unsigned int	**i_w;
	int				p_row;
	int				p_colom;
	int				f;
	int				c;
	unsigned int	***torch;
	int				tnum;
	int				torchnum;
}					t_map;

// Структура для хранения данных игрока
typedef struct player
{
	float			p_angle;
	float			p_dy;
	float			p_dx;
	float			p_y;
	float			p_x;
	bool			w;
	bool			s;
	bool			a;
	bool			d;
	bool			left;
	bool			right;
	bool			shift;
}					t_player;

// Основная структура игры, объединяющая все компоненты
typedef struct cub3d
{
	int				width;
	int				height;
	void			*mlx;
	void			*mlx_window;
	t_data			img;
	t_map			map;
	t_player		player;
	bool			m;
	int				fail;
}					t_cub3d;

// Структура для представления точки на плоскости
typedef struct point
{
	float			x;
	float			y;
}					t_point;

// Структура для расчётов при построении лучей (raycasting)
typedef struct casting
{
	int				rays;
	int				dof;
	float			x;
	float			distv;
	float			disth;
	float			distt;
	float			r_angle;
	float			angle_diff;
	t_point			rayh;
	t_point			rayv;
	t_point			off;
	t_point			player;
	t_point			lines;
	t_point			height;
}					t_cast;

// Структура для алгоритма DDA (Digital Differential Analyzer)
typedef struct flor_and_top
{
	int				i;
	float			s;
	float			t;
	float			y;
	float			x;
}					t_dda;

typedef struct text
{
	unsigned int	**texture;
	int				pixel_position;
	int				i;
	int				j;

}					t_text;

# endif // CUB3D_H

void				parsingfr(t_cub3d *cub3d, char *argv[]);
char				*reading(int fd);
void				mapread(t_cub3d *cub3d, int start);
int					file_check(char *string);
void				error_p(t_cub3d *game, char *str);
void				close_free(t_cub3d *cube);

int					texture_parse(t_cub3d *cub3d);

int					valid_letter(char letter);
void				validate_and_join(char **str, char *line, t_cub3d *cub3d);
char				*ft_strtrim_free(char *s1, char const *set);
void				check_player_exist(t_cub3d *cube);
void				map_size(t_cub3d *cub3d);
int					if_player(t_cub3d *cub3d, int c);
void				player_info(t_cub3d *cub3d);

void				wallcheck_vert(t_cub3d *cub3d, int row, int colom);
int					wallcheck_hor(t_cub3d *cub3d, int row, int colom);
void				check_valid(t_cub3d *cub3d, int row, int colom);
void				map_checker(t_cub3d *cub3d);
void				path_validate(t_cub3d *cube);

void				ft_freesplit(char **split);
void				free_point(unsigned int **map);
char				*get_pl(t_cub3d *cub3d, int c, char *str);
int					path_n_color(t_cub3d *cub3d, char *line, int c);
int					get_color(char *line);
int					create_trgb(int t, int r, int g, int b);
int					check_digit(char *string);

// execution
void				check_text(t_cub3d *game);
unsigned int		**create_texture(char *data, t_cub3d *game);
char				*load_image(t_cub3d *game, char *file_path, int *w, int *h);
unsigned int		**load_texture(t_cub3d *game, char *file_path, int w,
						int h);
void				get_text(t_cub3d *game);
void				create_map(t_cub3d *game);

// hooks
void				hooks(t_cub3d cub3d);
int					move(t_cub3d *game);
int					keyup(int keycode, t_cub3d *game);
int					close_esc(int keycode, t_cub3d *game);
int					keydown(int keycode, t_cub3d *game);
int					close_x(t_cub3d *game);

// moves check
void				check_boundaries(t_cub3d *game);
bool				condition(t_cub3d *game);
void				change_position(t_cub3d *game);
void				change_angle(t_cub3d *game);

// sets
void				set_sides_and_mlx(t_cub3d *game);
void				set_booleans(t_cub3d *game);
void				init(t_cub3d *game);
void				initialize_cast(t_cast *rend, t_cub3d *game);

// rays
void				render_rays(t_cub3d *game);
void				set_horizontals(t_cub3d *game, t_cast *cast);
void				set_rayh(t_cub3d *game, t_cast *cast);
void				set_vertical_rays(t_cub3d *game, t_cast *cast);
void				cast_vertical_ray(t_cub3d *game, t_cast *cast);
void				initialize_vertical_ray(t_cub3d *game, t_cast *cast);

// calculate
bool				v_angle(t_cast *cast);
bool				v_condition(t_point x1, float increase_x, float increase_y,
						int i);
void				pixel_put(t_data *data, int x, int y, int color);
float				dist(t_point player, t_point ray, float angle);
double				deg2rad(double degrees);
void				fov(t_cast *cast);
void				calculate_wals(t_cast *cast);

// draw
void				wall_text_h(t_point x1, t_point x2, t_cub3d *game,
						t_cast *cast);
void				wall_text_v(t_point x1, t_point x2, t_cub3d *game,
						t_cast *cast);
void				draw_all(t_cub3d *game, t_cast *cast);
void				draw_top(t_cub3d *game);
void				draw_floor(t_cub3d *game);
void				dda(t_point x1, t_point x2, t_cub3d *game, int color);
void				cast_n_project(t_cub3d *game, t_cast *cast);
void				draw(t_cub3d *game);
// void	torch(t_cub3d *cube, unsigned int **map);
unsigned int		**tor_load_tex(t_cub3d *game, char *file_path, int w,
						int h);
void				load_torches(t_cub3d *game);

#endif
