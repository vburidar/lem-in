/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:42:38 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 17:41:56 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

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

typedef struct		s_path
{
	t_room			*room;
	struct s_path	*nxt;
}					t_path;

typedef struct		s_path_pack
{
	t_path			*init;
	t_path			*current;
	t_path			*best;
}					t_path_pack;

typedef struct		s_ant
{
	t_room			*room;
	int				nb;
	struct s_ant	*nxt;
}					t_ant;

t_info				*ft_get_data(int argc);

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
t_path				*ft_get_path(t_info *data, t_path_pack path_p);
void				ft_fill_path(t_info *data, t_path *best);
t_info				*ft_add_line(t_info *data, char *line);
t_info				*ft_free_data(t_info *data);
void				ft_free_path(t_path *path);
void				ft_free_ant(t_ant *ant);
int					ft_get_s_or_e(char *instruction);
int					ft_dellastline(t_info *data);
t_info				*ft_free_l(char *line);
t_room				*ft_get_nxt_room(t_room *room, char *line);
int					ft_is_s_or_e(char *line);
int					ft_big_nb(char *line);

#endif
