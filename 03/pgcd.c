// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e
// 1$
// $> ./pgcd | cat -e
// $

// 최대 공약수 뽑는 프로그램 / 예시에선 atoi 와 printf 만 사용

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int nbr1;
    int nbr2;

    // 1. 두 개의 명령줄 인자가 제공된 경우에만 실행
    if (argc == 3)
    {
        // 2. 두 명령줄 인자를 정수로 변환하고, 두 수가 모두 양수인지 확인
        if ((nbr1 = atoi(argv[1])) > 0 && (nbr2 = atoi(argv[2])) > 0)
        {
            // 3. 유클리드 호제법 (빼기 연산 버전)을 사용하여 GCD 계산
            while (nbr1 != nbr2)
            {
                if (nbr1 > nbr2)
                    nbr1 -= nbr2;  // nbr1이 더 크면 nbr1에서 nbr2를 뺌
                else
                    nbr2 -= nbr1;  // nbr2가 더 크면 nbr2에서 nbr1을 뺌
            }
            // 4. GCD를 출력 (nbr1과 nbr2가 동일하면 그게 GCD)
            printf("%d", nbr1);
        }
    }

    // 5. 개행을 출력하고 프로그램 종료
    printf("\n");
    return (0);
}