#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *fib;
    int steps;
    int n, i;

    /*Calcolo complessità computazionale del calcolo del n-esimo numero di Fibonacci*/

    printf("Quanti numeri di Fibonacci si vuole calcolare? ");
    scanf("%d", &n);
    putchar('\n');
    steps = 4; /*Le tre istruzioni precedenti + l'assegnamento di steps = 4*/

    fib = (int *)calloc(n, sizeof(int));
    steps++;

    for(fib[0] = fib[1] = 1, i = 1; i < n-1; i++, steps += 2) /*A ogni ciclo viene valutata la condizione e incrementati i e steps = +2 passi*/
    {
        fib[i+1] = fib[i] + fib[i-1];
        steps++;
    }

    steps++; /*Primo assegnamento del ciclo for*/

    for (i = 0; i < n; i++, steps += 2)
    {
        printf("%d ", fib[i]);
        steps++;
    } 
    putchar('\n');
    steps += 2; /*Putchar + primo assegnamento for loop*/

    printf("Il calcolo è avvenuto in %d passi.\n", steps);
}