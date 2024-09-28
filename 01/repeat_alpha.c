// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>

// ac 가 2가 아니면 개행만 / 인자 내의 글자를 알파벳 인덱스 만큼 반복

#include <unistd.h>

int get_num(char c)
{
    int z;

    if (c >= 'a' && c <= 'z')
        return (c - 'a' + 1); //인덱스 계산 char int 덜 익숙해하니까 다시 체크 필수..
    if (c >= 'A' && c <= 'Z')
        return (c - 'A' + 1);
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;
    int num;

    if (ac != 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    while (av[1][i] != '\0')
    {
        if ((av[1][i] >= 'a' && av[1][i] <= 'z') || (av[1][i] >= 'A' && av[1][i] <= 'Z'))
        {
            num = get_num(av[1][i]);
            while (num > 0)
            {
                write(1, &av[1][i], 1);
                num--;
            }
        }
        else
        {
            write(1, &av[1][i], 1);
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}