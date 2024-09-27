// Assignment name  : ft_putstr
// Expected files   : ft_putstr.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that displays a string on the standard output.

// The pointer passed to the function contains the address of the string's first
// character.

// Your function must be declared as follows:

// void	ft_putstr(char *str);

함수 만드는 문제, 스트링 주소 받아서 스트링 뽑기 메인은 테스트용

#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str != '\0') //스트링이니까 null 까지
    {
        write(1, str, 1); // str[i]로 함수 내 이용하는 경우는 &가 필요하다, write (1, &argv[1][i], 1) 과 비교 요망
        str++;
    }
}

void    ft_putstr2(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main (void)
{
    char    str[] = "a,b,c,d,e,f,g";
    ft_putstr(str);
    write (1, "\n", 1);
    ft_putstr2(str);
    return (0);
}