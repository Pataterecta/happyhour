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
        write(1, str, 1); //글자 하나씩 읽을 거고 *str로 정의 되어 있었으니까 &이거 달 필요 없음
        str++;
    }
}

int main (void)
{
    char    str[] = "a,b,c,d,e,f,g";
    ft_putstr(str);
    return (0);
}