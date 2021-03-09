Header.h
#ifndef _header_h_
#define _header_h_

double **aloca2d(int nrL, int nrC);
void dealoca2d(double **a);
double **citire(int n);
void afisareMatrice(double **a, int n);
double *sumaL(double **a, int n);
double max(double *v, int n);
double **transpusa(double **a, int n);
double normaInf(double **a, int n);
double norma1(double **a, int n);
double normaF(double **a, int n);
int meniu(void);

#endif

///////////


Functii.c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include”header.h”

double **aloca2d(int nrL, int nrC)
{
    double **a = 0;
    int i;
    a = (double **)malloc(nrL * sizeof(double *));
    if (a == 0)
    {
        fprintf(stderr, "Alocare esuata\n");
        exit(EXIT_FAILURE);
    }
    *(a + 0) = (double *)malloc(nrL * nrC * sizeof(double));
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
void dealoca2d(double **a)
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
double **citire(int n)
{
    double **b = 0;
    int i, j;
    b = aloca2d(n, n);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("m[%d][%d]=", i, j);
            scanf("%lf", *(b + i) + j);
        }
    }
    return b;
}
void afisareMatrice(double **a, int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            printf("%.2lf ", *(*(a + i) + j));
        }
        puts("");
    }
}
double *sumaL(double **a, int n)
{
    double *s = 0;
    int i, j;
    s = (double *)malloc(n * sizeof(double));
    if (!s)
    {
        fprintf(stderr, "Alocare esuata\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; ++i)
    {
        s[i] = 0;
        for (j = 0; j < n; ++j)
        {
            s[i] += abs(a[i][j]);
        }
    }
    return s;
}
double max(double *v, int n)
{
    double m;
    m = v[0];
    int i;
    for (i = 1; i < n; ++i)
    {
        if (v[i] > m)
        {
            m = v[i];
        }
    }
    return m;
}
double **transpusa(double **a, int n)
{
    double **at = 0;
    int i, j;
    at = aloca2d(n, n);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            at[i][j] = a[j][i];
        }
    }
    return at;
}
double normaInf(double **a, int n)
{
    double *v = sumaL(a, n);
    return max(v, n);
}
double norma1(double **a, int n)
{
    double **at = 0, *v = 0;
    at = transpusa(a, n);
    v = sumaL(at, n);
    return max(v, n);
}
double normaF(double **a, int n)
{
    int i, j;
    double s = 0;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            s += a[i][j] * a[i][j];
        }
    }
    s = sqrt(s);
    return s;
}
int meniu(void)
{
    int opt;
    do
    {
        printf("\n Meniu: \n\t 1 - Norma infinit \n\t 2 - Norma 1 \n\t 3 - Norma F \n\t 0 - Iesire \noptiunea = ");
        scanf("%d", &opt);
    } while (opt < 0 || opt > 3);
    return opt;
}


///////////

Main.c

int main(void)
{
    double **a = 0;
    int n, rel, opt;
    rel = 1;
    while (rel)
    {
        printf("Introduceti dimensiunea matricei:\nn=");
        scanf("%d", &n);
        a = citire(n);
        puts("Matricea este:");
        afisareMatrice(a, n);
        opt = meniu();
        switch (opt)
        {
        case 0:
            break;
        case 1:
        {
            printf("Noma infinit este %.2lf.\n", normaInf(a, n));
        }
        break;
        case 2:
        {
            printf("Noma 1 este %.2lf.\n", norma1(a, n));
        }
        break;
        case 3:
        {
            printf("Noma F este %.2lf.\n", normaF(a, n));
        }
        break;
        }
        printf("\n [0 - iesire, 1 -reluare]\t rel =");
        scanf("%d", &rel);
    }
    dealoca2d(a);
    return 0;
}
