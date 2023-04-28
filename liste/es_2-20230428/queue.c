#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* dichiarazione strutture*/
typedef struct {
    int nr;
    char *st;
} dato_t;

typedef struct elem_lista {
    dato_t val;
    struct elem_lista *succ_p;
} elem_lista_t;

/* dichiarazione funzioni*/
void metti_in_coda (elem_lista_t **uscita_p, elem_lista_t **ingresso_p, dato_t valore);
void stampa_coda (elem_lista_t *uscita_p);
elem_lista_t* cerca_in_coda (elem_lista_t *uscita_p, int key);
char* genera_stringa_casuale (void);

/* programma main */
int main (int argc, char **argv) {
    int N, key, i;
    dato_t dato;
    elem_lista_t *uscita_p, *ingresso_p, *elem_p;
    
    uscita_p = ingresso_p = NULL;
    printf("N = ");
    scanf("%d",&N);
    printf("Generazione di N = %d numeri tra 0 e %d e di %d stringhe casuali associate\n",N,3*N,N);
    srand(1);/* Inizializzazione generatore numeri pseudocasuali*/
    
    for (i=0;i<N;i++){
        dato.nr = rand() % (3*N);
        dato.st = genera_stringa_casuale();
        printf("Dato generato: (%d,%s)\n", dato.nr, dato.st);
        metti_in_coda(&uscita_p,&ingresso_p, dato);
        printf("...e inserito in coda\n\n");
    }
    printf("Stampa del contenuto della coda...\n");
    stampa_coda(uscita_p);
    printf("\n");
    printf("key = ");
    scanf("%d",&key);
    elem_p = cerca_in_coda(uscita_p,key);
    if (elem_p!=NULL)
        printf("Trovato elemento (%d,%s)\n", elem_p->val.nr,elem_p->val.st);
    else
        printf("Elemento non trovato.\n");
    return(0);
}

                    
/* definizione funzioni */
void metti_in_coda(elem_lista_t **uscita_p,
                   elem_lista_t **ingresso_p,
                   dato_t valore) {
    
    elem_lista_t *nuovo_p;
    nuovo_p = (elem_lista_t *)malloc(sizeof(elem_lista_t));
    nuovo_p->val = valore;
    nuovo_p->succ_p = NULL;
    if (*ingresso_p != NULL)
        (*ingresso_p)->succ_p = nuovo_p;
    else
        *uscita_p = nuovo_p;
    *ingresso_p = nuovo_p;
}

char* genera_stringa_casuale (void) {
    int i, n;
    char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
    char* stringa;
    
    stringa = (char *)malloc(sizeof(6));
    for (i=0;i<5;i++){
        n = rand() % (26);
        stringa[i] = alfabeto[n];
    }
    stringa[6] = '\0';
    return(stringa);
}


void stampa_coda (elem_lista_t *uscita_p) {
    elem_lista_t *elem_p;
    int i;
    
    i = 1;
    for (elem_p = uscita_p; elem_p!=NULL; elem_p = elem_p->succ_p){
        printf("%d. (%d,%s)\n",i,elem_p->val.nr,elem_p->val.st);
        i++;
    }
}


elem_lista_t* cerca_in_coda (elem_lista_t *uscita_p, int key){
    elem_lista_t *elem_p;
    
    for (elem_p = uscita_p;((elem_p!=NULL)&&(elem_p->val.nr!=key));elem_p = elem_p->succ_p);
    return(elem_p);
}
