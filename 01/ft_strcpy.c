// Assignment name  : ft_strcpy
// Expected files   : ft_strcpy.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcpy (man strcpy).

// Your function must be declared as follows:

// char    *ft_strcpy(char *s1, char *s2);

// src 를 null 까지 카피하여 dest 에 넣는다 dest 는 src 를 받을 만큼 커야함 
// prototype : char * strcpy(char *dest, const char *src);

#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i;
    i = 0;

    while (s2[i]) //s2[i] != '\0'
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);    //man 에서는 리턴 값 언급이 정확히 없지만 strncpy 의 예시로 드러내고 있음 dest 보내야 함
}

int main(void)
{
    char    dest[] = "a, b, c, d, e";
    char    src[] = "x, y, z";
    ft_strcpy(dest, src);
    printf("%s\n", dest);   //프린트 시에는 x, y, z 가 뽑힘 왜냐면 이후는 null이라서 문자열의 일부로 인식되지 않음
}