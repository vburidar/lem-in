/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:53:35 by vburidar          #+#    #+#             */
/*   Updated: 2018/04/06 17:33:35 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <string.h>
# include <wchar.h>

/*
**FT_PRINTF
*/
int					ft_printf(const char *format, ...);

/*
**CONVERSION
*/
char				*ft_affiche_d(va_list *pt_ap, char *str);
char				*ft_affiche_o(va_list *pt_ap, char *str);
char				*ft_affiche_u(va_list *pt_ap, char *str);
char				*ft_affiche_s(va_list *pt_ap, char *str);
char				*ft_affiche_p(va_list *pt_ap, char *str);
char				*ft_affiche_x(va_list *pt_ap, char *str);
char				*ft_affiche_per(va_list *pt_ap, char *str);
char				*ft_affiche_c(va_list *pt_ap, char *str);
char				*ft_affiche_b(va_list *pt_ap, char *str);
char				*ft_getwchar(wchar_t wc);

/*
** BASE TRANSFORMATION
*/
char				*ft_itoa_dec(long long n);
char				*ft_itoa_unbase(unsigned long long n, int base, int i);

/*
**PRECISION AND STRING MODIFICATIONS
*/
char				*ft_precision(char *str, char *tab_flag, char conv);
char				*ft_concat(char *str, unsigned int iter, char d, char flag);
char				*ft_plus_space(char *ret, char *tab_flag, int valeur);

/*
**LENGHT MODIFICATION
*/
unsigned long long	ft_size_var(char *tab_flag, va_list *pt_ap);
int					ft_find_double(char *tab_flag, char c);
int					ft_find_single(char *tab_flag, char c);

/*
**USEFUL TOOLS USED ALL THROUGH THE FONCTION
*/
void				ft_replace(char *str, char old, char new, char *tab_flag);
int					ft_zero(char *str);
int					ft_valid(char c);
char				*ft_secure_strsub(char *s, int start, int compteur);
int					ft_find_nb(char *adr);

/*
**LIBFT
*/
char				*ft_strcat(char *dest, const char *src);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*ft_strdup(const char *str);
char				*ft_strchr(const char *s, int c);
void				ft_bzero(void *pointer, size_t length);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
char				*ft_strjoin(const char *dest, const char *src, int free);
int					get_next_line(const int fd, char **line);
void				*ft_memchr(const void *src, int c, size_t taille);
void				ft_memdel(void *ap);
void				*ft_memmove(void *dest, void *src, size_t taille);
void				ft_bnull(void **pointer, size_t length);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, int size);
char				**ft_strsplit(const char *str, char c);
int					ft_abs(int value);

/*
**INITIALISATION OF ARRAYS
*/
void				ft_filltab(char tab[128]);
void				ft_add(char c, char tab[128]);
int					ft_fill_buff(const char *adr);

/*
**STRUCTURES
*/
typedef struct		s_tabf
{
	char			*(*pt_affiche)(va_list*, char*);
	char			tab[128];
}					t_tabf;

typedef struct		s_len
{
	int				len_str;
	int				len_flag;
}					t_len;

#endif
