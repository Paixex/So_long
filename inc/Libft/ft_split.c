/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:51:08 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:49:45 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_letter_count(char const *s, char c)
{
	size_t	k;

	k = 0;
	while (s[k] != '\0' && s[k] != c)
		k++;
	return (k);
}

static int	ft_word_count(char const *s, char c)
{
	int	k;
	int	onof;
	int	word;

	k = 0;
	onof = 1;
	word = 0;
	while (s[k] != '\0')
	{
		if (onof == 1 && s[k] != c)
		{
			word++;
			onof = 0;
		}
		else if (s[k] == c)
			onof = 1;
		k++;
	}
	return (word);
}

static char	*ft_stralloc(char **strs, char const *s, int *i, char c)
{
	int		k;
	char	*str;

	k = 0;
	str = (char *)malloc(sizeof(char) * (ft_letter_count(s + *i, c) + 1));
	if (!strs || !str)
		return (NULL);
	while (s[*i] != '\0' && s[*i] != c)
	{
		str[k] = s[*i];
		k++;
		(*i)++;
	}
	str[k] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		k;
	int		count;

	k = 0;
	count = 0;
	strs = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!strs)
		return (NULL);
	while (s[k] != '\0')
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		if (s[k] != '\0')
		{
			strs[count] = ft_stralloc(strs, s, &k, c);
			count++;
		}
	}
	strs[count] = 0;
	return (strs);
}
