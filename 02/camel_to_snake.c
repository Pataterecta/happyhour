// <!-- Assignment name  : camel_to_snake
// Expected files   : camel_to_snake.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in lowerCamelCase format
// and converts it into a string in snake_case format.

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

// A snake_case string is a string where each word is in lower case, separated by
// an underscore "_".

// Examples:
// $>./camel_to_snake "hereIsACamelCaseWord"
// here_is_a_camel_case_word
// $>./camel_to_snake "helloWorld" | cat -e
// hello_world$
// $>./camel_to_snake | cat -e
// $ -->

// 대문자 발견시에 _ 먼저 쓰고 소문자로 변환 그 외의 경우는 그냥 인쇄로 치면 되고 인풋 관리xxx

#include <unistd.h>

int main(int ac, char **argv)
{
    int i = 0;

    if (ac != 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    if (ac == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                argv[1][i] = argv[1][i] + 32;
                write (1, "_", 1);
            }
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}