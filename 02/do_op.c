// Assignment name  : do_op
// Expected files   : *.c, *.h
// Allowed functions: atoi, printf, write
// --------------------------------------------------------------------------------

// Write a program that takes three strings:
// - The first and the third one are representations of base-10 signed integers
//   that fit in an int.
// - The second one is an arithmetic operator chosen from: + - * / %

// The program must display the result of the requested arithmetic operation,
// followed by a newline. If the number of parameters is not 3, the program
// just displays a newline.

// You can assume the string have no mistakes or extraneous characters. Negative
// numbers, in input or output, will have one and only one leading '-'. The
// result of the operation fits in an int.

// Examples:

// $> ./do_op "123" "*" 456 | cat -e
// 56088$
// $> ./do_op "9828" "/" 234 | cat -e
// 42$
// $> ./do_op "1" "+" "-43" | cat -e
// -42$
// $> ./do_op | cat -e
// $

// 계산하는 프로그램을 만들어라 ac = 4 av 1 과 3을 부호 2 + - * / % 를 통한 연산하기 / av 1 과 3 은 -일 수 있음 / 모든 결과는 개행으로 끝냄
// printf atoi 사용 가능 av는 "" 없어도 계산 가능 / 부호 기준으로 if 분류

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **argv)
{
  if (ac != 4)
  {
    write(1, "\n", 1);
    return (0);
  }
  if (argv[2][0] == '+') // [2]가 아니라 [2][0] 인 거 잘 체크하기
    printf("%d\n", (atoi(argv[1]) + atoi(argv[3]))); // printf 내에서 계산 가능하고 변수 따로 필요x
  else if (argv[2][0] == '-')
    printf("%d\n", (atoi(argv[1]) - atoi(argv[3])));
  else if (argv[2][0] == '*')
    printf("%d\n", (atoi(argv[1]) * atoi(argv[3])));
  else if (argv[2][0] == '/')
    printf("%d\n", (atoi(argv[1]) / atoi(argv[3])));
  else if (argv[2][0] == '%')
    printf("%d\n", (atoi(argv[1]) % atoi(argv[3]))); // 개행문자 write로 따로 빼서 처리할시 아웃풋 이상하게 나옴 내부에 같이 처리
  return (0);
}