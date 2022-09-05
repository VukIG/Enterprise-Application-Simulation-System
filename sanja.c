#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ucenik
{
    int index, brojpredmeta;
    char ime[30], prezime[30];
    struct ucenik *sledeci;
}ucenik;

typedef struct predmet{
    int sifra;
    char nazivpredmeta[30];
    int brojstudenata;
    struct predmet *sledeci;
}predmet;

typedef struct prijava{
    int brojindeksa, sifra_pred, ocena;
    struct prijava *sledeci;
}prijava;

predmet* dodaj_na_poceta(predmet* glava, predmet* novi)
{
    novi->sledeci = glava;
    glava = novi;
    return glava;
}

ucenik* dodaj_na_pocetak(ucenik* glava, ucenik* novi)
{
    novi->sledeci = glava;
    glava = novi;
    return glava;
}

prijava* dodaj_na_kraj(prijava* glava, prijava* novi)
{
    if (glava)
    {
        prijava *tekuci = glava;
        while (tekuci->sledeci)
            tekuci = tekuci->sledeci;
        tekuci->sledeci = novi;
    }
    else
        glava = novi;
    return glava;
}

ucenik* unosucenik(int n,ucenik *glavaucenik){
    ucenik *novi;

    int index, ocena, brojpredmeta;
    char s[31];
    while (n)
    {
        novi = (ucenik*)malloc(sizeof(ucenik));
        printf("unesi ime ucenika: ");
        scanf("%s", s);
        strncpy(novi->ime, s, 30);

        printf("unesi prezime ucenika: ");
        scanf("%s", s);
        strncpy(novi->prezime, s, 30);

        printf("unesi broj polozenih predmeta ");
        scanf("%d",&brojpredmeta);
        novi->brojpredmeta = brojpredmeta;

        printf("unesi broj index-a studenta: ");
        scanf("%d", &index);
        novi->index = index;

        glavaucenik = dodaj_na_pocetak(glavaucenik, novi);
        scanf("%d",&n);
    }
    return glavaucenik;
}

predmet* unospredmet(int n,predmet *glavapredmet){
    predmet *novi;

    int sifra,brojstudenata;
    char nazivpredmet[30];

    while (n)
    {
        novi = (predmet*)malloc(sizeof(predmet));
        printf("unesi sifru ");
        scanf("%d",&sifra);
        novi->sifra = sifra;

        printf("unesi naziv predmeta ");
        scanf("%s",nazivpredmet);
        strncpy(novi->nazivpredmeta, nazivpredmet, 30);

        printf("unesi broj studenta ");
        scanf("%d",&brojstudenata);
        novi->brojstudenata = brojstudenata;

        glavapredmet = dodaj_na_poceta(glavapredmet, novi);
        scanf("%d",&n);
    }
    return glavapredmet;
}

prijava* unosprijava(prijava *glava, int ocena, predmet *tmp_p, ucenik *tmp_u){
    prijava *novi;

    novi = (prijava*)malloc(sizeof(prijava));

    novi->brojindeksa = tmp_u->index;
    novi->ocena = ocena;
    novi->sifra_pred = tmp_p->sifra;
    glava = dodaj_na_kraj(glava, novi);

    return glava;
}

predmet* proveriimepredmeta(char imepredmeta[], predmet *glavapredmet){
    predmet *tekuci;
    tekuci=glavapredmet;
    while (tekuci)
    {
        if(strcmp(tekuci->nazivpredmeta, imepredmeta) == 0)
            return tekuci;
        tekuci=tekuci->sledeci;
    }
    return NULL;
}

ucenik* proveriimeucenika(char *ime, char *prezime, ucenik *glavaucenika){
    ucenik *tekuci;
    tekuci=glavaucenika;
    while (tekuci)
    {
        if(strcmp(ime, tekuci->ime)==0 && strcmp(prezime, tekuci->prezime)==0)
            return tekuci;
        tekuci=tekuci->sledeci;
    }
    return NULL;
}

void zameni(prijava *tekuci1,prijava *tekuci2){
    prijava* pom;
    pom=tekuci1;
    tekuci1=tekuci2;
    tekuci2=pom;
}

predmet* sort(predmet* glava){
    predmet *tek2;
    predmet *tek1;
    int br, sif;
    char naziv[30];
    for (tek1 = glava; tek1 != NULL; tek1 = tek1->sledeci){
        for (tek2 = tek1->sledeci; tek2 != NULL; tek2 = tek2->sledeci){
            if(tek1->brojstudenata < tek2->brojstudenata){
                br = tek1->brojstudenata;
                sif = tek1->sifra;
                strcpy(naziv, tek1->nazivpredmeta);

                tek1->brojstudenata = tek2->brojstudenata;
                strcpy(tek1->nazivpredmeta, tek2->nazivpredmeta);
                tek1->sifra = tek2->sifra;
                
                tek2->brojstudenata = br;
                strcpy(tek2->nazivpredmeta, naziv);
                tek2->sifra = sif;
            }
        }
    }

    tek1 = glava;
    while (tek1)
    {
        printf("%d ",tek1->sifra);
        printf("%s ",tek1->nazivpredmeta);
        printf("%d \n",tek1->brojstudenata);
        tek1 = tek1->sledeci;
    }

    return glava;
}

void ispis_prijava(prijava* glava){
    while(glava != NULL){
        printf("%d \n",glava->ocena);
        glava = glava->sledeci;
    }
}

int main(){

    int bru,brp,nneki,tata;
    char imestudenta[30], ppredmet[30], prezime[30];
    int ocena;

    predmet *glavapredmet = NULL;
    ucenik *glavaucenik = NULL;
    prijava *glava = NULL;

    printf("unosi uceike,0 ako te je smorilo ");
    scanf("%d",&bru);
    glavaucenik = unosucenik(bru, glavaucenik);
    
    printf("unosi predmete,0 ako te je smorilo ");
    scanf("%d",&brp);
    glavapredmet = unospredmet(brp, glavapredmet);

    tata = 1;
    
    while (tata){
        system("cls");
        printf("unesi 1 za novu prijavu \n");
        printf("unesi 2 za formiranje izvestaja \n");
        printf("unesi 3 za kraj \n");
        scanf("%d",&tata);
        if(tata==1){
            printf("unesi novu prijavu:\n ");
            printf("\tunesi ime studenta: ");
            scanf("%s",imestudenta);

            printf("\tunesi prezime studenta: ");
            scanf("%s", prezime);

            printf("\tunesi ocenu: ");
            scanf("%d",&ocena);

            printf("\tunesi ime predmeta: ");
            scanf("%s", ppredmet);

            ucenik *tmp_u = proveriimeucenika(imestudenta, prezime, glavaucenik);
            predmet *tmp_p = proveriimepredmeta(ppredmet, glavapredmet);
            
            if (ocena < 11 && ocena > 4 && tmp_p != NULL && tmp_u != NULL)
                glava = unosprijava(glava, ocena, tmp_p, tmp_u);
            else
                printf("greska");
        }
        else if(tata==2){
            printf("formiraj izvestaj ");
            glavapredmet = sort(glavapredmet);
        }
        else if(tata==3){
            printf("plvs vltra \n");
            break;
        }
        else{
            printf("greska \n");
            break;
        }
        system("pause");
    }
    return 0;
}