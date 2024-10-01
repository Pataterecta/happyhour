// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

#include <unistd.h>

void    last_word(char *str)
{
    int i = 0;
    int start = -1;
    int end = -1;

    // 문자열 끝까지 탐색
    while (str[i])
    {
        // 문자가 공백이나 탭이 아닐 때 단어 시작 지점 기록
        if ((str[i] != ' ' && str[i] != '\t') && (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t'))
            start = i;

        // 단어의 끝 지점을 업데이트 (공백이나 탭이 아닌 문자가 있으면)
        if (str[i] != ' ' && str[i] != '\t')
            end = i;
        i++;
    }

    // 유효한 마지막 단어가 있는지 확인 후 출력 해당 체크 안하면 공백만 있는 인풋에 대한 결과값 이상하게 나옴
    if (start != -1 && end != -1)
    {
        while (start <= end)
        {
            write(1, &str[start], 1);
            start++;
        }
    }
}

int main(int ac, char **argv)
{
    if (ac == 2)
        last_word(argv[1]);
    write(1, "\n", 1); // 개행
    return (0);
}