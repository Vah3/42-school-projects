/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:55:00 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/18 15:31:28 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

# define ESC 53

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

# define LEFT_A 123
# define RIGHT_A 124

# define DIR_CHAR "NEWS" 
# define VALID_CHARS "10NEWS"

# define RED     		"\x1b[1;31m"
# define GREEN   		"\x1b[1;32m"
# define YELLOW  		"\x1b[1;33m"
# define BLUE    		"\x1b[1;34m"
# define MAGENTA 		"\x1b[1;35m"
# define CYAN    		"\x1b[1;36m"
# define COLOR_RESET   	"\x1b[0m"

typedef struct s_dir
{
	char	*path_to_xpm;

}	t_dir;

typedef struct s_directions
{
	t_dir	north;
	t_dir	south;
	t_dir	east;
	t_dir	west;

}	t_directions;

typedef struct s_colors
{
	int	red;
	int	green;
	int	blue;
}	t_colors;

typedef struct s_cf
{
	t_colors	ceil;
	t_colors	floor;

}	t_cf;

typedef struct s_player
{
	char		face_to;
	double		x;
	double		y;
}	t_player;

typedef struct s_game
{
	char			**file;
	t_directions	directions;
	t_cf			ceil_floor;
	t_player		player;	
	char			**map;
	int				size_of_map;

}	t_game;

/*			GET_FILE.C				*/
char	*tab_to_4space(char *content);
char	*final_line(char *content);
void	clear_list(t_list **list_map);
char	**list_to_array(t_list	*list_map);
char	**get_full_file(int fd);

/*			HELPERS.C				*/
void	free_after_split(char **store);
int		splited_size(char **words);
int		count_of_tabs(char *content);
int		extension_is_wrong(char *filename, char *extension);

/*			PARSE_UTILS_1.C			*/
int		is_cubes_side(char *name);
int		is_surface(char *name);
int		is_number(char *line);
int		there_is_comma_error(char *line);
int		is_empty_line(char *line);

/*			FLOOR_CEIL.C			*/
int		is_valid_color_codes(char *color_codes_line, int *error_code);
int		can_assign(t_game *game, char *key, int *err_code);
void	assign_rgb(t_game *game, char **info, int *count_of_information);

/*			DIRECTION_CHECKING.C	*/
int		is_empty_keys_value(t_game *game, char *key_name);
int		is_valid_path(t_game *game, char *path_to_xpm);
void	assign_direction(t_game *game, char **splited_info,
			int *count_of_information);
int		is_all_spaces(char *line);

/*			MAP_CHECKERS_1.C		*/
int		get_size_of_map(t_game *game, int *i);
void	get_map_from_file(t_game *game, int *i, int size_of_map);
int		there_is_empty_line_in_map(char **map, int size);
int		maps_up_and_down_is_not_correct(char **map, int size);
int		there_is_invalid_char(char **map);

/*			MAP_CHECKERS_2.C		*/
int		left_wall_is_not_correct(char **map);
int		right_wall_is_not_correct(char **map);
int		is_covered_by_space(char **map, int i, int j);
int		zero_is_not_covered(char **map);
int		count_of_directions(char **map);

/*			PARSE_UTILS_2.C			*/
void	set_direction(t_game *game);
void	skip_spaces_and_get_sizeof_map(t_game *game, int *i);

/*			parse_map.c			*/
int		validation_of_file(t_game	*game, char *filename, int argc);
void	ft_error(int error_code, t_game *game);
void	free_after_split(char **store);
void	clear_struct(t_game *game);

void	initialize_struct(t_game *game);

#endif