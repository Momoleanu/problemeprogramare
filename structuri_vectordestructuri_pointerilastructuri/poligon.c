header.h

#ifndef _header_h_
#define _header_h_

typedef struct _PUNCT {
	double x,y;
}PUNCT;

void *xmalloc(size_t nrOcteti);
PUNCT *citirePoligon(int n);
void afisarePoligon(PUNCT* v, int n);
double distanta(PUNCT p1, PUNCT p2);
double semiperimetru(double a, double b, double c);
double arieTriunghi(PUNCT p1, PUNCT p2, PUNCT p3);
double ariePoligon (PUNCT *v, int n);
double perimetruPoligon(PUNCT*v, int n);

#endif

////////////

functii.c

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "header.h"

void* xmalloc(size_t nrOcteti)
{
	void *p=0;
	p=malloc(nrOcteti);
	if(!p)
	{
		fprintf(stderr, "Memorie insuficienta!");
		exit(EXIT_FAILURE);
	}
	return p;
}

PUNCT* citirePoligon(int n)
{
	int i;
	PUNCT* v;
	v=(PUNCT*)xmalloc(n*sizeof(PUNCT));
	for(i=0;i<n;i++)
	{
		scanf("%lf %lf", &v[i].x, &v[i].y);
	}
	return v;
	
}

void afisarePoligon(PUNCT* v, int n)
{
	int i;
	for(i=0;i<n;i++)
	
		printf("%c(%2.lf, %2.lf), \t", 'A'+i, v[i].x,v[i].y);
		
	printf("%c(%2.lf, %2.lf), \t", 'A'+i, v[i].x,v[i].y);
}
double distanta(PUNCT p1, PUNCT p2)
{
	double d;
	d=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	return d;
}

double semiperimetru(double a, double b, double c)
{
	double rez=0;
	rez=(a+b+c)/2.0;
	return rez;
}
double arieTriunghi(PUNCT p1, PUNCT p2, PUNCT p3)
{
	double rez,p,d1,d2,d3;
	d1=distanta(p1,p2);
	d2=distanta(p2,p3);
	d3=distanta(p1,p3);
	p=semiperimetru(d1,d2,d3);
	rez=sqrt(p*(p-d1)*(p-d2)*(p-d3));
	return rez;
}

double ariePoligon(PUNCT* v, int n)
{
	int i;
	double rez=0;
	for(i=0;i<=n-3;i++)
	{
		rez=rez+arieTriunghi(v[0],v[i+1],v[i+2]);
	}
	return rez;
}

double perimetruPoligon(PUNCT*v, int n)
{
	double rez=0;
	int i;
	for(i=0;i<=n-2;i++)
	{
		rez=rez+distanta(v[i], v[i+1]);
	}
	rez=rez+distanta(v[n-1], v[0]);
	return rez;
}

	
	//////////
  
main.c
	#include<stdio.h>
#include"header.h"

int main(void)
{
	int n;
	PUNCT* v;
	
	scanf("%d", &n);
	
	double arie, perimetru;
	
	v=citirePoligon(n);
	afisarePoligon(v,n);
	
	arie=ariePoligon(v,n);
	perimetru=perimetruPoligon(v,n);
	
	printf("\nPerimetrul poligonului este: %.3lf.", perimetru);
	printf("\nAria poligonului este: %.3lf", arie);
	
	return 0;
}
