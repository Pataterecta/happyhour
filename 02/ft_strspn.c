// Assignment name	: ft_strspn
// Expected files	: ft_strspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the strspn function 
// (man strspn).

// The function should be prototyped as follows:

// size_t	ft_strspn(const char *s, const char *accept);

// accept 에 해당하는 글자들의 연속된 범위 길이 리턴

#include <stdio.h>

char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return ((char *) s);
        ++s;
    }
    return (0); // NULL 포인터로 간주됨 포인터가 가리키는 것이 없다, 찾는 문자가 없다
}

size_t  ft_strspn(const char *s, const char *accept)
{
    size_t  i = 0;
   
    while (s[i] != '\0')
    {
        if (ft_strchr(accept, s[i]) == 0)
            break; // break 걸릴시 루프 밖으로 나감
        ++i;
    }
    return (i);
}

int main(void)
{
    const char  *s = "abcdefg12345";
    const char  *accept = "abc";

    int i;

    i = ft_strspn(s, accept);

    printf("%d\n", i);
    return (0);
}