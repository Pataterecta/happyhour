// Assignment name  : ft_strcmp
// Expected files   : ft_strcmp.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcmp (man strcmp).

// Your function must be declared as follows:

// int    ft_strcmp(char *s1, char *s2);

// strcmp 만들기 / 리턴값 : 두개의 밸류가 같으면 0 s1이 s2 보다 작으면 마이너스 s1이 s2보다 크면 플러스
// 스트링이기에 서로 다른 문자값이 나온 시점에서 s1 - s2 비교하면 됨

#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (*s1 && *s2) // 둘 다 null인지 아닌지 체크 필요 하나가 길던 짧던 정확히 끝까지 비교 위해서
    {
        if (*s1 != *s2)
        {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int main(void)
{
    char    *str1 = "abc";
    char    *str2 = "abd";
    int res;

    res = ft_strcmp(str1, str2);

    printf("%d\n",res);
    return (0);
}