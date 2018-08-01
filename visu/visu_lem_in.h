/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_lem_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:10:37 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/05 15:58:51 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_LEM_IN_H
# define VISU_LEM_IN_H

typedef struct s_link	t_link;

typedef struct s_room	t_room;

typedef struct		s_line
{
	char			*line;
	struct s_line	*nxt;
}					t_line;

typedef	struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

struct				s_link
{
	t_room			*link;
	t_link			*nxt;
};

struct				s_room
{
	t_coord			coord;
	int				dist;
	char			*name;
	int				s_or_e;
	t_link			*lst_link;
	t_room			*nxt;
};

typedef struct		s_info
{
	int				nb_ant;
	t_line			*lst_line;
	t_room			*room;
}					t_info;

typedef	struct		s_visu
{
	t_info			*data;
	void			*mlx;
	void			*win;
	char			*line;
}					t_visu;

typedef struct		s_col
{
	char			*name;
	struct s_col	*nxt;
}					t_col;

t_info				*ft_get_data(void);
int					ft_is_nant(char *line);
int					ft_is_room(char *line);
int					ft_is_link(char *line);
int					ft_is_instruc(char *line);
char				*ft_is_number(char *line, char c);
int					ft_is_comment(char *str);
int					ft_get_room(t_info *data, char *line, char *instruction);
int					ft_get_link(t_info *data, char *line);
char				*ft_next_char(char *str, char c);
void				ft_print_data(t_info *data);
t_info				*ft_add_line(t_info *data, char *line);
void				ft_loop(t_info *data);
void				ft_print_image(t_visu *v, void *mlx, void *win, t_col *c);
void				ft_resize_coord(t_info *data);
int					ft_sens(int depart, int arrivee);
void				ft_print_room(t_room *room, char *str, t_col *col);
t_col				*ft_get_col(void);
int					ft_get_s_or_e(char *instruction);
t_info				*ft_free_data(t_info *data);
void				ft_white_pixel(t_coord curseur, char *str);
void				ft_blue_pixel(t_coord curseur, char *str);
void				ft_green_pixel(t_coord curseur, char *str);
void				ft_red_pixel(t_coord curseur, char *str);
char				*ft_get_name(char *str, char c);
#endif
