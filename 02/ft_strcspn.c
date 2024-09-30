// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);

// reject 내에 없는 글자들로만 이뤄진 스트링 내 범위 길이 뽑기

#include <stdio.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0')
    {
        j = 0; // initialize 해줘야지 각각의 reject 에 해당하는지 확인 가능~
        while (reject[j] != '\0')
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

int main(void)
{
    const char *s = "abcdefghi";
    const char *reject = "12345f";
    int i;
    i = ft_strcspn(s, reject);
    printf("%d\n", i);
    return (0);
}