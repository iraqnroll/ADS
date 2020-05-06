#include <list>
#include <queue>
#include <vector>

typedef struct Klientas
{
    int KlientoNr, PardavejosNr;
    int AtejimoLaikas, IsejimoLaikas, AptLaikas;
    int KlientoStatusas;    //0 - tik ka atejes. 1 - Priimamos prekes. 2 - Prekes priimtos, keliauja i kasa. 3 - Musamas cekis. 4 - Cekis ismustas, grizta i prioritetine eile.
    bool TuriCeki;
}Klientas;

struct compare
{
    bool operator()(const Klientas &a, const Klientas &b)
    {
        return a.KlientoNr<b.KlientoNr;
    }
};


typedef struct Pardaveja
{
    Klientas dabartinisKlientas;
    int PardavejosNr;
    bool Uzimta;
    std::queue<Klientas> eile;
    std::list<Klientas> peile;
}Pardaveja;

typedef struct Kasininke
{
    Klientas dabartinisKlientas;
    int KasosNr;
    bool Uzimta;
    std::queue<Klientas> eile;
}Kasininke;

void InitPard(std::list<Pardaveja> *pardavejos, int PardSk);
void InitKas(std::list<Kasininke> *kasininkes, int KasSk);
void RinktiRezultatus(int *MinLaik, int *MaxLaik, Klientas klientas);
void Procesas2(std::list<Pardaveja> *pardavejos, std::list<Kasininke> *kasininkes, int Laikas);
void Procesas1(std::list<Pardaveja> *pardavejos, int Laikas);