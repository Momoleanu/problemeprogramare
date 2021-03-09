header.h

#ifndef _header_h_
#define _header_h_

typedef struct _COMPLEX{
	double re,im;
}COMPLEX;

void* xmalloc(size_t nrOcteti);
void Citire(COMPLEX*a);
void Afisare(COMPLEX*a);
COMPLEX* Aduna(COMPLEX* a, COMPLEX* b);
COMPLEX* Inmulteste(COMPLEX* a, COMPLEX* b);
COMPLEX* Conjugat(COMPLEX* a);
double Modul(COMPLEX* a);
double Argument(COMPLEX* a);

void citireSir(COMPLEX *v, int n);
void afisareSir(COMPLEX *v, int n);
void afisareVDouble(double *v, int n);
COMPLEX* sumaElementeSir(COMPLEX* v, int n);
COMPLEX* raportSume(COMPLEX* v, int n);
double* sirModule(COMPLEX* v, int n);
double* sirArgumente(COMPLEX* v, int n);


#endif

////////////



functii.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

void* xmalloc(size_t nrOcteti)
{
	void* p=0;
	p=malloc(nrOcteti);
	if(!p)
	{
		fprintf(stderr,"Memorie insuficienta!");
		exit(EXIT_FAILURE);
	}
	return p;
}

void Citire(COMPLEX* a)
{
	printf("\n Re(a)=");
	scanf("%lf",&a->re);

	printf("\n Im(a)=");
	scanf("%lf",&a->im);
}

void Afisare(COMPLEX* a)
{
	printf("\n%.2lf + %.2lf", a->re, a->im);
}

COMPLEX* Aduna(COMPLEX* a, COMPLEX* b)
{
	COMPLEX* r;
	r=(COMPLEX*)xmalloc(sizeof(COMPLEX));
	r->re = a->re + b->re;
	r->im = a->im + b->im;
	return r;
}

COMPLEX* Inmulteste(COMPLEX* a, COMPLEX* b)
{
	COMPLEX* r;
	r=(COMPLEX*)xmalloc(sizeof(COMPLEX));
	r->re = a->re * b->re - a->im * b->im;
	r->im = a->re * b->im - a->im * b->re;
	return r;
}

COMPLEX* Conjugat(COMPLEX* a)
{
	COMPLEX* r;
	r=(COMPLEX*)xmalloc(sizeof(COMPLEX));
	r->re = a->re;
	r->im = -a->im;
	return r;
}

double Modul (COMPLEX* a)
{
	double m;
	m=sqrt(a->re * a->re + a->im * a->im);
	return m;
}

void citireSir(COMPLEX* v, int n)
{
	int i;
	for(i=0; i<n; i++)
	Citire(&v[i]);
}

void afisareSir(COMPLEX* v, int n)
{
	int i;
	for(i=0; i<n; i++)
	Afisare(&v[i]);
}

COMPLEX* sumaElementeSir(COMPLEX* v, int n)
{
	COMPLEX* s=0;
	s=(COMPLEX*)xmalloc(sizeof(COMPLEX));
	s->re=0;
	s->im=0;
	int i;
	for(i=0; i<=n-1; i++)
	{
		s=Aduna(s,&v[i]);
	}
	return s;
}

COMPLEX* raportSume(COMPLEX* v, int n)
{
	COMPLEX *si=0, *sp=0, *r=0;
	COMPLEX a1;
	
	si=(COMPLEX*)xmalloc(sizeof(COMPLEX));
	sp=(COMPLEX*)xmalloc(sizeof(COMPLEX));
	si->re=0; si->im=0;
	sp->re=0; sp->im=0;
	r=(COMPLEX*)xmalloc(sizeof(COMPLEX));
	int i;
	for(i=0; i<n; i++)
	{
		if(i%2==0)
		{
			sp=Aduna(sp,&v[i]);
		}
		else
		{
			si=Aduna(si,&v[i]);
		}
	}
	a1.re=1.0/(Modul(sp)*Modul(sp));
	a1.im=0;

	r=Inmulteste(Inmulteste(&a1,si),Conjugat(sp));

	return r;
}

double* sirModule(COMPLEX* v, int n)
{
	double* m=0;
	m=(double*)xmalloc(n*sizeof(double));

	int i;
	for(i=0; i<n; i++)
	{
		m[i]=Modul(&v[i]);
	}
	return m;
	}

double Argument(COMPLEX* a)
{
	double arg;
	arg=atan((a->im)/(a->re));
	return arg;
}

double* sirArgumente(COMPLEX* v, int n)
{
	int i;
	double* t=0;
	t=(double*)xmalloc(n*sizeof(double));
	for(i=0; i<n; i++)
	{
		t[i]=Argument(&v[i]);
	}
	return t;
}

void afisareVDouble(double* v, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("\n %.2lf ", v[i]);
	}	
}

///////


main.c


#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
	COMPLEX *v, *suma, *raport;
	double *module, *argumente;
	int n;

	printf("\n n=");
	scanf("%d", &n);

	v=(COMPLEX*)xmalloc(n*sizeof(COMPLEX));

	citireSir(v,n);
	afisareSir(v,n);

	suma=sumaElementeSir(v,n);
	printf("\nSuma elementelor sirului de numere complexe este:\n");
	Afisare(suma);

	raport=raportSume(v,n);
	printf("\nRaportul celor doua sume este:\n");
	Afisare(raport);

	module=sirModule(v,n);
	printf("\nSirul modulelor elementelor este:\n");
	afisareVDouble(module, n);

	argumente=sirArgumente(v,n);
	printf("\nSirul argumentelor elementelor este:\n");
	afisareVDouble(argumente,n);

	if(v)
	free(v);
	v=0;

	return 0;
}
