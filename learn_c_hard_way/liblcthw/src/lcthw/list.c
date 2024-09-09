#include <stdio.h>
#include "dbg.h"
#include "list.h"

list *list_creat()
{
        list *elist = calloc(1, sizeof(list));
        return elist;
}

void list_destroy(list *elist)
{
        
}

void list_clear(list *elist);

void list_clear_destroy(list *elist)
{
        list_clear(elist);
        list_destroy(elist);
}

void list_push(list *elist, void *value)
{
        listnote *note = calloc(1, sizeof(listnote)); 
        note->value = value;
        if(elist->first == NULL && elist->last == NULL) {
                elist->first = note;
                elist->note = note;
        }
        else {
                elist->last->next = note;
                note->prev = elist->next;
                elist->last = note;
        }
}

void *list_pop(list *elist)
{
        listnote *note = elist->last;
        return note ? list_remove(elist, note) : NULL;
}

void list_unshift(list *elist, void *value)
{
        listnote *note =  calloc(1, sizeof(listnote));
        note->value = value;
        if(elist->first == NULL && elist->last == NULL) {
                elist->first = note;
                elist->last = note;
        }
        else {
                elist->first->prev = note;
                note->next = elist->first;
                elist->first = note;
        }
}

void *list_shift(list* elist)
{
        listnote *note = elist->first;
        return note ? list_remove(elist, note) : NULL;
}

void list_remove(list *elist, listnote *note)
{
        
}
