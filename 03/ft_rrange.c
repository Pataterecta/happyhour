// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int *ft_rrange(int start, int end)
{
	int i = 0;
	int len = ft_abs(end - start) + 1;
	int *res = (int *)malloc(sizeof(int) * len);
	
    if(!res)
        return (NULL);

	while (i < len)
	{
        res[i] = end;
        if (end > start)
            end--;
        else
            end++;
        i++;
    }
        return (res); // 동적으로 할당된 배열 반환
}

int *ft_rrange(int start, int end);

int main(void)
{
    int *rrange;
    int i;
    int start = -2;
    int end = 3;
    int len = ft_abs(end - start) + 1;

    rrange = ft_rrange(start, end);
    
    // 배열 출력
    for (i = 0; i < len; i++)
    {
        printf("%d ", rrange[i]);
    }
    printf("\n");

    free(rrange);  // 동적 메모리 해제
    return 0;
}