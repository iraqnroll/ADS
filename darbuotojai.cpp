#include "darbuotojai.h"
#include <iostream>
#include <fstream>
#include <time.h>

void InitKas(std::list<Kasininke> *kasininkes, int KasSk)
{
    Kasininke tempKas;
    for(int i = 1; i <= KasSk; i++)
    {
        tempKas.KasosNr = i;
        tempKas.Uzimta = false;
        kasininkes->push_back(tempKas);
    }
}

void InitPard(std::list<Pardaveja> *pardavejos, int PardSk)
{
    Pardaveja tempPard;
    for(int i = 1; i <= PardSk; i++)
    {
        tempPard.PardavejosNr = i;
        tempPard.Uzimta = false;
        pardavejos->push_back(tempPard);
    }
}

void RinktiRezultatus(int *MinLaik, int *MaxLaik, Klientas klientas)
{
    if(klientas.KlientoNr == 1)
    {
        *MinLaik = klientas.AptLaikas;
        *MaxLaik = klientas.AptLaikas;
    }
    else
    {
        if(klientas.AptLaikas > *MaxLaik) *MaxLaik = klientas.AptLaikas;
        if(klientas.AptLaikas < *MinLaik) *MinLaik = klientas.AptLaikas;
    }
}

void Procesas1(std::list<Pardaveja> *pardavejos, int Laikas)
{
    int T = 0;
    std::ofstream fwrite ("1PROCESAS.txt");
    unsigned int seed = (unsigned)time(NULL);
    int KlientoNr=1, AptKlientuSk=0;
    int MinAptLaikas, MaxAptLaikas;
    int KlientuSk;
    Klientas tempKlientas;
    fwrite<<"PARAMETRAI : "<<std::endl;
    fwrite<<"Proceso trukme T = "<<Laikas<<"."<<std::endl;
    fwrite<<"Pardaveju skaicius : "<<pardavejos->size()<<"."<<std::endl;
    fwrite<<std::endl;

    while(T<Laikas)
    {
        srand(seed);
        fwrite<<"T : "<<T<<std::endl;
        for(std::list<Pardaveja>::iterator i = pardavejos->begin(); i!= pardavejos->end(); i++)
        {
            KlientuSk = (rand()%3)+1;
            seed++;
            for(int k=0;k<KlientuSk;k++)
            {
                tempKlientas.KlientoStatusas = 0;
                tempKlientas.TuriCeki = false;
                i->eile.push(tempKlientas);
            }
            if(i->Uzimta == false)
            {
                if(i->eile.empty() == 0)
                {
                    if(i->eile.front().KlientoStatusas == 0)
                    {
                        i->dabartinisKlientas = i->eile.front();
                        i->eile.pop();
                        i->dabartinisKlientas.KlientoNr = KlientoNr;
                        KlientoNr++;
                        i->dabartinisKlientas.AtejimoLaikas = T;
                        i->Uzimta = true;
                        i->dabartinisKlientas.KlientoStatusas = 1;
                        fwrite<<"   Klientui "<<i->dabartinisKlientas.KlientoNr<<" paduoda prekes pardaveja "<<i->PardavejosNr<<std::endl;
                    }
                }
            }
            else if(i->Uzimta == true)
            {
                if(i->dabartinisKlientas.KlientoStatusas == 2)
                {
                   i->dabartinisKlientas.IsejimoLaikas = T;
                   i->dabartinisKlientas.AptLaikas = i->dabartinisKlientas.IsejimoLaikas - i->dabartinisKlientas.AtejimoLaikas;
                   i->Uzimta = false;
                   AptKlientuSk++;
                   RinktiRezultatus(&MinAptLaikas, &MaxAptLaikas, i->dabartinisKlientas);
                   fwrite<<"    Klientas "<<i->dabartinisKlientas.KlientoNr<<" dave pinigus pardavejai "<<i->PardavejosNr<<".";
                   fwrite<<" Jis uztruko "<<i->dabartinisKlientas.AptLaikas<<" min."<<std::endl;
                   if(i->eile.empty() == 0)
                    {
                        if(i->eile.front().KlientoStatusas == 0)
                        {
                            i->dabartinisKlientas = i->eile.front();
                            i->eile.pop();
                            i->dabartinisKlientas.KlientoNr = KlientoNr;
                            KlientoNr++;
                            i->dabartinisKlientas.AtejimoLaikas = T;
                            i->Uzimta = true;
                            i->dabartinisKlientas.KlientoStatusas = 1;
                            fwrite<<"   Klientui "<<i->dabartinisKlientas.KlientoNr<<" paduoda prekes pardaveja "<<i->PardavejosNr<<"."<<std::endl;
                        }
                    }
                }
                else if(i->dabartinisKlientas.KlientoStatusas == 1)
                {
                    fwrite<<"   Klientui "<<i->dabartinisKlientas.KlientoNr<<" ismuse ceki pardaveja "<<i->PardavejosNr<<"."<<std::endl;
                    i->dabartinisKlientas.KlientoStatusas = 2;
                }

            }
        }
        T++;
    }
    fwrite<<std::endl;
    fwrite<<"REZULTATAI : "<<std::endl;
    fwrite<<"Aptarnauta klientu : "<<AptKlientuSk<<"."<<std::endl;
    fwrite<<"Trumpiausias aptarnavimas : "<<MinAptLaikas<<" min."<<std::endl;
    fwrite<<"Ilgiausias aptarnavimas : "<<MaxAptLaikas<<" min."<<std::endl;
    fwrite.close();
}



void Procesas2(std::list<Pardaveja> *pardavejos, std::list<Kasininke> *kasininkes, int Laikas)
{
    int T = 0;
    std::ofstream fwrite ("2PROCESAS.txt");
    unsigned int seed = (unsigned)time(NULL);
    int KlientoNr=1, AptKlientuSk=0;
    int MinAptLaikas, MaxAptLaikas;
    int KlientuSk;
    Klientas tempKlientas;
    fwrite<<"PARAMETRAI : "<<std::endl;
    fwrite<<"Proceso trukme T = "<<Laikas<<"."<<std::endl;
    fwrite<<"Pardaveju skaicius : "<<pardavejos->size()<<"."<<std::endl;
    fwrite<<"Kasininkiu skaicius : "<<kasininkes->size()<<"."<<std::endl;
    fwrite<<std::endl;

    while(T<Laikas)
    {   
        srand(seed);
        fwrite<<"T : "<<T<<std::endl;
        for(std::list<Pardaveja>::iterator i = pardavejos->begin(); i != pardavejos->end(); i++)
        {
            KlientuSk = (rand()%3)+1;
            seed++;
            for(int g=0;g<KlientuSk;g++)
            {
                //tempKlientas.KlientoNr = KlientoNr;
                //KlientoNr++;
                tempKlientas.KlientoStatusas = 0;
                tempKlientas.TuriCeki = false;
                i->peile.push_back(tempKlientas);
            }
            if(i->Uzimta == false)
            {
                if(i->peile.empty() == 0)
                { 
                    if(i->peile.front().TuriCeki == true)
                    {
                        i->dabartinisKlientas = i->peile.front();
                        i->peile.pop_front();
                        i->dabartinisKlientas.IsejimoLaikas = T;
                        i->dabartinisKlientas.AptLaikas = i->dabartinisKlientas.IsejimoLaikas - i->dabartinisKlientas.AtejimoLaikas;
                        RinktiRezultatus(&MinAptLaikas, &MaxAptLaikas, i->dabartinisKlientas);
                        AptKlientuSk++;
                        fwrite<<"    Klientas "<<i->dabartinisKlientas.KlientoNr<<" paeme savo prekes.";
                        fwrite<<" Jis uztruko "<<i->dabartinisKlientas.AptLaikas<<" min."<<std::endl;

                        i->dabartinisKlientas = i->peile.front();
                        i->peile.pop_front();
                        i->dabartinisKlientas.KlientoNr = KlientoNr;
                        KlientoNr++;
                        i->dabartinisKlientas.PardavejosNr = i->PardavejosNr;
                        i->dabartinisKlientas.AtejimoLaikas = T;
                        i->Uzimta = true;
                        fwrite<<"    Kliento "<<i->dabartinisKlientas.KlientoNr<<" prekes priimamos pardavejos "<<i->PardavejosNr<<"."<<std::endl;
                        i->dabartinisKlientas.KlientoStatusas = 1;
                    }
                    else if(i->peile.front().KlientoStatusas == 0)  //Tik ka atejes klientas.
                    {
                        i->dabartinisKlientas = i->peile.front();
                        i->peile.pop_front();
                        i->dabartinisKlientas.KlientoNr = KlientoNr;
                        KlientoNr++;
                        i->dabartinisKlientas.PardavejosNr = i->PardavejosNr;
                        i->dabartinisKlientas.AtejimoLaikas = T;
                        i->Uzimta = true;
                        fwrite<<"    Kliento "<<i->dabartinisKlientas.KlientoNr<<" prekes priimamos pardavejos "<<i->PardavejosNr<<"."<<std::endl;
                        i->dabartinisKlientas.KlientoStatusas = 1;
                    }
                }
            }
            if(i->Uzimta == true)
            {
                if(i->dabartinisKlientas.KlientoStatusas == 2)
                {
                    //Pardaveja nebera uzimta.
                    //Priskiriam kasa su maziausia eile.
                    i->Uzimta = false;
                    std::list<Kasininke>::iterator PriskirtaKasa = kasininkes->begin();
                    for(std::list<Kasininke>::iterator j = kasininkes->begin(); j != kasininkes->end(); j++)
                    {
                        if(j->eile.size() < PriskirtaKasa->eile.size())
                        {
                            PriskirtaKasa = j;
                        }
                    }
                    PriskirtaKasa->eile.push(i->dabartinisKlientas);
                    fwrite<<"    Kliento "<<i->dabartinisKlientas.KlientoNr<<" prekes priimtos pardavejos "<<i->dabartinisKlientas.PardavejosNr<<".";
                    fwrite<<" Klientas "<<i->dabartinisKlientas.KlientoNr<<" keliauja i kasa "<<PriskirtaKasa->KasosNr<<"."<<std::endl;
                    if(i->peile.empty() == 0)
                    {
                        if(i->peile.front().TuriCeki == true)
                        {
                            i->dabartinisKlientas = i->peile.front();
                            i->peile.pop_front();
                            i->dabartinisKlientas.IsejimoLaikas = T;
                            i->dabartinisKlientas.AptLaikas = i->dabartinisKlientas.IsejimoLaikas - i->dabartinisKlientas.AtejimoLaikas;
                            RinktiRezultatus(&MinAptLaikas, &MaxAptLaikas, i->dabartinisKlientas);
                            AptKlientuSk++;
                            fwrite<<"    Klientas "<<i->dabartinisKlientas.KlientoNr<<" paeme savo prekes.";
                            fwrite<<" Jis uztruko "<<i->dabartinisKlientas.AptLaikas<<" min."<<std::endl;

                            i->dabartinisKlientas = i->peile.front();
                            i->peile.pop_front();
                            i->dabartinisKlientas.KlientoNr = KlientoNr;
                            KlientoNr++;
                            i->dabartinisKlientas.PardavejosNr = i->PardavejosNr;
                            i->dabartinisKlientas.AtejimoLaikas = T;
                            i->Uzimta = true;
                            fwrite<<"    Kliento "<<i->dabartinisKlientas.KlientoNr<<" prekes priimamos pardavejos "<<i->PardavejosNr<<"."<<std::endl;
                            i->dabartinisKlientas.KlientoStatusas = 1;
                        }
                        else if(i->peile.front().KlientoStatusas == 0)  //Tik ka atejes klientas.
                        {
                            i->dabartinisKlientas = i->peile.front();
                            i->peile.pop_front();
                            i->dabartinisKlientas.KlientoNr = KlientoNr;
                            KlientoNr++;
                            i->dabartinisKlientas.PardavejosNr = i->PardavejosNr;
                            i->dabartinisKlientas.AtejimoLaikas = T;
                            i->Uzimta = true;
                            fwrite<<"    Kliento "<<i->dabartinisKlientas.KlientoNr<<" prekes priimamos pardavejos "<<i->PardavejosNr<<"."<<std::endl;
                            i->dabartinisKlientas.KlientoStatusas = 1;
                        }
                    }
                    
                }
                if(i->dabartinisKlientas.KlientoStatusas == 1)
                {
                    i->dabartinisKlientas.KlientoStatusas = 2;
                }
            }
        }
        for(std::list<Kasininke>::iterator j = kasininkes->begin(); j != kasininkes->end(); j++)
        {
            if(j->Uzimta == true)
            {
                if(j->dabartinisKlientas.KlientoStatusas == 3)
                {
                    j->Uzimta = false;
                    j->dabartinisKlientas.KlientoStatusas = 4;
                    j->dabartinisKlientas.TuriCeki = true;
                    fwrite<<"    Klientui "<<j->dabartinisKlientas.KlientoNr<<" ismustas cekis.";
                    fwrite<<" Jis grizta pas pardaveja "<<j->dabartinisKlientas.PardavejosNr<<"."<<std::endl;
                    for(std::list<Pardaveja>::iterator p = pardavejos->begin(); p != pardavejos->end(); p++)
                    {
                        if(p->PardavejosNr == j->dabartinisKlientas.PardavejosNr)
                        {
                            p->peile.push_front(j->dabartinisKlientas);    //Grazinam klienta i jo pardavejos eiles pradzia.
                        }
                    }
                }

            }
            if(j->Uzimta == false)
            {
                if(j->eile.empty() == 0)
                {
                    j->dabartinisKlientas = j->eile.front();
                    j->eile.pop();
                    j->Uzimta = true;
                    if(j->dabartinisKlientas.KlientoStatusas == 2)
                    {
                        fwrite<<"    Klientui "<<j->dabartinisKlientas.KlientoNr<<" musamas cekis kasoje "<<j->KasosNr<<"."<<std::endl;
                        j->dabartinisKlientas.KlientoStatusas = 3;
                    }
                }
            }
        }
        T++;
    }
    fwrite<<std::endl;
    fwrite<<"REZULTATAI : "<<std::endl;
    fwrite<<"Aptarnauta klientu : "<<AptKlientuSk<<"."<<std::endl;
    fwrite<<"Trumpiausias aptarnavimas : "<<MinAptLaikas<<" min."<<std::endl;
    fwrite<<"Ilgiausias aptarnavimas : "<<MaxAptLaikas<<" min."<<std::endl;
    fwrite.close();
}