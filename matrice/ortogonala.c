#ifndef _header_h_
#define _header_h_

int **aloca2d(int nrL, int nrC);
void dealoca2d(int **a);
int **citireMatrice(int n);
void afisareMatrice(int **a, int n);
int **produsMatrice(int **a, int **b, int n);
int **transpusaMP(int **a, int n);
int comparaIn(int **a, int n);


#endif

/////////
Functii.c

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include”header.h”

int **aloca2d(int nrL, int nrC)
{
    int **a = 0, i;
    a = (int **)malloc(nrL * sizeof(int *));
    if (a == 0)
    {
        fprintf(stderr, "Alocare esuata\n");
        exit(EXIT_FAILURE);
    }
    *(a + 0) = (int *)malloc(nrL * nrC * sizeof(int));
    if ((a + 0) == 0)
    {
        fprintf(stderr, "Alocare esuata\n");
        exit(EXIT_FAILURE);
    }
    for (i = 1; i < nrL; ++i)
    {
        *(a + i) = *(a + i - 1) + nrC;
    }
    return a;
}
void dealoca2d(int **a)
{
    if (*(a + 0))
    {
        free(*(a + 0));
    }
    *(a + 0) = 0;
    if (a)
    {
        free(a);
    }
    a = 0;
}
int **citireMatrice(int n)
{
    int **b = 0, i, j;
    b = aloca2d(n, n);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("m[%d][%d]=", i, j);
            scanf("%d", *(b + i) + j);
        }
    }
    return b;
}
void afisareMatrice(int **a, int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%d ", *(*(a + i) + j));
        }
        puts("");
    }
}
int **produsMatrice(int **a, int **b, int n)
{
    int **p = 0, i, j, k;
    p = aloca2d(n, n);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            *(*(p + i) + j) = 0;
            for (k = 0; k < n; k++)
            {
                p[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return p;
}
int **transpusaMP(int **a, int n)
{
    int **at = 0, i, j;
    at = aloca2d(n, n);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            at[i][j]=a[j][i];
        }
    }
    return at;
}
int comparaIn(int **a, int n)
{
    int i, j, ok = 1;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if ((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0))
            {
                ok = 0;
                break;
            }
        }
    }
    return ok;
}

/////


Main.c

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include”header.h”

int main(void)
{
    int **a = 0, **at = 0, **aat = 0, n;
    printf("Introduceti dimensiunea matricei\nn=");
    scanf("%d", &n);
    a = citireMatrice(n);
    puts("Matricea este:");
    afisareMatrice(a, n);
    at = transpusaMP(a, n);
    puts("Transpusa este:");
    afisareMatrice(at, n);
    aat = produsMatrice(a, at, n);
    if (comparaIn(aat, n) == 1)
    {
        puts("Matricea A este ortogonala.");
    }
    else
    {
        puts("Matricea nu este ortogonala.");
    }
    dealoca2d(a);
    dealoca2d(at);
    dealoca2d(aat);
    return 0;
}
