// Assignment name  : rev_print
// Expected files   : rev_print.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a string, and displays the string in reverse
// followed by a newline.

// The original string must not be modified.

// You must return the string passed as a parameter.

// Your function must be declared as follows:

// char *rev_print(char *str);

// Examples:

// int main(void)
// {
//   rev_print("Hello world");
//   write (1, "\n", 1);
//   rev_print("tnirp esreveR");
//   write (1, "\n", 1);
//   rev_print("");
//   write (1, "\n", 1);
// }

// Output :
// $> ./a.out | cat -e
// dlrow olleH$
// $> ./a.out | cat -e
// Reverse print$
// $> ./a.out | cat -e
// $

#include <unistd.h>

int ft_strlen(char *str)
{
  int i = 0;
  while(str[i])
    i++;
  return (i);
}

char  *rev_print(char *str)
{
    int i = 0;
    int len = ft_strlen(str);

    while (len > 0)
    {
        len--;
        write(1, &str[len], 1);
    }
    return (str);
}

int main(void)
{
  rev_print("Hello world");
  write (1, "\n", 1);
  rev_print("tnirp esreveR");
  write (1, "\n", 1);
  rev_print("");
  write (1, "\n", 1);
}