#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct person{
        char *name;
        int age;
};

struct person *person_creat(char *name, int age)
{
        struct person *who = malloc(sizeof(struct person));
        assert(who != NULL);
        who->name = strdup(name);
        who->age = age;
}

int person_destroy(struct person *who)
{
        assert(who != NULL);
        free(who->name);
        free(who);
        return 0;
}

int person_printf(struct person *who)
{
        printf("name is %s\n", who->name);
        printf("age is %d\n", who->age);
        return 0;
}

int main(int argc, char *argv[])
{
        struct person *kaplan = person_creat("kaplan", 23);
        person_printf(kaplan);
        person_destroy(kaplan);
        return 0;
}
