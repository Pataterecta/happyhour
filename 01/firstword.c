// Assignment name  : first_word
// Expected files   : first_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its first word, followed by a
// newline.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or if there are no words, simply display
// a newline.

// Examples:

// $> ./first_word "FOR PONY" | cat -e
// FOR$
// $> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
// this$
// $> ./first_word "   " | cat -e
// $
// $> ./first_word "a" "b" | cat -e
// $
// $> ./first_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

만들 것은 프로그램임 argv 로 받은 애들 첫 단어만 뽑아야 함 마무리는 개행으로 / 공백 무시할 줄 알아야 함 / spaces 랑 탭 확인 / ac가 2가 아니면 개행만

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;

    if (argc != 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    while (argv[1][i] == ' ' || argv[1][i] == '\t')
    {    
        i++;
    }
    while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
    {
        write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}