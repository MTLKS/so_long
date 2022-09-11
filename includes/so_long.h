/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maliew <maliew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:12:52 by maliew            #+#    #+#             */
/*   Updated: 2022/09/11 17:55:44 by maliew           ###   ########.fr       */
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
# define SCREEN_W 1280
# define SCREEN_H 720
# define SPRITE_SIZE 64
# define STEP_SIZE 4
# define MOVE_UP 0
# define MOVE_DOWN 1
# define MOVE_LEFT 2
# define MOVE_RIGHT 3
# define FACE_LEFT 0
# define FACE_RIGHT 1
# ifdef __APPLE__
#  define ANIM_SPEED 5
#  define LOOPS_PER_TICK 500
# else
#  define ANIM_SPEED 5
#  define LOOPS_PER_TICK 5000
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

typedef struct s_sl_astar_node
{
	int						x;
	int						y;
	int						g_cost;
	int						h_cost;
	int						last_move;
	struct s_sl_astar_node	*prev_node;
}	t_sl_astar_node;

typedef struct s_sl_pathfind
{
	int		sx;
	int		sy;
	int		ex;
	int		ey;
	t_list	*moves;
}	t_sl_pathfind;

typedef struct s_sl_data_addr
{
	char	*address;
	int		pixel_bits;
	int		size_line;
	int		endian;
	int		pixel;
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
	int			x;
	int			y;
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
	char				*key;
	t_sl_img			*img;
	struct s_sl_imgs	*next;
}	t_sl_imgs;

typedef struct s_sl_context
{
	void		*mlx;
	void		*win;
	t_sl_img	*scene;
	t_sl_map	*map;
	t_sl_player	*player;
	t_sl_coll	*colls;
	t_sl_exit	*exit;
	t_sl_enemy	*enemies;
	t_sl_ui		*ui;
	t_sl_imgs	*imgs;
	int			move_count;
}	t_sl_context;

int				sl_close(t_sl_context *ctx);

void			sl_copy_image(t_sl_img *des, t_sl_img *src, int x, int y);

void			sl_parse_map_image(t_sl_context *ctx, char c, int x, int y);
void			sl_loop_map(t_sl_context *ctx,
					void (*f)(t_sl_context *ctx, char c, int x, int y));
void			sl_parse_map(t_sl_context *c, char *path);

t_sl_img		*sl_xpm_to_img(t_sl_context *ctx, char *path);
t_sl_img		*sl_new_img(void *mlx, int width, int height);
void			sl_img_free(t_sl_img *img, void *mlx);

void			sl_print_context(t_sl_context *c);

t_sl_context	*sl_context_init(void);
void			sl_context_free(t_sl_context *ctx);

t_sl_coll		*sl_coll_init(void);
void			sl_coll_add_coords(t_sl_coll *coll, int x, int y);
int				*sl_coll_get_coords(t_sl_coll *coll, int index);
void			sl_coll_copy_all(t_sl_img *img, t_sl_context *c);
void			sl_coll_check(t_sl_context *c);

void			sl_coll_free(t_sl_coll *coll);

t_sl_anim		*sl_anim_init(void);
void			sl_anim_add_frame(t_sl_anim *anim, t_sl_img *img);
t_sl_img		*sl_anim_get_frame(t_sl_anim *anim, int index);
void			sl_anim_free(t_sl_anim *anim);

t_sl_exit		*sl_exit_init(void);
void			sl_exit_set_coords(t_sl_context *ctx, int x, int y);
void			sl_exit_copy_all(t_sl_img *img, t_sl_context *c);
void			sl_exit_check(t_sl_context *c);
void			sl_exit_free(t_sl_exit *exit);

t_sl_player		*sl_player_init(void);
void			sl_player_set_coords(t_sl_context *ctx, int x, int y);
t_sl_img		*sl_player_get_anim(t_sl_player *p);
void			sl_player_free(t_sl_player *player);

t_sl_enemy		*sl_enemy_init(void);
void			sl_enemy_add_coords(t_sl_enemy *enemy, int x, int y, int dir);
void			sl_enemy_free(t_sl_enemy *enemy);

void			sl_load_imgs(t_sl_context *ctx);
void			sl_load_anims(t_sl_context *ctx);

void			sl_add_imgs(t_sl_context *ctx, char *key, char *path);
t_sl_img		*sl_get_imgs(t_sl_imgs *imgs, char *key);
void			sl_imgs_free(t_sl_imgs *imgs, void *mlx);

void			sl_move_player(t_sl_context *c);
void			*sl_move_new(int new_move);

void			sl_ui_display_moves(t_sl_context *c, t_sl_img *buffer_img);
t_sl_img		*sl_ui_get_move_img(t_sl_context *c, t_list *move_list);

int				sl_is_wall(t_sl_context *c, int x, int y);
void			sl_map_free(t_sl_map *map, void *mlx);
void			sl_init_map(t_sl_map **map);
void			sl_check_map(t_sl_context *ctx);

void			*sl_map_data_new(char *str);
void			sl_check_missing_key(t_sl_context *ctx);

void			sl_free_content(void *content);
void			sl_no_free_content(void *content);

int				sl_abs(int n);

void			sl_pathfind(t_sl_context *ctx, t_sl_pathfind *pf);

int				sl_astar_h_cost(int x, int y, int ex, int ey);
int				*sl_astar_get_neighbours(int x, int y);
t_sl_astar_node	*sl_astar_get_node(t_list *queue, int x, int y);
void			sl_astar_sort_queue(t_list *queue);

#endif