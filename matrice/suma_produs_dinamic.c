#ifndef _header_h_
#define _header_h

void *xmalloc(size_t nrOcteti);
void citireM2(int **a, int nl, int nc);
void afisareM3(int **a, int nl, int nc);
int **aloca2d(int nl, int nc);
void dealoca2d(int **a, int nl);
int **sumaMDinamic(int **a, int **b, int nl, int nc);
int **produsMDinamic(int **a, int **b, int nl1, int nc1, int nl2);


#endif


/////

Functii.c

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include”header.h”


void *xmalloc(size_t nrOcteti)
{
    void *p = 0;
    p = malloc(nrOcteti);
    if (!p)
    {
        fprintf(stderr, "Alocare de memorie esuata!");
        exit(0); // exit(EXIT_FAILURE);
    }
    return p;
}

void citireM2(int **a, int nl, int nc)
{
    int i, j;
    for (i = 0; i < nl; i++)
        for (j = 0; j < nc; j++)
        {
            printf("\n a[%d][%d]= ", i, j);
            scanf("%d", &a[i][j]);
        }
}

void afisareM3(int **a, int nl, int nc)
{
    int i, j;
    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc; j++)
            printf("%d ", a[i][j]);
        puts("");
    }
}

int **aloca2d(int nl, int nc)
{
    int **a = 0;
    int i;
    a = (int **)xmalloc(nl * sizeof(int *));
    for (i = 0; i < nl; i++)
        a[i] = (int *)xmalloc(nc * sizeof(int));
    return a;
}
void dealoca2d(int **a, int nl)
{
    int i;
    for (i = 0; i < nl; i++)
    {
        if (a[i])
            free(a[i]);
        a[i] = 0;
    }
    if (a)
        free(a);
    a = 0;
}

int **citireM3(int nl, int nc)
{
    int i, j;
    int **a = 0;
    a = aloca2d(nl, nc);
    for (i = 0; i < nl; i++)
        for (j = 0; j < nc; j++)
        {
            printf("\n a[%d][%d]= ", i, j);
            scanf("%d", &a[i][j]);
        }
    return a;
}

int **sumaMDinamic(int **a, int **b, int nl, int nc)
{
    int **s = 0;
    int i, j;
    s = aloca2d(nl, nc);
    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc; j++)
        {
            s[i][j] = a[i][j] + b[i][j];
        }
    }
    return s;
}

int **produsMDinamic(int **a, int **b, int nl1, int nc1, int nl2)
{
    int **p = 0;
    int i, j, k;
    p = aloca2d(nl1, nc1);
    for (i = 0; i < nl1; i++)
        for (j = 0; j < nc1; j++)
        {
            p[i][j] = 0;
            for (k = 0; k < nl2; k++)
            {
                p[i][j] += a[i][k] * b[k][j];
            }
        }
    return p;
}

////

Main.c

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include”header.h”


int main(void)
{
    int **a, nl1, nc1;
    int **b, nl2, nc2;
    int **s;
    int **p;

    printf("\n nl1= ");
    scanf("%d", &nl1);
    printf("\n nl1= ");
    scanf("%d", &nc1);
    printf("\n nl2= ");
    scanf("%d", &nl2);
    printf("\n nc2= ");
    scanf("%d", &nc2);
    printf("Dati prima matrice:\n");
    a = aloca2d(nl1, nc1);
    citireM2(a, nl1, nc1);
    printf("Prima matrice este:\n ");
    afisareM3(a, nl1, nc1);
    printf("Dati a doua matrice: \n");
    b = aloca2d(nl1, nc2);
    citireM2(b, nl2, nc2);
    printf("A doua matrice este:\n ");
    afisareM3(b, nl2, nc2);

    puts("");

    if (nl1 == nl2 && nc2 == nc1)
    {
        printf("Matricea suma este: \n");
        s = sumaMDinamic(a, b, nl1, nc1);
        afisareM3(s, nl1, nc1);
        puts("");
        dealoca2d(s, nl1);
    }
    else
    {
        printf("Nu se poate calcula suma !");
    }

    if (nc1 == nl2)
    {
        printf("Matricea produs este:\n ");
        p = produsMDinamic(a, b, nl1, nc1, nl2);
        afisareM3(p, nc1, nl2);
        dealoca2d(p, nl1);
    }
    else
    {
        printf("Nu se poate calcula produsul !");
    }

    printf("\n\n");

    dealoca2d(a, nl1);
    dealoca2d(b, nl2);
     return 0;
}
