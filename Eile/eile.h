/*
Lukas Tamulaitis VU MIF PS 1 k.

Eile - sarasas, kuriame elementai gali buti iterpiami tik i gala, o naikinami
tik pradzioje.
Operacijos:
1. Sukurti tuscia eile  (x)
2. Patikrinti ar eile tuscia    (x)    
(?)3. Patikrinti ar eile pilna (Jeigu eile kuriama dinamiskai sis tikrinimas nelogiskas)
4. Ideti nauja elementa i eile  (x)
5. Isimti elementa is eiles     (x)
6. Gauti pirmo eiles elemento duomenis, neisimant jo is eiles (???)
7. Gauti eiles elementu skaiciu (x)
8. Sunaikinti eile      (x)


SIOJE VIETOJE NUSTATYTI KOKIO TIPO DUOMENIMIS EILE OPERUOS !
*/
typedef int eilduom;


typedef struct Eile
{
    eilduom duomuo;
    struct Eile *kitas;

} Eile;

/*Error kodai:
0 - Viskas gerai.
1 - Vartotojas bando sukurti nauja eile, kai jau yra viena sukurta.
2 - Eile nesukurta arba nera tuscia.
3 - Vartotojas bando iterpti/isimti elementa nesukures eiles arba eile yra tuscia.
4 - Vartotojas bando salinti eile nesukures jos.
*/

void SpausdinkEil(Eile *eil, int eilValid);             
int SukurkEil(Eile **eil, int *eilValid);               //return: Error kodas
int TuscEilCheck(Eile **eil, int eilValid);             //return: Error kodas
int IdetEil(Eile **eil, eilduom duomuo, int eilValid);  //return: Error kodas
int IsimtEil(Eile **eil, int eilValid);                 //return: Error kodas
int ElemSk(Eile **eil, int *sk, int eilValid);          //return: Error kodas
int NaikintEil(Eile **eil, int *eilValid);              //return: Error kodas