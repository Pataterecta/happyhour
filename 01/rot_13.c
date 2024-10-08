// Assignment name  : rot_13
// Expected files   : rot_13.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the letter 13 spaces ahead in alphabetical order.

// 'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

// The output will be followed by a newline.

// If the number of arguments is not 1, the program displays a newline.

// Example:

// $>./rot_13 "abc"
// nop
// $>./rot_13 "My horse is Amazing." | cat -e
// Zl ubefr vf Nznmvat.$
// $>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
// NxwuM mYXVWm , 23l $
// $>./rot_13 | cat -e
// $
// $>
// $>./rot_13 "" | cat -e
// $
// $>

// 인쇄 / 13먼저번 알파벳 인쇄 / a 등 낮은 숫자는 아스키 인덱스 기준x

#include <unistd.h>

int main(int ac, char **argv)
{
    int i = 0;

    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while(argv[1][i])
    {
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            argv[1][i] = (argv[1][i] - 'a' + 13) % 26 + 'a'; //자릿수 잡아내서 a기준으로 다시 문자화
        }
        else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            argv[1][i] = (argv[1][i] - 'A' + 13) % 26 + 'A';
        }
        write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}