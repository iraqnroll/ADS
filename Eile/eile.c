#include <stdio.h>
#include <stdlib.h>
#include "eile.h"

// !!! Nepamirskite pakeisti printf'u pagal naudojama duomenu tipa
void SpausdinkEil(Eile *eil, int eilValid)
{
    if(eil != NULL && eilValid == 1)
    {
        Eile *e_darb = eil;
        printf("\n");
        while(e_darb != NULL)
        {
            printf("| %d |",e_darb->duomuo);
            e_darb = e_darb->kitas;
        }
        printf("\n");
    }
    else
    {
        printf("|  |\n");
    }
}


int SukurkEil(Eile **eil, int *eilValid)
{
    if(*eilValid == 0)
    {
        *eil = NULL;
        *eilValid = 1;      //indikuoja, jog eile yra sukurta.
        return 0;
    }
    else return 1;
}

int TuscEilCheck(Eile **eil, int eilValid)
{
    if(*eil == NULL && eilValid == 1) return 0;
    else return 2;
}

int IdetEil(Eile **eil, eilduom duomuo, int eilValid)
{
    if(eilValid == 1)
    {
        if(*eil == NULL)
        {
            *eil = (Eile *)malloc(sizeof(Eile));
            Eile *e_darb = *eil;
            e_darb->kitas = NULL;
            e_darb->duomuo = duomuo;
            *eil = e_darb;
            return 0;
        }
        else if(*eil != NULL)
        {
            Eile *e_darb = *eil;
            //Iteruojam iki eiles galo:
            while(e_darb->kitas != NULL)
            {
                e_darb = e_darb->kitas;
            }
            Eile *temp = (Eile *)malloc(sizeof(Eile));
            temp->kitas = NULL;
            temp->duomuo = duomuo;
            e_darb->kitas = temp;
            return 0;
        }
    }
    else return 3;
}

int IsimtEil(Eile **eil, int eilValid)
{
    if(eilValid == 1 && *eil != NULL)
    {
        Eile *e_darb = *eil;
        *eil = e_darb->kitas;
        free(e_darb);
        return 0;
    }
    else return 3;
}

int ElemSk(Eile **eil, int *sk, int eilValid)
{
    if(eilValid == 1)
    {
        *sk = 0;
        Eile *e_darb = *eil;
        while(e_darb != NULL)
        {
            *sk+=1;
            e_darb = e_darb->kitas;
        }
        return 0;
    }
    else return 3;
}

int NaikintEil(Eile **eil, int *eilValid)
{
    if(*eilValid == 1)
    {
        Eile *s_darb = *eil;
        while(s_darb != NULL)
        {
            Eile *temp = s_darb;
            s_darb = s_darb->kitas;
            free(temp);
        }

        *eilValid = 0;
        return 0;
    }
    else return 4;
}

