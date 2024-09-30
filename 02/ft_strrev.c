// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);

#include <stdio.h>

char    *ft_strrev(char *str)
{
    int len = 0;
    int i = 0;
    char    temp;

    while (str[len])
    {
        len++;
    }

    while (i < len / 2)
    {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
        i++;
    }
    return (str);
}

int main(void)
{
    // char    *str = "hello world"; 잘못된 것임 상수 데이터로 저장되기에 수정시 세그폴트, 문자열 리터럴은 읽기 전용임 직접 수정하면 안됨 배열은 수정 가능한 메모리에 할당
    char    str[] = "hello world";
    printf("%s\n",ft_strrev(str));
    return (0);
}