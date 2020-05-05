#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#include "dlistc.h"

int main(){
    printf("Lista doble\n\n");
    dlist *l;
    l = create_dlist();
    insert_dlist(l, 0, 0);
    insert_dlist(l, 2, 1);
    print_dlist(l);
    insert_dlist(l, 1, 1);
    insert_dlist(l, 3, 1);
    print_dlist(l);
    remove_pos(l, 1);
    print_dlist(l);
    remove_pos(l, 1);
    remove_pos(l, 1);
    print_dlist(l);
    remove_dlist(l);
    l = NULL;

    printf("Lista doble circular \n\n");
    dlistc *c;

    c=create_dlistc();
    insert_dlistc(c, 0, 0);
    insert_dlistc(c, 2, 1);
    print_dlistc(c);
    insert_dlistc(c, 1, 1);
    insert_dlistc(c, 3, 1);
    print_dlistc(c);
    remove_posc(c, 1);
    print_dlistc(c);
    remove_posc(c, 1);
    remove_posc(c, 1);
    print_dlistc(c);
    remove_dlistc(c);
    return 0;
}