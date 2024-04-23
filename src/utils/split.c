/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:21:26 by octoross          #+#    #+#             */
/*   Updated: 2024/04/06 16:21:26 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_is_sep(char c, char *sep)
{
	while (*sep)
		if (c == *sep++)
			return (1);
	return (0);
}

void	ft_free_until(void **tab, int start, int end)
{
	int		i;
	char	**strs;

	if (start < 0 || !tab)
		return ;
	i = start;
	if (end < 0)
	{
		strs = (char **)tab;
		while (strs[i])
			free(strs[i ++]);
	}
	else 
	{
		while (i < end)
			free(tab[i++]);
	}
	free(tab);
}

int	ft_nbr_words(char const *s, char *sep)
{
	int	nbr_words;
	int	i;

	nbr_words = 0;
	i = 0;
	while (s[i] && ft_is_sep(s[i], sep))
		i ++;
	while (s[i])
	{
		nbr_words ++;
		while (s[i] && !ft_is_sep(s[i], sep))
			i ++;
		while (s[i] && ft_is_sep(s[i], sep))
			i ++;
	}
	return (nbr_words);
}

char	*ft_next_word(const char *s, int *i, char *sep)
{
	char	*word;
	int		len;

	len = 0;
	while (s[*i + len] && !ft_is_sep(s[*i + len], sep))
		len ++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	word[len] = '\0';
	len = 0;
	while (s[*i] && !ft_is_sep(s[*i], sep))
		word[len++] = s[(*i)++];
	while (s[*i] && ft_is_sep(s[*i], sep))
		(*i)++;
	return (word);
}

char	**ft_split(char const *s, char *sep)
{
	int		nbr_words;
	int		i;
	char	**splited;

	if (!s)
		return (0);
	nbr_words = ft_nbr_words(s, sep);
	splited = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!splited)
		return (0);
	splited[nbr_words] = 0;
	nbr_words = 0;
	i = 0;
	while (s[i] && ft_is_sep(s[i], sep))
			i ++;
	while (s[i])
	{
		splited[nbr_words] = ft_next_word(s, &i, sep);
		if (!splited[nbr_words])
			return (ft_free_until((void **)splited, 0, -1), NULL);
		nbr_words ++;
	}
	return (splited);
}
