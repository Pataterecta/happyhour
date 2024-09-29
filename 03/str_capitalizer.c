// Assignment name  : str_capitalizer
// Expected files   : str_capitalizer.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes one or several strings and, for each argument,
// capitalizes the first character of each word (If it's a letter, obviously),
// puts the rest in lowercase, and displays the result on the standard output,
// followed by a \n.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string. If a word only has one letter, it must be
// capitalized.

// If there are no arguments, the progam must display \n.

// Example:

// $> ./str_capitalizer | cat -e
// $
// $> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
// A First Little Test$
// $> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
// __second Test A Little Bit   Moar Complex$
//    But... This Is Not That Complex$
//      Okay, This Is The Last 1239809147801 But Not    The Least    T$
// $>

// 첫 알파벳과 스페이스,\t 이후의 첫 글자가 알파벳인 경우 대문자화, 첫 글자가 아닌 대문자들 소문자화, 첫 글자가 _ 같이 알파벳이 아닌 경우 이후에 오는 알파벳 _S은 _s로 소문자화
// argv 갯수 제한 없으며 하나마다 개행문자 따라옴

#include <unistd.h>

void  str_capitalizer(char *str)
{
  int i = 0;

  // while(str[i] == ' ' || str[i] == '\t') // 첫 공백문자 처리
  // {
  //   write(1, &str[i], 1); // 아토이 생각하면서 스킵하는 이상한 착각 말고 인쇄하는거임
  //   i++;
  // } // 불필요함 뒤의 것과 겹침..
  if (str[i] >= 'a' && str[i] <= 'z') // 첫 공백 이후의 소문자니 바로 대문자화
  {
    str[i] = str[i] - 32;
  }
  write(1, &str[i], 1); // 바로 인쇄 후 i++;
  i++;

  while (str[i])
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
    if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t')) // 공백문자 뒤에 오는 소문자는 바로 대문자화
      str[i] = str[i] - 32;
    write(1, &str[i], 1); // else의 경우 포함(아무 문자)하여 인쇄
    i++;
  } 
}

int main(int  ac, char  **argv)
{
  int i;

  if(ac < 2)
  {
    write(1, "\n", 1);
    return (0);
  }
  else
  {
      i = 1;
      while (i < ac)
      {
        str_capitalizer(argv[i]);
        write(1, "\n", 1);
        i++;
      }
  }
  return (0);
}