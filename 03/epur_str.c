// Assignment name  : epur_str
// Expected files   : epur_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string, and displays this string with exactly one
// space between words, with no spaces or tabs either at the beginning or the end,
// followed by a \n.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// If the number of arguments is not 1, or if there are no words to display, the
// program displays \n.

// Example:

// $> ./epur_str "See? It's easy to print the same thing" | cat -e
// See? It's easy to print the same thing$
// $> ./epur_str " this        time it      will     be    more complex  . " | cat -e
// this time it will be more complex .$
// $> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
// $
// $> ./epur_str "" | cat -e
// $
// $>

// 스트링 하나를 받아서 단어 사이에 스페이스 하나만 존재하도록 한다 / 첫 시작이나 끝에 스페이스나 탭 없어야 함 / 개행으로 마무리
// 단어는 스페이스나 탭 혹은 스트링의 시작과 끝으로 분리되어 있는 스트링의 일부이다

#include <unistd.h>

int main(int ac, char const *argv[])
{
    int i = 0;
    int first_word = 1; // 첫 단어를 구분하기 위한 플래그

    if (ac == 2)
    {
        // 공백과 탭을 넘어 첫 번째 단어 찾기
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        
        while (argv[1][i])
        {
            // 현재 문자가 공백이 아닌 경우
            if (argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                // 첫 단어가 아니라면 단어 사이에 공백 출력
                if (!first_word)
                    write(1, " ", 1);
                
                // 단어 출력
                while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
                {
                    write(1, &argv[1][i], 1);
                    i++;
                }
                first_word = 0; // 첫 단어 처리 후 플래그 끔
            }
            else
            {
                // 단어 사이의 공백을 넘기기
                while (argv[1][i] == ' ' || argv[1][i] == '\t')
                    i++;
            }
        }
    }
    write(1, "\n", 1); // 마지막에 개행 출력
    return (0);
}
