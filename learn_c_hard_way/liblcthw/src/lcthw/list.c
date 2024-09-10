#include <stdio.h>
#include "dbg.h"
#include "list.h"

list *list_creat()
{
        //返回指针
        return calloc(1, sizeof(list));
}

void list_destroy(list *elist)
{
        LIST_FOREACH(elist, first, next, cur) {
                if(cur->prev) free(cur);
        }
        free(elist->last);
        free(elist);
}


//return-int; parameter-list *, void *;
void list_push(list *elist, void *value)
{
        //creat note &分配空间
        listnote *note = calloc(1, sizeof(listnote)); 
        check_mem(note);

        note->value = value;
        //调整指针
        if(elist->first == NULL && elist->last == NULL) {
                elist->first = note;
                elist->note = note;
        }
        else {
                elist->last->next = note;
                note->prev = elist->next;
                elist->last = note;
        }
        elist->count++;

error:
        return;
}

//return-list *; para-list *;
void *list_pop(list *elist)
{
        //便于操作，创建指针，指向操作note
        listnote *note = elist->last;
        //返回弹出note
        return note ? list_remove(elist, note) : NULL;
}

void list_unshift(list *elist, void *value)
{
        listnote *note =  calloc(1, sizeof(listnote));
        check_mem(note);

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
        elist->count++;

error:
        return; //注意，此处无论是否错误均会执行
}

void *list_shift(list* elist)
{
        listnote *note = elist->first;
        return note ? list_remove(elist, note) : NULL;
}

//remove函数通过节点地址删除节点
//return-void *; para-list *, listnote *;
listnote* list_remove(list *elist, listnote *note)
{
        check(elist->first && elist->last, "elist is empt");
        check(note, "note is not exest");
        void *result = NULL;
        if(note == elist->first && note == elist->last) {
                elist->first = NULL;
                elist->last = NULL;
        } else if(note == elist->first) {
                //elist->first指向新的节点，检查指向是否为空
                elist->first = note->next;
                check(elist->first != NULL, "elist get first is empt");
                elist->first->prev = NULL;
        } else if(note->next == NULL) {
                elist->last = note->prev;
                check(elist->last != NULL, "elist get lastis empt");
                elist->last->next = NULL;
        } else {
                listnote *before = note->prev;
                listnote *after = note->next;
                before->next = after;
                after->prev = before;
        }
        elist->count--;
        result = note->value;
        free(note);

error:
        return result;
}




