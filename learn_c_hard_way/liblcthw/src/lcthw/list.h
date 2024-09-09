#ifndef LIST_H
#define LIST_H 

#include <stdio.h>
#include <stdlib.h>

struct listnote;

typedef struct listnote{
        struct listnote *prev;
        struct listnote *next;
        void *value;
}

typedef struct list{
        int count;
        listnote *first;
        listnote *last;
}

list *list_creat();

void list_destroy(list *elist);

void list_clear(list *elist);

void list_clear_destroy(list *elist);

void list_push(list *elist, void *value);

void list_pop(list *elist);

void list_unshift(list *elist);

void list_shift(list* elist);

void list_remove(list *elist, listnote *note);

#endif
