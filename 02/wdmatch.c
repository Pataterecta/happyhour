// Assignment name  : wdmatch
// Expected files   : wdmatch.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and checks whether it's possible to
// write the first string with characters from the second string, while respecting
// the order in which these characters appear in the second string.

// If it's possible, the program displays the string, followed by a \n, otherwise
// it simply displays a \n.

// If the number of arguments is not 2, the program displays a \n.

// Examples:

// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// faya$
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
// $
// $>./wdmatch "forty two" "qfqfsoudf arzgrsayns tsryegftdgs sjytwdekuooixq " | cat -e
// forty two$
// $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// $
// $>./wdmatch | cat -e
// $

// av1의 모든 글자를 순서대로 av2에서 찾을 수 있을 시 av1 그대로 출력 후 개행, 아닐 경우 개행

#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int main(int ac, char **argv)
{
    int i = 0;
    int j = 0;
    int len;

    if (ac != 3)
    {
        write(1, "\n", 1);
        return (0);
    }

    len = ft_strlen(argv[1]);
    while (argv[2][i])
    {
        if(argv[1][j] == argv[2][i])
        {
            j++; //찾은 경우 j++
        }
        i++; // 항상 i는 증가함
    }
    if (j = len)
    {
        write(1, argv[1], j); // 스트링 이렇게 인쇄 가능한 거 기억하기 j에는 len이 들어감 null 착각 xxx
    }
    write(1, "\n", 1);
    return (0);
}