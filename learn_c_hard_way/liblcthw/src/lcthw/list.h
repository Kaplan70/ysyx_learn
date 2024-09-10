#ifndef LIST_H
#define LIST_H 

#include <stdio.h>
#include <stdlib.h>

struct listnote;

typedef struct listnote{
        struct listnote *prev;
        struct listnote *next;
        void *value;
} listnote;

typedef struct list{
        int count;
        listnote *first;
        listnote *last;
} list;

list *list_creat();

void list_destroy(list *elist);

void list_push(list *elist, void *value);
void *list_pop(list *elist);

void list_unshift(list *elist);
void *list_shift(list* elist);

void *list_remove(list *elist, listnote *note);

#define LIST_FOREACH(L, F, N, C) listnote *_note = NULL;\
        listnote *C = NULL;\
        for(C = _note = L->F; _note != NULL; C = _note = C->N)

#endif
