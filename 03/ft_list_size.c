// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c, ft_list.h
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that returns the number of elements in the linked list that's
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure, and turn it in as a file called
// ft_list.h:

// typedef struct    s_list
// {
//     struct s_list *next; // 다음 노드를 가리키는 포인터
//     void          *data; // 노드에 저장된 데이터 void * 는 어떤 타입의 데이터든 저장할 수 있음을 의미함
// }                 t_list;

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int size = 0;

    while (begin_list != 0)
    {
        size++;
        begin_list = begin_list->next;
    }
    return (size);
}