// Assignment name  : snake_to_camel
// Expected files   : snake_to_camel.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in snake_case format
// and converts it into a string in lowerCamelCase format.

// A snake_case string is a string where each word is in lower case, separated by
// an underscore "_".

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

// Examples:
// $>./camel_to_snake "here_is_a_snake_case_word"
// hereIsASnakeCaseWord
// $>./camel_to_snake "hello_world" | cat -e
// helloWorld$
// $>./camel_to_snake | cat -e
// $

// _ 나올 시에 i++ 한 후에( _ 는 인쇄 안하기 위함) 해당 글자 대문자화 / 인풋 확인 필요 없음

#include <unistd.h>

int main(int ac, char **argv)
{
    int i = 0;

    if (ac == 2)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] == '_')
            {
                i++;
                argv[1][i] = argv[1][i] - 32;
            }
            write (1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}