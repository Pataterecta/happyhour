// Assignment name  : ft_strlen
// Expected files   : ft_strlen.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that returns the length of a string.

// Your function must be declared as follows:

// int	ft_strlen(char *str);

// 리턴 값 : 스트링 길이

#include <stdio.h>

int ft_strlen(char *str)
{
    int i;
    i = 0;

    while(str[i] != '\0')
    {
        i++;
    }   //strlen의 반환값은 null 문자를 포함하지 않는다 C 언어에서 문자열의 길이는 정의적으로 null 문자 제외한 개수
    return (i);
}

int main(void)
{
    int length;
    char    happystring[] = "abc"; //실제 문자 개수인 3 리턴하는지 확인

    length = ft_strlen(happystring);
    printf("%d\n", length);
    return (0);
}