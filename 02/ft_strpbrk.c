// Assignment name	: ft_strpbrk
// Expected files	: ft_strpbrk.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strpbrk
// (man strpbrk).

// The function should be prototyped as follows:

// char	*ft_strpbrk(const char *s1, const char *s2);

// s에 accept 에 해당되는 문자와 일치하는 첫번째 문자를 가리키는 포인터 반환

#include <stdio.h>

char    *ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] && s2[j])
    {
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return ((char *)&s1[i]); // 리턴값이 const 가 아니라서 char로 만드는 과정 포인터 리턴해야 하기에 주소화
            j++;
        }
        j = 0; // 글자 각각을 보기 위해 initialized
        i++;
    }
    return (NULL);
}

int main(void)
{
    const char  *s = "zabcdef";
    const char  *accept = "12345a";
    const char  *res;
    
    res = ft_strpbrk(s, accept);
    if (res != NULL)
        printf("Matched : %s\n", res); // res 는 포인터니까 이거 앞에 주소 안달아도 됨..
    else
        printf("no match return value NULL\n"); 
// 해당 함수 프린트 되는 값은 abcdef 임 a 의 위치를 가르키는 포인터를 이용하여서 그 뒤로 쭉 인쇄
    return (0);
}