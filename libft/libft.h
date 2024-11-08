/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:35:00 by edalexan          #+#    #+#             */
/*   Updated: 2024/08/30 08:11:15 by edalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

// ....................LIBC FUNCTIONS (MADE BY EDALEXAN).......................
size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

long	ft_atoi(const char *nptr);

int		ft_isalpha(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

char	*ft_strnstr(const char *big, const char *little, size_t len);

//....................ALSO LIBC FUNCTIONS, BUT USING MALLOC NOW.................
char	*ft_strdup(const char *s);

void	*ft_calloc(size_t nmemb, size_t size);

//.............ADDITIONAL FUNCTIOS (YEAH, I REALLY DIDNT WANNA TO DO THAT)......
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *s);

char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int nb, int fd);
//Finally end yeahhhhhhhhhhhh... Lets go to BONUSSSSSS

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

//Personalizado para o GET_NEXT_LINE
char	*get_next_line(int fd);

//Personalizado para o FT_PRINTF
int		ft_process_specifier(char c, va_list list);
int		ft_print_str(char *str);
int		ft_print_ptr(void *i);
int		ft_print_nbr_u(unsigned int n);
int		ft_print_nbr(int n);
int		ft_print_hex(unsigned int i, const char format);
int		ft_print_chr(char c);
int		ft_printf(const char *format, ...);

// The things that i have coded by my own
void	ft_print_matrix(char **matrix);
void	ft_free_matrix(char **matrix);

#endif
