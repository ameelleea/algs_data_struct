#include <stdio.h>
#include <stdlib.h>

/*Tipo di dato per alberi binari, ovvero ogni nodo ha max due figli*/
typedef struct treet 
{
    int n;
    struct treet *sx;
    struct treet *dx;
}

void anticipated_visit(treet **);
void simmetric_visit(treet **);
void postponed_visit(treet **);
int bst_search(treet **, int, treet **);
int bst_insert(treet **, int);
int bst_remove(treet **, int);

void anticipated_visit(treet **root)
{   
    if(*root != NULL)
    {
    printf("%d", *root->n);
    anticipated_visit(*root->sx);
    anticipated_visit(*root->dx);
    }
}

void simmetric_visit(treet **root)
{   
    if (*root != NULL)
    {
    simmetric_visit(*root->sx);
    printf("%d", *root->n);
    simmetric_visit(*root->dx);
    }
}

void postponed_visit(treet **)
{   
    if (*root != NULL)
    {
    postponed_visit(*root->sx);
    postponed_visit(*root->dx);
    printf("%d", *root->n);
    }
}

/*Modificabile a seconda delle esigenze, qui alloca l'indirizzo dell'elemento in elem se presente*/
/*Potrebbe anche solo restituire 1 o 0 per sapere se l'elemento c'è*/
int bst_search(treet **root, int value, treet **elem)
{
    treet *actual_n;
    int found;

    for (actual_n = *root; actual_n != NULL && actual_n-> != value;)
    {   
        actual_n = (actual_n->n < value)? 
                   actual_n->dx:
                   actual_n->sx;
    }

    if (actual_n == NULL)
    {
       printf("Absent value!");
       found = 0;
    }
    else
    {
       *elem = actual_n;
       found = 1;
    }

    return(found);
}

int bst_insert(treet **root, int value)
{
    treet *actual_n, *prev_n, *new_n;
    int outcome;

    for(actual_n = prev_n = *root; actual_n != NULL && actual_n->n != value;)
    {   
        prev_n = actual_n;
        actual_n = (actual_n->n < value)? 
                    actual_n->dx:
                    actual_n->sx;
    }

    if (actual_n != NULL)
    {
        printf("Value already present in tree.");
        outcome = 0;
    }
    else
    {
        new_n = (treet *)malloc(sizeof(treet));
        new_n->n = value;
        new_n->sx = new_n->dx = NULL;

        if (actual_n == *root)
           *root = new_n;
        else
        {
            if (prev_n->n < new_n->n)
               prev_n->dx = new_n;
            else 
               prev_n->sx = new_n;
        }

        outcome = 1;
    }

    return(outcome);
}

int bst_remove(treet **root, int value)
{
    treet *actual_n, *prev_n, *remove;
    int outcome;

    for (actual_n = prev_n = *root; actual_n != NULL && actual_n-> != value;)
    {   
        prev_n = actual_n;
        actual_n = (actual_n->n < value)? 
                   actual_n->dx:
                   actual_n->sx;
    }

    if (actual_n == NULL)
    {
        printf("Value already absent.");
        outcome = 0;
    }
    else
    {   
        remove = actual_n;

        if (remove->sx == NULL && remove->dx == NULL)  /*Nodo foglia (no figli)*/
           free(remove);
        else if (remove->sx != NULL && remove->dx == NULL) /*Nodo con figlio sinistro*/
        {   
            *actual_n = remove->sx;

            if (prev_n->n < actual_n->n)
               prev_n->dx = actual_n;
            else if (prev_n->n > actual_n->n)
               prev_n->sx = actual_n;

            free(remove);
        }
        else if (remove->sx == NULL && remove->dx != NULL) /*Nodo con figlio destro*/
        {   
            *actual_n = remove->dx;

            if (prev_n->n < actual_n->n)
               prev_n->dx = actual_n;
            else if (prev_n->n > actual_n->n)
               prev_n->sx = actual_n;
            
            free(remove);
        }
        else if (remove->sx != NULL && remove->dx != NULL) /*Nodo con due figli*/
        {   
            for(actual_n = prev_n = remove->sx; actual_n->dx != NULL; prev_n = actual_n, actual_n = actual_n->dx);
            
            /*Sostituisci il nodo da rimuovere con quello più a destra del sottoalbero sx*/
            remove = actual_n;
            prev_n->dx = actual_n->sx;

            free(actual_n);
        }

        outcome = 1;
    }

    return(outcome);
}