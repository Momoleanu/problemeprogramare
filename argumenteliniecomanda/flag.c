#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
void *xmalloc(size_t nrOcteti);
 
int main(int argc, char *argv[])
{
    int flagM = 0, flagP = 0, flagS = 0, flagH = 0, flagI = 0, flagFIN = 0, flagFOUT = 0;
    char *denFIN, *denFOUT;
    FILE *fin, *fout;
    int i;
 
    printf("\nLinia de comanda contine %d argumente: ", argc);
    for (i = 0; i < argc; ++i)
    {
        printf("%s ", argv[i]);
    }
    printf("\n Identificarea procesarilor in linia de comanda: ");
    switch (argc)
    {
    case 1:
        flagM = 1;
        fin = stdin;
        fout = stdout;
        break;
 
    case 2:
        if (argv[1][0] == '-')
        {
            if (strlen(argv[1]) == 2)
            {
                switch (argv[1][1])
                {
                case 'm':
                    flagM = 1;
                    break;
                case 'p':
                    flagP = 1;
                    break;
                case 's':
                    flagS = 1;
                    break;
                case 'h':
                    flagH = 1;
                    break;
                default:
                    flagI = 1;
                    break;
                }
            }
            else
            {
                flagI = 1;
            }
        }
        else
        {
            flagM = 1;
            flagFIN = 1;
            fout = stdout;
            denFIN = (char *)xmalloc(strlen(argv[1] + 1));
            strcpy(denFIN, argv[1]);
        }
        break;
 
    case 3:
        if (argv[1][0] == '-')
        {
            if (strlen(argv[1]) == 2)
            {
 
                switch (argv[1][1])
                {
                case 'm':
                    flagM = 1;
                    break;
                case 'p':
                    flagP = 1;
                    break;
                case 's':
                    flagS = 1;
                    break;
                case 'h':
                    flagH = 1;
                    break;
                default:
                    flagI = 1;
                    break;
                }
                if (!flagI)
                {
                    if (argv[2][0] == '-')
                    {
                        flagI = 1;
                    }
 
                    else
                    {
                        flagFIN = 1;
                        flagFOUT = 0;
                        denFIN = (char *)xmalloc(strlen(argv[1]) + 1);
                        strcpy(denFIN, argv[1]);
                    }
                }
            }
            else
                flagI = 1;
        }
        else
        {
            if (argv[2][0] == '-')
            {
                flagI = 1;
            }
            else
            {
                flagFIN = 1;
                flagFOUT = 1;
                denFIN = (char *)xmalloc(strlen(argv[1]) + 1);
                strcpy(denFIN, argv[1]);
                denFOUT = (char *)xmalloc(strlen(argv[2]) + 1);
                strcpy(denFOUT, argv[1]);
            }
        }
        break;
 
    case 4:
        if (argv[1][0] == '-')
        {
            if (strlen(argv[1]) == 2)
            {
                switch (argv[1][1])
                {
                case 'm':
                    flagM = 1;
                    break;
                case 'p':
                    flagP = 1;
                    break;
                case 's':
                    flagS = 1;
                    break;
                case 'h':
                    flagH = 1;
                    break;
                default:
                    flagI = 1;
                    break;
                }
                if (!flagI)
                {
                    if (argv[2][0] == '-' || argv[3][0] == '-')
                    {
                        flagI = 1;
                    }
                    else
                    {
                        flagFIN = 1;
                        flagFOUT = 1;
                        denFIN = (char *)xmalloc(strlen(argv[2]) + 1);
                        strcpy(denFIN, argv[2]);
                        denFOUT = (char *)xmalloc(strlen(argv[3]) + 1);
                        strcpy(denFOUT, argv[3]);
                    }
                }
            }
            else
            {
                flagI = 1;
            }
        }
        else
        {
            flagI = 1;
        }
        break;
 
    default:
        flagI = 1;
        break;
    }
 
    if (flagI)
    {
        printf("\n Linie de comanda invalida! \n");
    }
    else
    {
        printf("\n Linie de comanda valida");
        if (flagFIN == 0)
        {
            fin = stdin;
            printf("\n Citire de la tastatura");
        }
        else
        {
            printf("\n Citire din fisierul %s", denFIN);
            fin = fopen(denFIN, "r");
            if (!fin)
            {
                fprintf(stderr, "Eroare la deschiderea fisierului! ");
                exit(0);
            }
        }
        if (!flagFOUT)
        {
            fout = stdout;
            printf("\n Afisare pe monitor");
        }
        else
        {
            printf("\n Afisare in fisierul %s", denFOUT);
            fout = fopen(denFOUT, "w");
            if (!fout)
            {
                fprintf(stderr, "Eroare la deschiderea fisierului! ");
                exit(0);
            }
        }
 
        if (flagH)
        {
            printf("\n Optiunea H");
        }
 
        if (flagS)
        {
            printf("\n Optiunea S");
        }
 
        if (flagP)
        {
            printf("\n Optiunea P");
        }
 
        if (flagM)
        {
            printf("\n Optiunea M");
        }
        if (flagI)
        {
            printf("\n Optiunea I");
        }
        puts("");
 
        fclose(fin);
        fin = 0;
        fclose(fout);
        fout = 0;
        fin = 0;
        fout = 0;
        puts("");
    }
    return 0;
}
 
void *xmalloc(size_t nrOcteti)
{
    void *p = 0;
    p = malloc(nrOcteti);
    if (!p)
    {
        fprintf(stderr, "Alocare de memorie esuata!\n ");
        exit(0);
    }
 
    return p;
}
