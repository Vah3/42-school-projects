/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:17:55 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 19:55:54 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

char	**ft_split(char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	**init_map(char *filename);
size_t	ft_strlen(const char *s);
void	calculate(int *len, int *height, char **map);
void	window_image(int len, int height, char **map);
typedef struct vars{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	void	*img9;
	int		len;
	int		height;
	char	***map;
	int		count;
}	t_vars;
int		points(t_vars *vars);
void	maps(t_vars wind, char **map);
void	move_w(t_vars *vars, int i, int j);
void	move_s(t_vars *vars, int i, int j);
void	move_a(t_vars *vars, int i, int j);
void	move_d(t_vars *vars, int i, int j);
void	printpoints(t_vars vars);
void	finish(t_vars *vars);
void	exitchange(t_vars *vars);
void	map_z(t_vars wind, int c, int b);
void	map_e(t_vars wind, int c, int b);
void	map_c(t_vars wind, int c, int b);
void	map_p(t_vars wind, int c, int b);
void	mapimage(t_vars wind, int c, int b, char **map);
void	keycodehook(int keycode, t_vars *vars, int i, int j);
int		ft_close(int key, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	xpmtoimage(t_vars *wind, int *x, int *y);
void	animutils(t_vars *vars);
void	rip(t_vars *vars, int i, int j);
void	findperson(t_vars *vars);
void	freefunc(char **map);
void	checkmap(char **map, int len, int height);
void	checkmemb(char **map);
void	checker(char **map, int i, int j);
void	exitstatus(char **map, char c);
int		main(int argc, char **argv);
void	putnbr(int key);

#endif
