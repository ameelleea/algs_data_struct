#include <stdio.h>
#include <stdlib.h>

typedef struct rbtree 
{
    int v;
    char color;
    struct rbtree *dad;
    struct rbtree *sx, *dx;
} rbtree;

void insert(rbtree *, int);
void remove(rbtree *);
void reset_tree(rbtree *, rbtree *);
void rotate(rbtree *, rbtree *, char);

int main(void)
{
    rbtree *sentinel;
    
    sentinel->value = 0;
    sentinel->dad = NULL;
    sentinel->color = 'b';
    sentinel->sx = sentinel->sx = NULL;

    return(0);
}

void insert(rbtree *sentinel, int v)
{
    rbtree *new, *prev, *curr;

    int outcome;

    for(prev = curr = *root; curr != NULL && curr->n != value;)
    {   
        prev = curr;
        curr = (curr->n < value)? 
                    curr->dx:
                    curr->sx;
    }

    if (curr != NULL)
    {
        printf("Value already present in tree.");
        outcome = 0;
    }
    else
    {
        new = (rbtree *)malloc(sizeof(rbtree));
        new->n = value;
        new->color = 'r';
        new->sx = new->dx = NULL;

        if (curr == sentinel)
        {
            new->dad = sentinel;
            sentinel->sx = sentinel->dx = new;
        }
        else
        {   
            new->dad = prev;

            if (prev->n < new->n)
               prev->dx = new;
            else 
               prev->sx = new;
        }
        
        reset_tree(sentinel, new);
        outcome = 1;
    }

    return(outcome);
}
void remove(rbtree *sentinel);

void reset_tree(rbtree *sentinel, rbtree *newnode)
{   
    rbtree *dad, *uncle, *granpa;

    if (newnode->dad == sentinel)
    {
        newnode->color = 'b';
    }
    else
    {
        dad = newnode->dad;
        granpa = dad->dad;

        if (granpa->sx == dad)
            uncle = granpa->dx;
        else
            uncle = granpa->sx;
        
        if (uncle->color == 'r')
        {
            dad->color = uncle->color = 'b';
            granpa->color = 'r';
            reset_tree(sentinel, granpa);
        }
        else
        {
            if (dad->dx == newnode)
            {
                rotate(dad, new, 's');
                new = dad;
                rotate(dad, granpa, 'd');
                dad->color = 'b'; 
                granpa->color = 'r';
            }
            else
            {
                rotate(dad, granpa, 'd');
                dad->color = 'b'; 
                granpa->color = 'r';
            }
        }
    }
}

void rotate(rbtree *x, rbtree *y, char dir)
{
    if (dir == 's')
    {
        x->dx = y->sx;
        y->sx = x;
        y->dad = x->dad;
        x->dad = y;
    }
    else if (dir == 'd')
    {
        y->sx = x->dx;
        x->dx = y;
        x->dad = y->dad;
        y->dad = x;
    }
}