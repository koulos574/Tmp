#include "ft_list.h"
#include <stdio.h>

t_list  *ft_create_elem(void *data)
{
    t_list *new_list;
    new_list = malloc(sizeof(t_list));
    if  (new_list)
    {
        new_list->data = data;
        new_list->next = NULL;
        return (new_list);
    }
    return (0);
}

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *new_list;

    if (*begin_list)
    {
        new_list = *begin_list;
        while (new_list->next != NULL)
            new_list = new_list->next;
        new_list->next = ft_create_elem(data);
    }
    else
        *begin_list = ft_create_elem(data);
}

void    ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new_list;
    t_list *tmp_list;

    tmp_list = NULL;
    if (*begin_list)
    {
        new_list = *begin_list;
        tmp_list = ft_create_elem(data);
        tmp_list->next = new_list;
        *begin_list = tmp_list;
    }
    else
        *begin_list = ft_create_elem(data);
}

int ft_list_size(t_list *begin_list)
{
    int i;

    i = 0;
    while (begin_list != NULL)
    {
        i++;
        begin_list = begin_list->next;
    }
    return (i);
}

t_list *ft_list_last(t_list *begin_list)
{
    while (begin_list->next != NULL)
        begin_list = begin_list->next;
    return (begin_list);
}

void crap_a_list(t_list* list)
{
	for (; list != 0; list = list->next)
		printf("%s,", (char*)list->data);
	printf("\n");
}

int     main(void)
{
    t_list* new_list;
    t_list* list = 0;

	ft_list_push_back(&list, "asdf");
	crap_a_list(list);
	ft_list_push_front(&list, "qwer");
	ft_list_push_back(&list, "zxcv");
	crap_a_list(list);
	list = 0;
	ft_list_push_back(&list, "uiop");
	ft_list_push_back(&list, "hjkl");
	crap_a_list(list);
    printf("%d\n", ft_list_size(list));
    new_list = ft_list_last(list);
    crap_a_list(new_list);
}