// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:

// int	ft_atoi(const char *str);

// atoi 인데 몇가지 빠진 것 str을 int로 만든다(인풋은 글자로 적힌 숫자로 보면 됨), ascii ' ' 와 9~13 처리 \t, \n, \v, \f, \r

#include <stdio.h>

int ft_atoi(const char *str)
{
    int result = 0;
    int plusminus = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-')
        plusminus = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + *str - '0'; //차곡차곡 쌓아가기 한자리씩 왼쪽으로 밀어간다고 생각하면 됨
        str++;
    }
    return(plusminus * result);   
}

int main(void)
{
    const char *str1 = "    +-234568"; // 시험 내 함수는 연속된 부호 처리 필요x
    const char *str2 = "    -99999";
    int result;

    result = ft_atoi(str1);
    printf("%d\n", result);
    result = ft_atoi(str2);
    printf("%d\n", result);
    return (0);
}

