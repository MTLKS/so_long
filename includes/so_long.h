/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:52 by maliew            #+#    #+#             */
/*   Updated: 2022/08/31 17:20:15 by maliew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/includes/libft.h"
# include <mlx.h>

/* Game constants
** SCREEN_W			= Width of screen
** SCREEN_H			= Height of screen
** SPRITE_SIZE		= Size of one sprite
** STEP_SIZE		= Number of steps to move distance of SPRITE_SIZE
**						SPRITE_SIZE must be divisible by STEP_SIZE.
** LOOPS_PER_TICK	= The number of loop calls before loop hook runs
** ANIM_SPEED		= The speed of animation, lower value = faster speed
*/
# define SCREEN_W 640
# define SCREEN_H 320
# define SPRITE_SIZE 64
# define STEP_SIZE 4
# define LOOPS_PER_TICK 1000
# define MOVE_UP 0
# define MOVE_DOWN 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3
# define FACE_LEFT 0
# define FACE_RIGHT 1
# ifdef __APPLE__
#  define ANIM_SPEED 3
# else
#  define ANIM_SPEED 10
# endif

// Event definition
# define ON_DESTROY 17

// Key definition
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

typedef struct s_sl_data_addr
{
	char	*address;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_sl_data_addr;

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
	t_sl_anim	*idle_left;
	t_sl_anim	*idle_right;
	t_sl_anim	*walk_left;
	t_sl_anim	*walk_right;
	int			x;
	int			y;
	int			dir;
	int			move_count;
	t_list		*move_list;
}	t_sl_player;

typedef struct s_sl_enemy
{
	t_sl_anim	*idle_left;
	t_sl_anim	*idle_right;
	t_sl_anim	*walk_left;
	t_sl_anim	*walk_right;
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

typedef struct s_sl_imgs
{
	t_sl_img	*plyr_idle_left_1;
	t_sl_img	*plyr_idle_left_2;
	t_sl_img	*plyr_idle_right_1;
	t_sl_img	*plyr_idle_right_2;
	t_sl_img	*plyr_walk_left_1;
	t_sl_img	*plyr_walk_left_2;
	t_sl_img	*plyr_walk_right_1;
	t_sl_img	*plyr_walk_right_2;
	t_sl_img	*enem_idle_left_1;
	t_sl_img	*enem_idle_left_2;
	t_sl_img	*enem_idle_right_1;
	t_sl_img	*enem_idle_right_2;
	t_sl_img	*enem_walk_left_1;
	t_sl_img	*enem_walk_left_2;
	t_sl_img	*enem_walk_right_1;
	t_sl_img	*enem_walk_right_2;
	t_sl_img	*coll_1;
	t_sl_img	*coll_2;
	t_sl_img	*coll_3;
	t_sl_img	*coll_4;
	t_sl_img	*exit_open_1;
	t_sl_img	*exit_open_2;
	t_sl_img	*exit_open_3;
	t_sl_img	*exit_open_4;
	t_sl_img	*exit_closed_1;
	t_sl_img	*exit_closed_2;
	t_sl_img	*exit_closed_3;
	t_sl_img	*exit_closed_4;
	t_sl_img	*ground;
	t_sl_img	*wall;
	t_sl_img	*move_up;
	t_sl_img	*move_down;
	t_sl_img	*move_left;
	t_sl_img	*move_right;
}	t_sl_imgs;

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
	t_sl_imgs	*imgs;
}	t_sl_context;

void			sl_copy_image(t_sl_img *des, t_sl_img *src, int x, int y);
void			sl_parse_map(t_sl_context *c, char *path);
t_sl_img		*sl_xpm_to_img(void *mlx, char *path);
t_sl_img		*sl_new_img(void *mlx, int width, int height);

void			sl_print_context(t_sl_context *c);

t_sl_context	*sl_context_init(void);

t_sl_coll		*sl_coll_init(void);
void			sl_coll_add_coords(t_sl_coll *coll, int x, int y);
t_sl_img		*sl_coll_get_anim(t_sl_coll *coll, int frame);
int				*sl_coll_get_coords(t_sl_coll *coll, int index);
void			sl_coll_copy_all(t_sl_img *img, t_sl_context *c);

t_sl_anim		*sl_anim_init(void);
void			sl_anim_add_frame(t_sl_anim *anim, t_sl_img *img);
t_sl_img		*sl_anim_get_frame(t_sl_anim *anim, int index);

t_sl_exit		*sl_exit_init(void);
void			sl_exit_add_coords(t_sl_exit *exit, int x, int y);

t_sl_player		*sl_player_init(void);
void			sl_player_set_coords(t_sl_player *p, int x, int y);
t_sl_img		*sl_player_get_anim(t_sl_player *p);

t_sl_enemy		*sl_enemy_init(void);
void			sl_enemy_add_coords(t_sl_enemy *enemy, int x, int y, int dir);

void			sl_load_imgs(t_sl_context *ctx);

void			sl_move_player(t_sl_player *player);
void			*sl_move_new(int new_move);

void			sl_ui_display_moves(t_sl_context *c, t_sl_img *buffer_img);
t_sl_img		*sl_ui_get_move_img(t_sl_context *c, t_list *move_list);

#endif