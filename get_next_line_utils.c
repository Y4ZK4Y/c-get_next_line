/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 13:27:51 by ykarimi       #+#    #+#                 */
/*   Updated: 2023/12/18 10:45:46 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char			*string;
	unsigned char	value;

	string = (char *)s;
	value = c;
	while (*string != value && *string != '\0')
		string++;
	if (*string == value)
		return (string);
	else
		return (NULL);
}
