// Assignment name  : fizzbuzz
// Expected files   : fizzbuzz.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that prints the numbers from 1 to 100, each separated by a
// newline.

// If the number is a multiple of 3, it prints 'fizz' instead.

// If the number is a multiple of 5, it prints 'buzz' instead.

// If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

// Example:

// $>./fizzbuzz
// 1
// 2
// fizz
// 4
// buzz
// fizz
// 7
// 8
// fizz
// buzz
// 11
// fizz
// 13
// 14
// fizzbuzz
// [...]
// 97
// 98
// fizz
// buzz
// $>

배수에 따라 피즈버즈 뽑기 프로그램이며 각각의 결과값은 개행문자로 이어짐

#include <unistd.h>

void    from10(int number) //재귀 쓰는거라 능지로 실수할 수 있어서 다시 외우는 과정 필수..
{
    char str[10] = "0123456789";
    if (number > 9)
        from10(number / 10);
    write(1, &str[number % 10], 1);
}

int main(void)
{
    int i;
    i = 1;
    while (i <= 100)
    {
        if (i % 15 == 0)
        {
            write (1, "fizzbuzz", 8);
        }
        else if (i % 3 == 0)
        {
            write(1, "fizz", 4);
        }
        else if (1 % 5 == 0)
        {
            write(1, "buzz", 4);
        }
        else
            from10(i);
        i++;
        write(1, "\n", 1);
    }
    return (0);
}