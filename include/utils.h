/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:07:56 by octoross          #+#    #+#             */
/*   Updated: 2024/04/25 21:02:25 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# define ERR_MALLOC "Error : malloc failed\n"
# define ERR_SAME "Error : value is not unique : %d\n"
# define ERR_INT "Error : %s is not an int\n"
# define ERR_NO_ARG "Error : no value given\n"

# define PRINT_ERRORS 0

# define TINY_NBR_CHUNKS 2
# define SMALL_NBR_CHUNKS 3
# define MEDIUM_NBR_CHUNKS 11
# define BIG_NBR_CHUNKS 20

# include <stdlib.h>

typedef struct s_valid_int
{
	int	n;
	int	is_valid;
	int order;
}	t_valid_int;

int		ft_nbr_digits(unsigned long nbr);
int		ft_isspace(char c);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char *sep);
void	ft_free_until(void **tab, int start, int end);

#endif