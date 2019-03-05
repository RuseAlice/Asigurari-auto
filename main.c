#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Header.h"
FILE *f, *h;

struct masina
{
    char marca[20];
    int an_fabr; /* anul fabricatiei */
    char tip;    /* tipul masinii: A-mica, B-medie, C-mare, D-foarte mare(camion, tir etc) */
    int accidente;
    char nr_inmatriculare[10];
    struct proprietar
    {
        char nume[50];
        int varsta;
        char adresa[100];
    } p[100];
    float pret;
    bool garantie; /* valabilitatea garantiei*/
};

typedef struct masina Masina;
Masina m[100];


enum stare_masina
{
    excelenta,
    buna,
    reparatii, /* necesita reparatii */
    proasta
};

union valabilitate  /*cati ani de gerantie mai are masina */
{
    int ani_ramasi;
    char expirata[2];

};


int comparare(const void *a, const void *b) /* comparam in functe de nr de accidente si in caz de egalitate, in odine alfabetica dupa marca */
{
    if (((struct masina *)a)->accidente==((struct masina *)b)->accidente)
        return strcmp(((struct masina *)a)->marca, ((struct masina *)b)->marca);

    if (((struct masina *)a)->accidente<((struct masina *)b)->accidente)
        return -1;
    return 1;
}

void citire11() /*citire/afisare din consola si metoda de memorare 1 */
{
    char steluta;
    int n, an_curent, t, k;
    printf("Introduceti anul curent: ");
    scanf("%d", &an_curent);
    printf("Cate masini doriti sa introduceti? ");
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++)
    {
        printf("Marca este: ");
        scanf("%c",&steluta);
        scanf("%s",m[i].marca);

        printf("Anul fabricatiei: ");
        scanf("%d", &m[i].an_fabr);

        printf("Tipul masinii: ");
        scanf("%c",&steluta);
        scanf("%c", &m[i].tip);

        printf("Nr de accidente: ");
        scanf("%c",&steluta);
        scanf("%d", &m[i].accidente);

        printf("Nr inmatriculare: ");
        scanf("%c",&steluta);
        scanf("%s", m[i].nr_inmatriculare);

        printf("Numele proprietarului: ");
        scanf("%c",&steluta);
        scanf("%s", m[i].p[i].nume);

        printf("Varsta proprietarului: ");
        scanf("%d",&m[i].p[i].varsta);

        printf("Pretul este: ");
        scanf("%f", &m[i].pret);

        m[i].garantie = valabilitate_garantie(i, an_curent);
        printf("Valabilitatea garantiei: %d \n", m[i].garantie );

        printf("Dati adresa: ");
        scanf("%c",&steluta);
        fgets(m[i].p[i].adresa, 100,stdin);
        printf("\n");

        t=verificare_stare(i, an_curent);
        printf("Nivelul de degradare al masinii este: %d \n", t);
    }
    i=i-1;
    union valabilitate v[100];
    k=citire_uniune(i, an_curent);
    if(k==0)
        strcpy(v[i].expirata,"da");
    else
        v[i].ani_ramasi=k;

    actualizare_pret(i);
    schimbare_nr_inmatriculare(i);
    schimbare_tip(i);
    varsta1(i);
    marca_proprietar1(i);
    qsort(m,i+1,sizeof(struct masina),comparare);
    afisare1(i);
}

void citire12() /* citire/afisare din consola si modul de memorare 2*/
{
    int i=0, an_curent, t, k;
    char steluta;
    printf("Introduceti anul curent: ");
    scanf("%d", &an_curent);

    printf("Marca este: ");
    scanf("%c",&steluta);
    scanf("%s",m[i].marca);

    printf("Anul fabricatiei: ");
    scanf("%d", &m[i].an_fabr);

    printf("Tipul masinii: ");
    scanf("%c",&steluta);
    scanf("%c", &m[i].tip);

    printf("Nr de accidente: ");
    scanf("%c",&steluta);
    scanf("%d", &m[i].accidente);

    printf("Nr inmatriculare: ");
    scanf("%c",&steluta);
    scanf("%s", m[i].nr_inmatriculare);

    printf("Numele proprietarului: ");
    scanf("%c",&steluta);
    scanf("%s", m[i].p[i].nume);

    printf("Varsta proprietarului: ");
    scanf("%d",&m[i].p[i].varsta);

    printf("Pretul este: ");
    scanf("%f", &m[i].pret);

    m[i].garantie=valabilitate_garantie(i, an_curent);
    printf("Valabilitatea garantiei: %d \n", m[i].garantie );

    printf("Dati adresa: ");
    scanf(" %c",&steluta);
    fgets(m[i].p[i].adresa, 100,stdin);
    printf("\n");

    t=verificare_stare(i, an_curent);
    printf("Nivelul de degradare al masinii este: %d \n", t);

eticheta1:
    printf("Doriti sa mai introduceti masini? (D/N)");
    char c;
    //scanf("%c", &steluta);
    scanf("%c", &c);
    if(c=='D' || c=='d')

    {
        i=i+1;
        printf("Marca este: ");
        scanf("%c",&steluta);
        scanf("%s",m[i].marca);

        printf("Anul fabricatiei: ");
        scanf("%d", &m[i].an_fabr);

        printf("Tipul masinii: ");
        scanf("%c",&steluta);
        scanf("%c", &m[i].tip);

        printf("Nr de accidente: ");
        scanf("%c",&steluta);
        scanf("%d", &m[i].accidente);

        printf("Nr inmatriculare: ");
        scanf("%c",&steluta);
        scanf("%s", m[i].nr_inmatriculare);

        printf("Numele proprietarului: ");
        scanf("%c",&steluta);
        scanf("%s", m[i].p[i].nume);

        printf("Varsta proprietarului: ");
        scanf("%d",&m[i].p[i].varsta);

        printf("Pretul este: ");
        scanf("%f", &m[i].pret);

        m[i].garantie=valabilitate_garantie(i, an_curent);
        printf("Valabilitatea garantiei: %d \n", m[i].garantie );

        printf("Dati adresa: ");
        scanf("%c",&steluta);
        fgets(m[i].p[i].adresa, 100,stdin);
        printf("\n");

        t=verificare_stare(i, an_curent);
        printf("nivelul de degradare al masinii este: %d \n", t);
        goto eticheta1;
    }
    union valabilitate v[100];
    k=citire_uniune(i, an_curent);
    if(k==0)
        strcpy(v[i].expirata,"da");
    else
        v[i].ani_ramasi=k;

    actualizare_pret(i);
    schimbare_nr_inmatriculare(i);
    schimbare_tip(i);
    varsta1(i);
    marca_proprietar1(i);
    qsort(m,i+1,sizeof(struct masina),comparare);
    afisare1(i);
}

void citire22() /*citire si afisare din fisier cu metoda de memorare 2 */
{
    int i=0, an_curent, t, k;
    fscanf(f, "%d", &an_curent);
    while(feof(f)==0)
    {
        char steluta;


        fscanf(f, "%s",m[i].marca);
        if(m[i].marca!=' ' || m[i].marca!="  " ||m[i].marca!=NULL )
            fprintf(h, "Marca este: %s\n",m[i].marca);

        fscanf(f, "%d", &m[i].an_fabr);
        if(m[i].an_fabr!=0)
            fprintf(h, "Anul fabricatiei: %d\n", m[i].an_fabr);

        fscanf(f,"%c",&steluta);

        fscanf(f, "%c", &m[i].tip);
        fprintf(h, "Tipul masinii: %c\n", m[i].tip);

        fscanf(f, "%d", &m[i].accidente);
        fprintf(h, "Nr de accidente: %d\n", m[i].accidente);

        fscanf(f, "%s", m[i].nr_inmatriculare);
        fprintf(h, "Nr inmatriculare: %s \n", m[i].nr_inmatriculare);

        fscanf(f, "%s", m[i].p[i].nume);
        fprintf(h, "Numele proprietarului: %s \n", m[i].p[i].nume);

        fscanf(f, "%d",&m[i].p[i].varsta);
        fprintf(h, "Varsta proprietarului: %d \n",m[i].p[i].varsta);

        fscanf(f, "%f", &m[i].pret);
        fprintf(h, "Pretul este: %f RON \n", m[i].pret);

        m[i].garantie=valabilitate_garantie(i, an_curent);
        fprintf(h,"Valabilitatea garantiei: %d \n", m[i].garantie );

        fscanf(f,"%c",&steluta);
        fgets(m[i].p[i].adresa, 100,f);
        fputs(m[i].p[i].adresa, h);
        fprintf(h, "\n");

        t=verificare_stare(i, an_curent);
        fprintf(h,"Gradul de degradare al masinii este: %d \n", t);

        i=i+1;
    }
    i=i-1;
    union valabilitate v[100];
    k=citire_uniune(i, an_curent);
    if(k==0)
        strcpy(v[i].expirata,"da");
    else
        v[i].ani_ramasi=k;

    actualizare_pret(i);
    schimbare_nr_inmatriculare(i);
    schimbare_tip(i);
    varsta2(i);
    marca_proprietar2(i);
    qsort(m,i+1,sizeof(struct masina),comparare);
    afisare2(i);
}

void citire21() /*citire/afisare cu fisiere si metoda de memorare 1 */
{
    char steluta;
    int n, an_curent, t, k;
    fscanf(f,"%d",&n);
    fscanf(f, "%d", &an_curent);
    fflush(stdin);
    int i;
    for(i=0; i<n; i++)
    {
        fscanf(f, "%s",m[i].marca);
        fprintf(h, "Marca este: %s \n",m[i].marca);

        fscanf(f, "%d", &m[i].an_fabr);
        fprintf(h, "Anul fabricatiei: %d \n", m[i].an_fabr);

        fscanf(f,"%c",&steluta);

        fscanf(f, "%c", &m[i].tip);
        fprintf(h, "Tipul masinii: %c \n", m[i].tip);

        fscanf(f, "%d", &m[i].accidente);
        fprintf(h, "Nr de accidente: %d \n", m[i].accidente);

        fscanf(f, "%s", m[i].nr_inmatriculare);
        fprintf(h, "Nr inmatriculare: %s \n", m[i].nr_inmatriculare);

        fscanf(f, "%s", m[i].p[i].nume);
        fprintf(h, "Numele proprietarului: %s \n", m[i].p[i].nume);

        fscanf(f, "%d",&m[i].p[i].varsta);
        fprintf(h, "Varsta proprietarului: %d \n",m[i].p[i].varsta);

        fscanf(f, "%f", &m[i].pret);
        fprintf(h, "Pretul este: %f RON \n", m[i].pret);

        m[i].garantie=valabilitate_garantie(i, an_curent);
        fprintf(h,"Valabilitatea garantiei: %d \n", m[i].garantie );

        fscanf(f,"%c",&steluta);
        fgets(m[i].p[i].adresa, 100,f);
        fputs(m[i].p[i].adresa, h);
        fprintf(h, "\n");

        t=verificare_stare(i, an_curent);
        fprintf(h,"Gradul de degradare al masinii este: %d \n", t);
    }
    i=i-1;
    union valabilitate v[100];
    k=citire_uniune(i, an_curent);
    if(k==0)
        strcpy(v[i].expirata,"da");
    else
        v[i].ani_ramasi=k;

    actualizare_pret(i);
    schimbare_nr_inmatriculare(i);
    schimbare_tip(i);
    varsta2(i);
    marca_proprietar2(i);
    qsort(m,i+1,sizeof(struct masina),comparare);
    afisare2(i);

}

void citire13() /* citire/afisare in consola si metoda de memorare 3 */
{
    struct masina *v;
    int n, i, an_curent, t, k;
    char steluta;
    printf("Introduceti anul curent: ");
    scanf("%d", &an_curent);
    printf("Cate masini doriti sa introduceti? ");
    scanf("%d",&n);
    v=malloc(n*sizeof(struct masina));

    for(i=0; i<n; i++)
    {
        printf("Marca este: ");
        scanf("%c",&steluta);
        scanf("%s",m[i].marca);

        printf("Anul fabricatiei: ");
        scanf("%d", &m[i].an_fabr);

        printf("Tipul masinii: ");
        scanf("%c",&steluta);
        scanf("%c", &m[i].tip);

        printf("Nr de accidente: ");
        scanf("%c",&steluta);
        scanf("%d", &m[i].accidente);

        printf("Nr inmatriculare: ");
        scanf("%c",&steluta);
        scanf("%s", m[i].nr_inmatriculare);

        printf("Numele proprietarului: ");
        scanf("%c",&steluta);
        scanf("%s", m[i].p[i].nume);

        printf("Varsta proprietarului: ");
        scanf("%d",&m[i].p[i].varsta);

        printf("Pretul este: ");
        scanf("%f", &m[i].pret);

        m[i].garantie=valabilitate_garantie(i, an_curent);
        printf("Valabilitatea garantiei: %d \n", m[i].garantie );

        printf("Dati adresa: ");
        scanf("%c",&steluta);
        fgets(m[i].p[i].adresa, 100,stdin);
        printf("\n");

        t=verificare_stare(i, an_curent);
        printf("Gradul de degradare al masinii este: %d \n", t);
    }
    i=i-1;
    union valabilitate valab[100];
    k=citire_uniune(i, an_curent);
    if(k==0)
        strcpy(valab[i].expirata,"da");
    else
        valab[i].ani_ramasi=k;

    actualizare_pret(i);
    schimbare_nr_inmatriculare(i);
    schimbare_tip(i);
    varsta1(i);
    marca_proprietar1(i);
    qsort(m,i+1,sizeof(struct masina),comparare);
    afisare1(i);
}

void citire23() /* citire/afisare cu fisiere si metoda de memorare 3*/
{
    struct masina *v;
    int n, i, steluta, an_curent, t, k;
    fscanf(f,"%d",&n);
    fscanf(f, "%d", &an_curent);
    fflush(stdin);
    v=malloc(n*sizeof(struct masina));
    for(i=0; i<n; i++)
    {
        fscanf(f, "%s",m[i].marca);
        fprintf(h, "Marca este: %s \n", m[i].marca);

        fscanf(f, "%d", &m[i].an_fabr);
        fprintf(h, "Anul fabricatiei: %d \n", m[i].an_fabr);

        fscanf(f,"%c",&steluta);

        fscanf(f, "%c", &m[i].tip);
        fprintf(h, "Tipul masinii: %c \n", m[i].tip);

        fscanf(f, "%d", &m[i].accidente);
        fprintf(h, "Nr de accidente: %d \n", m[i].accidente);

        fscanf(f, "%s", m[i].nr_inmatriculare);
        fprintf(h, "Nr inmatriculare: %s \n", m[i].nr_inmatriculare);

        fscanf(f, "%s", m[i].p[i].nume);
        fprintf(h, "Numele proprietarului: %s \n", m[i].p[i].nume);

        fscanf(f, "%d",&m[i].p[i].varsta);
        fprintf(h, "Varsta proprietarului: %d \n",m[i].p[i].varsta);

        fscanf(f, "%f", &m[i].pret);
        fprintf(h, "Pretul este: %f RON \n", m[i].pret);

        m[i].garantie=valabilitate_garantie(i, an_curent);
        fprintf(h,"Valabilitatea garantiei: %d \n", m[i].garantie );

        fscanf(f,"%c",&steluta);
        fgets(m[i].p[i].adresa, 100,f);
        fputs(m[i].p[i].adresa, h);
        fprintf(h, "\n");

        t=verificare_stare(i, an_curent);
        fprintf(h,"Gradul de degradare al masinii este: %d \n", t);
    }
    i=i-1;
    union valabilitate valab[100];
    k=citire_uniune(i, an_curent);
    if(k==0)
        strcpy(valab[i].expirata,"da");
    else
        valab[i].ani_ramasi=k;

    actualizare_pret(i);
    schimbare_nr_inmatriculare(i);
    schimbare_tip(i);
    varsta2(i);
    marca_proprietar2(i);
    qsort(m,i+1,sizeof(struct masina),comparare);
    afisare2(i);
}

void citire14() /* citire/afisare in consola si metoda de memorare 4 */
{
    struct masina *v;
    int n=1, i=0, an_curent, t, k;
    char steluta;
    printf("Introduceti anul curent: ");
    scanf("%d", &an_curent);
    v=malloc(n*sizeof(struct masina));
    printf("Marca este: ");
    scanf("%c",&steluta);
    scanf("%s",m[i].marca);

    printf("Anul fabricatiei: ");
    scanf("%d", &m[i].an_fabr);

    printf("Tipul masinii: ");
    scanf("%c",&steluta);
    scanf("%c", &m[i].tip);

    printf("Nr de accidente: ");
    scanf("%c",&steluta);
    scanf("%d", &m[i].accidente);

    printf("Nr inmatriculare: ");
    scanf("%c",&steluta);
    scanf("%s", m[i].nr_inmatriculare);

    printf("Numele proprietarului: ");
    scanf("%c",&steluta);
    scanf("%s", m[i].p[i].nume);

    printf("Varsta proprietarului: ");
    scanf("%d",&m[i].p[i].varsta);

    printf("Pretul este: ");
    scanf("%f", &m[i].pret);

    m[i].garantie=valabilitate_garantie(i, an_curent);
    printf("Valabilitatea garantiei: %d \n", m[i].garantie );

    printf("Dati adresa: ");
    scanf("%c",&steluta);
    fgets(m[i].p[i].adresa, 100,stdin);
    printf("\n");

    t=verificare_stare(i, an_curent);
    printf("Gradul de degradare al masinii este: %d \n", t);

eticheta:
    printf("Doriti sa mai introduceti masini? (D/N)");
    char c;
    scanf("%c", steluta);
    scanf("%c", &c);
    if(c=='D' || c=='d')

    {
        i=i+1;
        n=n+1;
        v=realloc(v, n*sizeof(struct masina));
        printf("Marca este: ");
        scanf("%c",&steluta);
        scanf("%s",m[i].marca);

        printf("Anul fabricatiei: ");
        scanf("%d", &m[i].an_fabr);

        printf("Tipul masinii: ");
        scanf("%c",&steluta);
        scanf("%c", &m[i].tip);

        printf("Nr de accidente: ");
        scanf("%c",&steluta);
        scanf("%d", &m[i].accidente);

        printf("Nr inmatriculare: ");
        scanf("%c",&steluta);
        scanf("%s", m[i].nr_inmatriculare);

        printf("Numele proprietarului: ");
        scanf("%c",&steluta);
        scanf("%s", m[i].p[i].nume);

        printf("Varsta proprietarului: ");
        scanf("%d",&m[i].p[i].varsta);

        printf("Pretul este: ");
        scanf("%f", &m[i].pret);

        m[i].garantie=valabilitate_garantie(i, an_curent);
        printf("Valabilitatea garantiei: %d \n", m[i].garantie );

        printf("Dati adresa: ");
        scanf("%c",&steluta);
        fgets(m[i].p[i].adresa, 100,stdin);
        printf("\n");

        t=verificare_stare(i, an_curent);
        printf("Gradul de degradare al masinii este: %d \n", t);

        goto eticheta;
    }
    union valabilitate valab[100];
    k=citire_uniune(i, an_curent);
    if(k==0)
        strcpy(valab[i].expirata,"da");
    else
        valab[i].ani_ramasi=k;

    actualizare_pret(i);
    schimbare_nr_inmatriculare(i);
    schimbare_tip(i);
    varsta1(i);
    marca_proprietar1(i);
    qsort(m,i+1,sizeof(struct masina),comparare);
    afisare1(i);
}

void citire24() /* citire/afisare cu fisere si metoda de memorare 4 */
{
    struct masina *v;
    int n=1, i=0, an_curent, t, k;
    fscanf(f, "%d", &an_curent);
    v=malloc(n*sizeof(struct masina));

    while(feof(f)==0)
    {
        n=n+1;
        v=realloc(v, n*sizeof(struct masina));

        char steluta;


        fscanf(f, "%s",m[i].marca);
        if(m[i].marca!=' ' || m[i].marca!="  " ||m[i].marca!=NULL )
            fprintf(h, "Marca este: %s\n",m[i].marca);

        fscanf(f, "%d", &m[i].an_fabr);
        if(m[i].an_fabr!=0)
            fprintf(h, "Anul fabricatiei: %d\n", m[i].an_fabr);

        fscanf(f,"%c",&steluta);

        fscanf(f, "%c", &m[i].tip);
        fprintf(h, "Tipul masinii: %c\n", m[i].tip);

        fscanf(f, "%d", &m[i].accidente);
        fprintf(h, "Nr de accidente: %d\n", m[i].accidente);

        fscanf(f, "%s", m[i].nr_inmatriculare);
        fprintf(h, "Nr inmatriculare: %s \n", m[i].nr_inmatriculare);

        fscanf(f, "%s", m[i].p[i].nume);
        fprintf(h, "Numele proprietarului: %s \n", m[i].p[i].nume);

        fscanf(f, "%d",&m[i].p[i].varsta);
        fprintf(h, "Varsta proprietarului: %d \n",m[i].p[i].varsta);

        fscanf(f, "%f", &m[i].pret);
        fprintf(h, "Pretul este: %f RON \n", m[i].pret);

        m[i].garantie=valabilitate_garantie(i, an_curent);
        fprintf(h,"Valabilitatea garantiei: %d \n", m[i].garantie );

        fscanf(f,"%c",&steluta);
        fgets(m[i].p[i].adresa, 100,f);
        fputs(m[i].p[i].adresa, h);
        fprintf(h, "\n");

        t=verificare_stare(i, an_curent);
        fprintf(h,"Nivelul de degradare al masinii este: %d \n", t);

        i=i+1;
    }
    i=i-1;
    union valabilitate valab[100];
    k=citire_uniune(i, an_curent);
    if(k==0)
        strcpy(valab[i].expirata,"da");
    else
        valab[i].ani_ramasi=k;

    actualizare_pret(i);
    schimbare_nr_inmatriculare(i);
    schimbare_tip(i);
    varsta2(i);
    marca_proprietar2(i);
    qsort(m,i+1,sizeof(struct masina),comparare);
    afisare2(i);
}

void afisare1(int i)/*afisare consola */
{
    int j;
    for(j=0; j<=i; j++)
    {
        printf("Marca este: %s \n", m[j].marca );
        printf("Anul fabricatiei: %d \n", m[j].an_fabr);
        printf("Tipul masinii: %c \n", m[j].tip);
        printf("Nr de accidente: %d \n", m[j].accidente);
        printf("Nr inmatriculare: %s \n", m[j].nr_inmatriculare);
        printf("Numele proprietarului: %s \n", m[j].p[j].nume);
        printf("Varsta proprietarului: %d \n", m[j].p[j].varsta);
        printf("Pretul este: %f \n", m[j].pret);
        printf("Valabilitatea garantiei este: %d \n", m[j].garantie);
        printf("Adresa este: %s \n", m[j].p[j].adresa);

    }

}

void afisare2(int i) /* afisare fisier */
{
    int j;
    for(j=0; j<=i; j++)
    {
        fprintf(h, "Marca este: %s\n",m[j].marca);
        fprintf(h, "Anul fabricatiei: %d\n", m[j].an_fabr);
        fprintf(h, "Tipul masinii: %c\n", m[j].tip);
        fprintf(h, "Nr de accidente: %d\n", m[j].accidente);
        fprintf(h, "Nr inmatriculare: %s \n", m[j].nr_inmatriculare);
        fprintf(h, "Numele proprietarului: %s \n", m[j].p[j].nume);
        fprintf(h, "Varsta proprietarului: %d \n",m[j].p[j].varsta);
        fprintf(h, "Pret: %d \n", m[j]);
        fprintf(h,"Valabilitatea garantiei este: %d \n", m[j].garantie);
        fprintf(h, "Adresa:");
        fputs(m[j].p[j].adresa, h);
        fprintf(h, "\n");

    }
}

void meniu()
{
    int optiune, opt1, opt2;
    char x[20], y[20];
    printf("Alegeti modul de citire/afisare: \n 1.Consola \n 2.Fisiere \n");
    scanf("%d", &opt1);
    printf("Alegeti modul de memorare a datelor:\n \
       1.vector cu n elemente de tip structura \n \
       2.vector fara a cunoaste nr de elemente \n \
       3.alocare dinamica pentru n elemente \n \
       4.alocare dinamica pentru un numar necunoscut de elemente \n");
    scanf("%d", &opt2);
    optiune=opt1*10+opt2;

    switch(optiune)
    {
    case 11:
        printf("Ati ales consola si modul de memorare %d \n", opt2);
        citire11();
        break;

    case 12:
        printf("Ati ales consola si modul de memorare %d \n", opt2);
        citire12();
        break;

    case 13:
        printf("Ati ales consola si modul de memorare %d \n", opt2);
        citire13();
        break;

    case 14:
        printf("Ati ales consola si modul de memorare %d \n", opt2);
        citire14();
        break;

    case 21:
        printf("Ati ales sa lucrati cu fisiere si modul de memorare %d \n \
               Dati numele fisierului din care preluati datele masinilor: \n ", opt2);
        scanf("%s", &x);
        printf("Dati numele fisierului in care vreti sa afisati datele: \n ");
        scanf("%s", &y);
        f=fopen(x, "r");
        h=fopen(y, "w");
        citire21();
        break;

    case 22:
        printf("Ati ales sa lucrati cu fisiere si modul de memorare %d \n \
               Dati numele fisierului din care preluati datele masinilor: \n", opt2);
        scanf("%s", &x);
        printf("Dati numele fisierului in care vreti sa afisati datele: \n ");
        scanf("%s", &y);
        f=fopen(x, "r");
        h=fopen(y, "w");
        citire22();
        break;

    case 23:
        printf("Ati ales sa lucrati cu fisiere si modul de memorare %d \n \
               Dati numele fisierului din care preluati datele masinilor: \n", opt2);
        scanf("%s", &x);
        printf("Dati numele fisierului in care vreti sa afisati datele: \n ");
        scanf("%s", &y);
        f=fopen(x, "r");
        h=fopen(y, "w");
        citire23();
        break;

    case 24:
        printf("Ati ales sa lucrati cu fisiere si modul de memorare %d \n \
               Dati numele fisierului din care preluati datele masinilor: \n", opt2);
        scanf("%s", &x);
        printf("Dati numele fisierului in care vreti sa afisati datele: \n ");
        scanf("%s", &y);
        f=fopen(x, "r");
        h=fopen(y, "w");
        citire24();
        break;
    }

}
void actualizare_pret(int i)
{
    int j;
    for(j=0; j<=i; j++)
    {
        if(m[j].accidente==0)
            m[j].pret=m[j].pret-(m[j].pret*0.2);
        if(m[j].accidente>=1 && m[j].accidente<4)
            m[j].pret=m[j].pret+(m[j].pret*0.3);
        if(m[j].accidente==4 || m[j].accidente==5)
            m[j].pret=m[j].pret+(m[j].pret*0.7);
        if(m[j].accidente>=6)
            m[j].pret=m[j].pret*2;
    }
}
void schimbare_tip(int i) /* schimbati masinile cu cel putin 2 accidente si de tip B in tip C */
{
    int j;
    for(j=0; j<=i; j++)
    {
        if(m[j].accidente>=2)
            if(m[j].tip=='B' || m[j].tip=='b' )
                m[j].tip='C';
    }
}

void schimbare_nr_inmatriculare(int i)  /* toate nr de inmatriculare de sibiu sa fie schimbate in brasov */
{
    int j;
    char s[2]="BV", *p, sep[]= {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for(j=0; j<=i; j++)
    {
        p=strtok(m[j].nr_inmatriculare, sep);
        if(p=="SB" || p=="sb" || p=="Sb")
            strncpy(m[j].nr_inmatriculare, s, 2);
        printf("&s", m[j].nr_inmatriculare);
    }

}

int valabilitate_garantie(int i, int an_curent) /* verificam daca masina a depasit garantia de 5 ani*/
{
    if(an_curent-m[i].an_fabr<=5)
        return 1;
    else
        return 0;


}

int verificare_stare(int j, int an_curent) /*  verificam starea masinilor in felul urmator:
                            starea este excelenta pt o masina nu mai veche de 5 ani si cu cel mult 2 accidente,
                            buna pt o masina veche de 5-8 ani si cu maxim 2 accidente,
                            necesita reparatii daca are intre 3 si 5 accidente si pana la 15 ani vechime,
                            stare proasta pentru masinile mai vachi de 15 ani sau cu mai mult de 5 accidente*/


{
    if((an_curent - m[j].an_fabr) <= 5 && m[j].accidente<=2)
        return excelenta;
    if((an_curent - m[j].an_fabr)>5  && (an_curent - m[j].an_fabr)<=8 && m[j].accidente<=2)
        return buna;
    if(m[j].accidente<=5 && m[j].accidente>2 && (an_curent - m[j].an_fabr)<=15)
        return reparatii;
    if(m[j].accidente>5 || (an_curent - m[j].an_fabr)>15 )
        return proasta;
}

void marca_proprietar1(int i) /* pentru masinile cu mai mult de 3 accidente afisati(in consola) marca si proprietarul  */
{
    int j;
    for(j=0; j>=i; j++)
    {
        if(m[j].accidente>3)
        {
            printf("Marca este: %s \n", m[j].marca );
            printf("Numele proprietearului este: %s \n", m[j].p[j].nume);
        }
    }

}

void marca_proprietar2(int i) /* pentru masinile cu mai mult de 3 accidente afisati(in fisier) marca si proprietarul  */
{
    int j;
    for(j=0; j>=i; j++)
    {
        if(m[j].accidente>3)
        {
            fprintf(h,"Marca este: %s \n", m[j].marca );
            fprintf(h,"Numele proprietearului este: %s \n", m[j].p[j].nume);
        }
    }

}

int citire_uniune(int i, int an_curent)
{
    if(an_curent-m[i].an_fabr<=5)
        return 5-an_curent+m[i].an_fabr;
    else
        return 0;

}

void varsta1(int i) /* sa se afiseze pe ecran varsta proprietarilor cu nume de 5 litere */
{int j;
for(j=0; j<=i;j++)
{
    if(strlen(m[i].p[i].nume)==6)
        printf("Varsta proprietarului este: %d", m[i].p[i].varsta);
}
}

void varsta2(int i) /* sa se afiseze in fisier varsta proprietarilor cu nume de 5 litere */
{int j;
for(j=0; j<=i;j++)
{
    if(strlen(m[i].p[i].nume)==6)
        fprintf(h, "Varsta proprietarului este: %d", m[i].p[i].varsta);
}
}


int main()
{
    meniu();

    return 0;
}
