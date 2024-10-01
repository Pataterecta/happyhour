// Assignment name  : swap_bits
// Expected files   : swap_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, swaps its halves (like the example) and
// returns the result.

// Your function must be declared as follows:

// unsigned char	swap_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0100 | 0001
//      \ /
//      / \
//  0001 | 0100

// unsigned char 는 1바이트(8비트) 크기를 가짐, 0~255 까지의 값
// >> 비트들을 오른쪽으로 이동시키며 가장 오른쪽 비트는 버리고 빈자리는 0으로 채움
// << 비트들을 왼쪽으로 이동시키며 가장 왼쪽 비트는 버리고 빈자리는 0으로 채움
// | OR 두 비트 중 하나라도 1이면 결과가 1이 됨
// 상위 4비트와 하위 4비트를 교환하는 함수

#include <stdio.h>

unsigned char swap_bits(unsigned char octet)
{
  return ((octet >> 4) | (octet << 4));
}

int main(void)
{
    unsigned char   octet = 65; // 01000001
    unsigned char   result = swap_bits(octet);

    printf("Original byte : %d\n", octet);
    printf("Swapped byte : %d\n", result);

    return (0);
}