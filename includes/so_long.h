/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:52 by maliew            #+#    #+#             */
/*   Updated: 2022/08/21 19:36:45 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/includes/libft.h"
# include <mlx.h>

# define ON_DESTROY 17

# define SCREEN_W 640
# define SCREEN_H 320
# define PLAYER_STEP 16
# define LOOPS_PER_TICK 1000

# ifdef __APPLE__
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_W 13
#  define KEY_ESC 53
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_DOWN 125
#  define KEY_UP 126
# else
#  define KEY_A 'a'
#  define KEY_S 's'
#  define KEY_D 'd'
#  define KEY_W 'w'
#  define KEY_ESC 65307
#  define KEY_LEFT 65363
#  define KEY_RIGHT 65361
#  define KEY_DOWN 65362
#  define KEY_UP 65364
# endif

typedef struct s_sl_img
{
	void	*img;
	int		width;
	int		height;
}	t_sl_img;

typedef struct s_sl_anim
{
	t_list		*frames;
	int			frame_count;
}	t_sl_anim;

typedef struct s_sl_player
{
	t_sl_anim	*s_left;
	t_sl_anim	*s_right;
	t_sl_anim	*w_left;
	t_sl_anim	*w_right;
	t_sl_anim	*sleep;
	int			x;
	int			y;
	int			dir;
}	t_sl_player;

typedef struct s_sl_enemy
{
	t_sl_anim	*s_left;
	t_sl_anim	*s_right;
	t_sl_anim	*w_left;
	t_sl_anim	*w_right;
	t_list		*coords;
}	t_sl_enemy;

typedef struct s_sl_coll
{
	t_sl_anim	*anim;
	t_list		*coords;
}	t_sl_coll;

typedef struct s_sl_exit
{
	t_sl_anim	*open;
	t_sl_anim	*closed;
	t_list		*coords;
}	t_sl_exit;

typedef struct s_sl_ui
{
	t_sl_img	*moves;
	t_sl_img	*map;
	t_sl_img	*up;
	t_sl_img	*down;
	t_sl_img	*left;
	t_sl_img	*right;
}	t_sl_ui;

typedef struct s_sl_map
{
	t_list		*data;
	t_sl_img	*img;
	int			width;
	int			height;
}	t_sl_map;

typedef struct s_sl_context
{
	void		*mlx;
	void		*win;
	t_sl_img	*scene;
	t_sl_map	*map;
	t_sl_player	*player;
	t_sl_coll	*colls;
	t_sl_exit	*exits;
	t_sl_enemy	*enemies;
	t_sl_ui		*ui;
}	t_sl_context;

void		sl_copy_image(t_sl_img *des, t_sl_img *src, int x, int y);
void		sl_parse_map(t_sl_context *c, char *path);
t_sl_img	*sl_xpm_to_img(void *mlx, char *path);
t_sl_img	*sl_new_img(void *mlx, int width, int height);

void		sl_print_context(t_sl_context *c);

t_sl_coll	*sl_coll_init(void);
void		sl_coll_add_coords(t_sl_coll *coll, int x, int y);
t_sl_img	*sl_coll_get_anim(t_sl_coll *coll);
int			*sl_coll_get_coords(t_sl_coll *coll, int index);
void		sl_coll_copy_all(t_sl_img *img, t_sl_context *c);

t_sl_anim	*sl_anim_init(void);
void		sl_anim_add_frame(t_sl_anim *anim, t_sl_img *img);
t_sl_img	*sl_anim_get_frame(t_sl_anim *anim, int index);

t_sl_player	*sl_player_init(void);
t_sl_img	*sl_player_get_anim(t_sl_player *p);

t_sl_enemy	*sl_enemy_init(void);
void		sl_enemy_add_coords(t_sl_enemy *enemy, int x, int y, int dir);

#endif