// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);

// 주어진 문자열 str 을 str_base(진수)로 해석하여 10진수 정수값으로 변환하는 것
// 최대 16진법으로 주어진 숫자 문자열을 받아서 
// 101이 문자열로 주어지고 str_base 가 2인 경우 문자열은 2진수로 해석되어 10진수로는 5가 됨
// 지원되는 문자는 0123456789abcdef / 0123456789ABCDEF 대소문자 구분 없이 숫자로 처리함
// '-' 기호는 음수를 나타내기에 해석해야 함
// 4진수의 경우 0123 만 문자로 인식함

int	ft_is_valid(char c, int base)
{
    if (base <= 10)
        return (c >= '0' && c < '0' + base); // base에 따라 숫자만 유효 / true (1) false (0)
    return ((c >= '0' && c <= '9') || (c >= 'a' && c < 'a' + base - 10) || (c >= 'A' && c < 'A' + base - 10));
}

int	ft_value_of(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0'); // 숫자를 해당 값으로 변환
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10); // 소문자 변환
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10); // 대문자 변환
    return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    // 잘못된 base 입력에 대한 처리
    if (str_base < 2 || str_base > 16)
        return (0);

    // 공백 무시
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    
    // 부호 처리
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    // 문자열을 숫자로 변환
    while (str[i] && ft_is_valid(str[i], str_base))
    {
        result = result * str_base + ft_value_of(str[i]);
        i++;
    }

    return (result * sign);
}

#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_atoi_base("101", 2));       // 2진수: 출력 5
    printf("%d\n", ft_atoi_base("-1A", 16));      // 16진수: 출력 -26
    printf("%d\n", ft_atoi_base("123", 10));      // 10진수: 출력 123
    printf("%d\n", ft_atoi_base("7B", 16));       // 16진수: 출력 123
    return 0;
}