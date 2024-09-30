// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>

// prime number = 소수 / 양수 int 를 받아서 int >= 인 모든 소수들 더한 값 뽑기 / 소수 = 1과 자기 자신만을 약수로 가지는 수 2도 소수임~
// 프로그램이 따로 음수의 경우 처리할 필요x

#include <unistd.h>

int ft_atoi(char *s) // 스트링을 인트로
{
    int res = 0;

    while (*s)
        res = res * 10 + (*s++ - 48); // 먼저 *s 값 이용하고 그 후에 증가시키기
    return (res);
}

int is_prime(int num) // 소수 판독기
{
    int i = 2;

    if (num <= 1)
        return (0);
    while (i * i <= num)
    {
        if (num % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void    put_nbr(int n)
{
    char    digit;
    if (n >= 10)
        put_nbr(n / 10);
    digit = n % 10 + '0';
    write (1, &digit, 1);
}

int main(int ac, char **argv)
{
    int nbr;
    int sum = 0; // sum 값이 0으로 초기화 되어 있어서 조건문 들어가지 않을 시 0이 출력됨

    if (ac != 2)
    {
        put_nbr(0);
        write(1, "\n", 1);
        return (0);
    }

    if (ac == 2)
    {
        nbr = ft_atoi(argv[1]); // 아토이는 스트링 받으니까
        
        while (nbr > 0)
        {
            if (is_prime(nbr)) // 함수가 1을 반환 할 때 내부 코드 실행
                sum += nbr;
            nbr--;
        }
        put_nbr(sum);
    }
    write(1, "\n", 1);
    return (0);
}