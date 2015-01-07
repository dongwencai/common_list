#include "list.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct list_head list;
}data_queue_t;

static data_queue_t *generate_data()
{
    data_queue_t *new_node;
    new_node = (data_queue_t *)malloc(sizeof(data_queue_t));
    if(new_node)
    {
        new_node->data = rand() % 100;
        new_node->list.next = new_node->list.prev = &new_node->list;
    }
    return new_node;
}
int main()
{
    data_queue_t *new_node;
    int i;
    data_queue_t *pos;
    struct list_head *link;
    LIST_HEAD(data_head);
    new_node = generate_data(); 
    list_add(&new_node->list,&data_head);
    for(i = 0 ; i < 20; i++)
    {
        new_node = generate_data(); 
        list_for_each_entry(pos,&data_head,list)
        {
            if(new_node->data > pos->data)
            {
                list_add_tail(&new_node->list,&pos->list);
                break;
            }
        }
       if (pos->list.next == data_head.next)  
        {
            list_add_tail(&new_node->list,&pos->list);
        }
    }
        list_for_each_entry_reverse(pos,&data_head,list)
        {
            printf("%d\n",pos->data);
        }
}
