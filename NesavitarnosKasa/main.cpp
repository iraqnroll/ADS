#include <iostream>
#include <cstdlib>
#include "darbuotojai.h"

int main(int argc, const char *argv[])
{
    int Laikas, KasSk, PardSk, ProcNr;
    std::list<Pardaveja> pardavejos;
    std::list<Kasininke> kasininkes;
    std::cout<<"Iveskite proceso numeri : ";
    std::cin>>ProcNr;
    std::cout<<"Iveskite proceso trukme T = ";
    std::cin>>Laikas;
    std::cout<<"Iveskite Kasininkiu skaiciu : ";
    std::cin>>KasSk;
    std::cout<<"Iveskite Pardaveju skaiciu : ";
    std::cin>>PardSk;

    
    switch (ProcNr)
    {
        case 1:
            InitPard(&pardavejos, PardSk);
            InitKas(&kasininkes, KasSk);
            Procesas1(&pardavejos, Laikas);
            std::cout<<"Procesas 1 ivykdytas."<<std::endl;
            break;
        case 2:
            InitPard(&pardavejos, PardSk);
            InitKas(&kasininkes, KasSk);
            Procesas2(&pardavejos, &kasininkes, Laikas);
            std::cout<<"Procesas 2 ivykdytas."<<std::endl;
        break;
    }
    
    return 0;
}
