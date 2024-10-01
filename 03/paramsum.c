// Assignment name  : paramsum
// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays the number of arguments passed to it, followed by
// a newline.

// If there are no arguments, just display a 0 followed by a newline.

// Example:

// $>./paramsum 1 2 3 5 7 24
// 6
// $>./paramsum 6 12 24 | cat -e
// 3$
// $>./paramsum | cat -e
// 0$
// $>

// ac - 1 갯수 계산하여 해당 숫자를 출력하기 위해 ft_putnbr 를 필요로 하는 프로그램

#include <unistd.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n >= 10)
		ft_putnbr(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	(void)argv; // argv를 사용하지 않음을 명시

	ft_putnbr(argc - 1); // 전달된 인자의 개수를 출력, 프로그램 이름 제외한 인자 수
	write(1, "\n", 1);
	return (0);
}