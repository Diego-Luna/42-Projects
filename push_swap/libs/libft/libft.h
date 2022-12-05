/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:35:22 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/05 15:59:56 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
// get_next_line

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Checker */
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isprint(char c);
int					ft_isascii(int c);

/* change */
int					ft_atoi(const char *str);
long int		ft_atoilz(const char *str);
char				*ft_itoa(int n);

/* Io */
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);

/* malloc */
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);

/* me */
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
						size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/* str */
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlen(const char *s);
void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
						size_t dstsize);

/* Bonus part */
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// main
int					ft_printf(const char *str, ...);

// controller
int					ft_print_and_length(va_list arg, char *str);
int					ft_percent_controller(va_list arg, char *str);

// utils
int					ft_putnbr_base(unsigned long nbr, char *base);

// caracteres
int					ft_result_sign(void);
int					ft_result_c(int arg);
int					ft_result_di(int arg);
int					ft_result_s(char *arg);
int					ft_result_p(unsigned long p);
int					ft_result_u(unsigned int arg);
int					ft_result_x(unsigned int arg, char *base);

// get_next_line
// main
char				*get_next_line(int fd);

// utils
// char	*ft_strdup(const char *str_1);
int					ft_contains_newline(const char *str);
void				*ft_malloc_zero(size_t count, size_t size);
char				*ft_join_strs(const char *str_1, const char *str_2);
void				ft_strs_cleans(char **str_1, char **str_2, char **str_3);

#endif