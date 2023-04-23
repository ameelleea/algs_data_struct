#include <stdio.h>
#include <stdlib.h>

typedef struct stackt
{
    int n;
    struct stackt *succ;
} stackt;

void add_to_stack(stackt **, int);
void remove_from_stack(stackt **);

void add_to_stack(stackt **top, int value)
{
    stackt *new_el;

    new_el = (stackt *)malloc(sizeof(stackt));
    new_el->n = value;
    new_el->succ = *top;
    *top = new_el;

}

void remove_from_stack(stackt **top)
{
    stackt *remove;
    
    if (*top != NULL)
    {
        remove = *top;
        *top = *top->succ;
    }

    free(remove);
}