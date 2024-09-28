// Assignment name  : rotone
// Expected files   : rotone.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays it, replacing each of its
// letters by the next one in alphabetical order.

// 'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

// The output will be followed by a \n.

// If the number of arguments is not 1, the program displays \n.

// Example:

// $>./rotone "abc"
// bcd
// $>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
// Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
// $>./rotone "AkjhZ zLKIJz , 23y " | cat -e
// BlkiA aMLJKa , 23z $
// $>./rotone | cat -e
// $
// $>
// $>./rotone "" | cat -e
// $
// $>

// 다음 글자로 치환하기 / z Z 가 a A 가 되는 것 예외 처리하기 / 프로그램임
// ac av 라서 학교가서 작동 다시 확인하기

#include <unistd.h>

int main(int ac, char **argv)
{
    int i;
    i = 0;

    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[1][i] != '\0')
    {
        if (argv[1][i] == 'z')
        {
            argv[1][i] = 'a';
        }
        else if (argv[1][i] == 'Z')
        {
            argv[1][i] = 'A';
        }
        else if ((argv[1][i] >= 'a' && argv[1][i] <= 'y') || (argv[1][i] >= 'A' && argv[1][i] <= 'Y'))
        {
            argv[1][i] = argv[1][i] + 1;
        }
        write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}