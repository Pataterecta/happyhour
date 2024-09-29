// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);

//        The strdup() function returns a pointer to a new string which is  a
//        duplicate  of  the string s.  Memory for the new string is obtained
//        with malloc(3), and can be freed with free(3).
// s 를 복사할 새 스트링 사이즈 위해 말록 필수 / 리턴 값은 포인터

#include <stdlib.h> // malloc
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char    *ft_strdup(char *src)
{
    int i = 0;
    int len;
    char    *result;

    len = ft_strlen(src);
    result = malloc(sizeof(*result) * (len +1));
    // if (result == NULL)
    //      return (NULL); 그 다음에 바로 while 해도 됨
    if (result != NULL) // NULL 체크 메모리 할당 실패 시 말록이 반환하는 것은 포인터의 NULL 값이기 때문
    {
        while (src[i] != '\0')
        {
            result[i] = src[i];
            i++;
        }
        result[i] = '\0';
    }
    return (result);
}

int main(void)
{
    char    *string = "abcde";
    printf("%s\n", ft_strdup(string)); // 프리 안해줬음 변수 선언해서 해줄만 함
    return (0);
}