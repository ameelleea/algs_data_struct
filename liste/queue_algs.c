#include <stdio.h>
#include <stdlib.h>

typedef struct queuet
{
    int n;
    struct queuet *succ;
} queuet;

int enqueue(queuet **, queuet **, int);
int dequeue(queuet **, queuet **);

int main(void)
{
    queuet *front, *rear;
    int value;
    
    front = rear = NULL;
    return(0);
}

int enqueue(queuet **rear, queuet **front, int value)
{
    queuet *new_el;

    new_el = (queuet *)malloc(sizeof(queuet));
    new_el->n = value;
    new_el->succ = NULL;

    if (*rear != NULL)
    {
        *rear->succ = new_el;
    }
    else
    {
        *rear = *front = new_el;
    }
}

int dequeue(queuet **rear, queuet **front)
{   
    queuet *remove;
    
    if(*front != NULL)
    {
        remove = *front;
        *front = front->succ;
        if (*front == NULL)
           *rear = NULL;

        free(remove);
    }
}
