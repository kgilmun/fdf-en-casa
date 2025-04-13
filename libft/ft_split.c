/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:58:03 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/01/05 16:19:20 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	freememory(char **arr, int n)
{
	while (n >= 0)
	{
		free(arr[n]);
		n--;
	}
	free(arr);
}

static int	countletters(const char *s, char c, int *i)
{
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (*i);
}

static char	**ft_storewords(const char *s, char c, char **arr)
{
	int	i;
	int	n;
	int	start;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			i = countletters(s, c, &i);
			arr[n] = ft_substr(s, start, i - start);
			if (!arr[n])
			{
				freememory(arr, n - 1);
				return (NULL);
			}
			n++;
		}
		else
			i++;
	}
	arr[n] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		numwords;
	char	**arr;

	if (!s)
		return (NULL);
	numwords = ft_countwords(s, c);
	arr = (char **)malloc((numwords + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_storewords(s, c, arr);
	return (arr);
}
