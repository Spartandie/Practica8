#include "dlistc.h"
#include<stdio.h>
#include <stdlib.h>
dlistc *create_dlistc()
{
    dlistc *l = (dlistc*)malloc(sizeof(dlistc));
    l->head = NULL;
    l->tail = NULL;
    l->num = 0;
    return l;
}
bool remove_dlistc(dlistc *l)
{
    if(!is_empty_dlistc(l))
        empty_dlistc(l);
    free(l);
    return true;
}

bool insert_initc(dlistc *l, DATA data)
{
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(is_empty_dlistc(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        l->num =1;
        l->head->next=nuevo;
        l->head->prev=nuevo;
        return true;
    }
    nuevo->next = l->head;
    l->head->prev = nuevo;
    l->tail->next=nuevo;
    nuevo->prev=l->tail;
    l->head=nuevo;
    l->num++;
    return true;
}
bool insert_endc(dlistc *l, DATA data)
{
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(is_empty_dlistc(l)){        
        l->head = nuevo;
        l->tail = nuevo;
        l->num =1;
        return true;
    }
    l->tail->next = nuevo;
    nuevo->prev = l->tail;
    nuevo->next=l->head;
    l->tail->prev=nuevo;
    l->tail = nuevo;
    l->num++;
    return true;
}
bool insert_dlistc(dlistc *l, DATA data, int pos)
{
    if(l == NULL) return false;
    dnode *nuevo = create_dnode(data);
    if(pos ==0) return insert_initc(l, data);
    else if(pos == l->num)
        return insert_endc(l,data);
    else if(pos >0 && pos< l->num-1 || pos==1 && l->num==2){
        dnode *t = l->head->next;
        for(int i =1; i < pos; i++){ // i = 1 Y pos = 1
            t= t->next;
        }
        dnode *prev = t->prev;    
        prev->next = nuevo;
        nuevo->next = t;
        nuevo->prev = prev;        
        t->prev = nuevo;
        l->num++;
        return true;
    }
    return false;
}

bool remove_initc(dlistc *l)
{
    if(l == NULL || is_empty_dlistc(l)) return false;
    if(l->head ==l->tail){
        remove_dnode(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    dnode *t = l->head->next;    
    t->prev = NULL;
    l->head->next= NULL;
    t->prev=l->tail;
    l->tail->next=t;
    remove_dnode(l->head);
    l->head = t;
    l->num--;
    return true;
}
bool remove_endc(dlistc *l)
{
    if(l == NULL || is_empty_dlistc(l)) return false;
    if(l->head ==l->tail){
        remove_dnode(l->head);
        l->head = l->tail = NULL;
        l->num = 0;
        return true;
    }
    dnode *t = l->tail->prev;
    t->next= NULL;
    l->tail->prev = NULL;
    t->next=l->head;
    l->head->prev=t;
    remove_dnode(l->tail);
    l->tail = t;
    l->num--;
    return true;
}
bool remove_posc(dlistc *l ,int pos)
{
    if(pos == 0){
        return remove_initc(l);
    }else if(pos == l->num-1){
        return remove_endc(l);
    }else if(pos>0 && pos < l->num-1 || pos==1 && l->num==2){
        dnode *t = l->head->next;
        for(int i =1; i < pos; i++){
            t= t->next;
        }
        dnode *prev = t->prev;    
        dnode *next = t->next;        
        prev->next = next;        
        next->prev = prev;
        t->next = NULL;
        t->prev = NULL;
        remove_dnode(t);
        l->num--;
        return true;
    }
    return false;
}

DATA search_dlistc(dlistc *l, int pos)
{
    if(pos == 0) return l->head->data;
    else if(pos == l->num-1) return l->tail->data;
    else if(pos >0 && pos < l->num-1){
        dnode *t = l->head->next;
        for(int i=1; i<l->num-2; i++){
            if(i==pos) return i;
            t = t->next;
        }
    }
    return -1;
}
int locate_dlistc(dlistc *l, DATA data)
{
    dnode *t = l->head;
    for(int i= 0; i < l->num-1; i++){
        if(t->data==data) return i;
        t = t->next;
    }
    return -1;
}

void print_dlistc(dlistc *l)
{
    printf("[");
    dnode *t;
    for(t=l->head;t->next!=l->head;t=t->next)
    {
        printf("%i, ", t->data);
    }
    printf("%i", t->data);
    printf("]\n");
}

bool is_empty_dlistc(dlistc *l)
{
    if(l->head == NULL && l->tail == NULL) return true;
    return false;
}
void empty_dlistc(dlistc *l){
    if(is_empty_dlistc(l)) return;
    dnode *t = l->head;
    while(remove_initc(l));
}

bool delete_datac(dlistc *l, DATA data)
{
    dnode *t = l->head;
    for(int i =0; i < l->num; i++){
        if(t->data == data){
            remove_posc(l, i);       
        }
    }
}
