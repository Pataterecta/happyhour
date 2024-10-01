// Assignment name  : is_power_of_2
// Expected files   : is_power_of_2.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that determines if a given number is a power of 2.

// This function returns 1 if the given number is a power of 2, otherwise it returns 0.

// Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);

// 2의 거듭제곱인지 2 4 8 16... 확인하는 함수 작성하기 거듭제곱이면 1 반환 아니면 0 반환

#include <stdio.h>

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    return (n & (n - 1)) == 0; // 비트 AND 연산자, 두 숫자의 이진수 표현에서 같은 위치의 비트들이 모두 1일때만 그 위치에서 1을 반환
}
int main(void)
{
    unsigned int    n = 16;
    if (is_power_of_2(n))
        printf("%u is power of 2 \n", n);
    else
        printf("%u is NOT power of 2", n);
    return (0);
}