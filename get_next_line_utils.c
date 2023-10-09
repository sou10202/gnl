#include "get_next_line.h"

int ft_strlen(const char *str)
{
	if (*str == '\0')
		return (0);
	return (ft_strlen(str + 1) + 1);
}

char	*ft_strdup(const char *src)
{
	char	*des;
	int		len;
	char	*tmp;

	len = ft_strlen(src);
	des = malloc(sizeof(char) * (len + 1));
	if (des == NULL || src == NULL)
		return (NULL);
	tmp = des;
	while (*src != '\0')
	{
		*des = *src;
		des++;
		src++;
	}
	*des = '\0';
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ans;
	if (s == NULL)
		return (NULL);
	ans = (char *)s;
	while (*ans != '\0')
	{
		if (*ans == c)
			return (ans);
		ans++;
	}
	if (c == '\0')
		return (ans);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	char	*tmp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (ft_strdup((char *)s1));
	if (s1 == NULL)
		return (ft_strdup((char *)s2));
	ans = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ans == NULL)
		return (NULL);
	tmp = ans;
	while (*s1 != '\0')
	{
		*ans = *s1;
		ans++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*ans = *s2;
		ans++;
		s2++;
	}
	*ans = '\0';
	return (tmp);
}



// int	main(void)
// {
// 	char	*ans = ft_strjoin(NULL, "aaabbb");
// 	printf("%s", ans);
// 	free(ans);
// }