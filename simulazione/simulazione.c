#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct coda_t
{
    int v;
    struct coda_t *next;
} coda_t;

int acquisisci_valore(void);
void genera_valori(int, coda_t **, coda_t **);
void inserisci_coda(int, coda_t **, coda_t **);
void stampa_lista(coda_t *, coda_t *);
int ricerca_estremi(char, coda_t *, coda_t *);

int main(void)
{
    int max, min, n;
    coda_t *ingresso, *uscita;

    ingresso = uscita = NULL;

    n = acquisisci_valore();
    
    genera_valori(n, &ingresso, &uscita);
    
    printf("\nValori generati: \n");
    stampa_lista(ingresso, uscita);

    min = ricerca_estremi('m', ingresso, uscita);
    max = ricerca_estremi('M', ingresso, uscita);

    printf("\nValore massimo generato: %d.\n", max);
    printf("\nValore minimo generato: %d.\n", min);

    return(0);
}

int acquisisci_valore(void)
{
    int valore, acquisizione_err, esito_acquis;

    do
    {
        printf("Inserisci un numero intero:\n");
        esito_acquis = scanf("%d", &valore);

        acquisizione_err = esito_acquis != 1 || valore <= 0;

        if (acquisizione_err)
            printf("Valore non accettabile! Prego reinserirlo.\n");
        while (getchar() != '\n');
    } while (acquisizione_err);

    return(valore);
}

void genera_valori(int n, coda_t **ingresso, coda_t **uscita)
{
    int nuovo_n, i;

    srand(time(NULL));

    for (i=0; i < n; i++)
    {
        nuovo_n = rand() % (3*n);
        inserisci_coda(nuovo_n, ingresso, uscita);
    }
}

void inserisci_coda(int nuovo_n, coda_t **ingresso, coda_t **uscita)
{
    coda_t *nuovo_el;

    nuovo_el = (coda_t *)malloc(sizeof(coda_t));
    nuovo_el->v = nuovo_n;
    nuovo_el->next = NULL;

    if (*ingresso != NULL)
    {
        (*ingresso)->next = nuovo_el;
        *ingresso = nuovo_el;
    }
    else 
    {
        *ingresso = *uscita = nuovo_el;
    }
}

void stampa_lista(coda_t *ingresso, coda_t *uscita)
{
    coda_t *corr_p;
    
    for(corr_p = uscita; corr_p != NULL; corr_p = corr_p->next)
    {
        printf("%d ", corr_p->v);
    }

    putchar('\n');
}

int ricerca_estremi(char estremo, coda_t *ingresso, coda_t *uscita)
{
    int val_estremo;
    coda_t *corr_p, *prec_p;
    
    val_estremo = uscita->v;

    if (estremo == 'm')
    {
        for(corr_p = prec_p = uscita; corr_p != NULL; prec_p = corr_p, corr_p = corr_p->next)
        {
            if (corr_p->v < val_estremo)
                val_estremo = corr_p->v;
        }
    }
    else if (estremo == 'M')
    {
        for(corr_p = prec_p = uscita; corr_p != NULL; prec_p = corr_p, corr_p = corr_p->next)
        {
            if (corr_p->v > val_estremo)
                val_estremo = corr_p->v;
        }
    }

    return(val_estremo);
}