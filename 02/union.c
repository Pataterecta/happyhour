// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

// 프로그램 작성 / 두개의 스트링에 존재하는 각각의 개별적인 문자들 중복 없이 출력

#include <unistd.h>

int main(int ac, char **argv)
{
    if (ac == 3)
    {
        unsigned char   seen[256] = {0};
        int i = 0;
        int j = 0;

        while (argv[1][i])
        {
            if (!seen[(unsigned char)argv[1][i]])
            {
                write(1, &argv[1][i], 1);
                seen[(unsigned char)argv[1][i]] = 1;
            }
            i++;
        }
        while (argv[2][j])
        {
            if (!seen[(unsigned char)argv[2][j]])
            {
                write(1, &argv[2][j], 1);
                seen[(unsigned char)argv[2][j]] = 1; // 아스키 값 위치에 1을 기록하는 것임
            }
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
// ./a.out "hapi" "abcpi" -> hapibc