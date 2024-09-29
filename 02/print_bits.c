// Assignment name  : print_bits
// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
// AT THE END.

// Your function must be declared as follows:

// void	print_bits(unsigned char octet);

// Example, if you pass 2 to print_bits, it will print "00000010"

//시프트란 비트를 한칸씩 지정 방향으로 이동 시키며 빈 자리는 0으로 채움

#include <unistd.h>

void    print_bits(unsigned char octet) // unsigned char 는 8비트 크기
{
    int i = 8;

    unsigned char bit;

    while(i--) // i 가 0이 될 때까지 반복 8은 조건 확인 뿐이고 7~0까지 함수 내 체크됨
    {
        bit = (octet >> i & 1) + '0'; // octet 값을 오른쪽으로 한자리씩 시프트 하여 해당 위치의 비트를 가져옴 & 1 연산으로 0인지 1인지 확인 후 숫자화
        write (1, &bit, 1);
    }
}

int main(void)
{
    unsigned char happy = 12;
    print_bits(happy);
    return (0);
}