// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <stdlib.h>
#include <stdio.h>


int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int *ft_range(int start, int end)
{
	int i = 0;
	int len = ft_abs(end - start) + 1;
	int *res = (int *)malloc(sizeof(int) * len);
	
    if(!res)
        return (NULL);

	while (i < len)
	{
		if (start < end) // start 가 end 보다 작으면 오름차순으로 배열을 채움
		{
			res[i] = start;
			start++;
			i++;
		}
		else // start 가 end 보다 크면 내림차순으로 배열을 채움
		{
			res[i] = start;
			start--;
			i++;
		}
	}
        return (res); // 동적으로 할당된 배열 반환
}

int *ft_range(int start, int end);

int main(void)
{
    int *range;
    int i;
    int start = -2;
    int end = 3;
    int len = ft_abs(end - start) + 1;

    range = ft_range(start, end);
    
    // 배열 출력
    for (i = 0; i < len; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");

    free(range);  // 동적 메모리 해제
    return 0;
}