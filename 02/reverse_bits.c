// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0100  0001
//      ||
//      \/
//  1000  0010

// 바이트 8자리 이진법 숫자 반대로 만들기 리턴값은 변경된 바이트 그 자체 / 함수 

#include <stdio.h>

 unsigned char  reverse_bits(unsigned char octet)
 {
    int i = 0;
    unsigned char   result = 0;
    while(i < 8)
    {
        result = (result << 1) | (octet >> i & 1); //문자 숫자화 하는 과정 필요x '0'이거 고려x, result 는 왼쪽으로 밀어서 자리 한 칸 만들고 / octet 가장 오른쪽 비트 하나씩 따오고 result는 왼쪽으로 계속 밀리니까 역순으로 채워짐 & 1은 오른쪽 마지막 자리 1인지 0인지 확인
        i++;
    } 
    return (result);
 }

 int    main(void)
 {
    unsigned char   check;
    unsigned char   input = 12;
    check = reverse_bits(input);
    printf("%d\n", check); //십진법으로 출력됨, 이진법 출력용 함수는 따로 만들어야됨 필요시
    return (0);
 }