// Assignment name  : max
// Expected files   : max.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// int		max(int* tab, unsigned int len);

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.

// len 에는 array 에 몇개의 element 가 있는지 나타내며 array 에서 찾은 가장 큰 숫자를 리턴한다

#include <stdio.h>

int max(int *tab, unsigned int len)
{
    int result;
    unsigned int    i = 0;

    if (len == 0)
        return (0);
    result = tab[i];

    while(i < len)
    {
        if (result < tab[i])
            result = tab[i]; // array 의 요소들 순차적으로 크기 비교하여 result 업데이트
        i++;    
    }
    return (result);
}
int main(void)
{
    int tab[] = {1, 2, 3, 4, 6, 7}; // 배열 선언 및 초기화 방법 숙지 필수!!!!!!!
    unsigned int len = 6;

    printf("%d\n", max(tab, len));
    
    return (0);
}