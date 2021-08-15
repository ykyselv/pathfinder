#include "../inc/libmx.h"

t_list *mx_create_node (void *data) {

    if(data == NULL)
        return 0;
    else {
        t_list *tmp = (t_list *)malloc(sizeof(t_list));
        tmp->data = data;
        tmp->next = NULL;
        return tmp;
    }
}

// int main() {
//     char* data = "ksjldhfls";
//     t_list* list = mx_create_node((void*) data);
//     printf("%s\n", (char*)list->data);
// }
