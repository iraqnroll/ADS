#include <stdio.h>
#include <stdlib.h>
#include "eile.h"

/*Error kodai:
0 - Viskas gerai.
1 - Vartotojas bando sukurti nauja eile, kai jau yra viena sukurta.
2 - Eile nesukurta arba nera tuscia.
3 - Vartotojas bando iterpti/isimti elementa nesukures eiles.
4 - Vartotojas bando salinti eile nesukures jos.
*/
typedef enum
{
   RINK_SUKURK=1,
   RINK_ITERPK=2,
   RINK_ISMESK=3,
   RINK_SUNAIKINK=4,
   RINK_SUSKAICIUOK=5,
   RINK_SPAUSDINK=6,
   RINK_PATIKRINK=7,
   RINK_BAIKDARBA=8
} vart_pasirinkimas;

int ProgInit()
{
    int pasirinkimas;
    printf("\n");
    printf("Ka noretumete daryti ? \n");

    printf("Sukurti nauja (tuscia) eile - 1\n");
    printf("Iterpti nauja elementa i eile - 2\n");
    printf("Ismesti elementa is eiles- 3\n");
    printf("Sunaikinti eile - 4\n");
    printf("Suskaiciuoti kiek elementu yra eileje - 5\n");
    printf("Atspausdinti eile - 6\n");
    printf("Patikrinti ar eile tuscia - 7\n");
    printf("Baigti darba - 8\n");

    scanf("%d", &pasirinkimas);
    
    return pasirinkimas;
}

int main()
{
    int pasirinkimas, error_code, sk=0;
    int eilValid=0;             //pagalbinis kintamasis, pagal kuri nustatysime ar eile sukurta, ar ne.
    eilduom duom;
    Eile *eile;
    while(pasirinkimas != RINK_BAIKDARBA)
    {
        pasirinkimas = ProgInit();

        switch (pasirinkimas)
        {
        case RINK_SUKURK:
            error_code = SukurkEil(&eile,&eilValid);
            if(error_code != 0) printf("ERROR_CODE : %d\n",error_code);
            break;
        case RINK_ITERPK:
            if(eilValid == 1)
            {
                printf("Iveskite elemento reiksme : ");
                scanf("%d",&duom);
            }
            error_code = IdetEil(&eile,duom,eilValid);
            if(error_code != 0) printf("ERROR_CODE : %d\n",error_code);
            break;
        case RINK_ISMESK:
            error_code = IsimtEil(&eile,eilValid);
            if(error_code != 0) printf("ERROR_CODE : %d\n",error_code);
            break;
        case RINK_SUNAIKINK:
            error_code = NaikintEil(&eile,&eilValid);
            if(error_code != 0) printf("ERROR_CODE : %d\n",error_code);
            break;
        case RINK_SUSKAICIUOK:
            error_code = ElemSk(&eile,&sk,eilValid);
            if(error_code != 0) printf("ERROR_CODE : %d\n",error_code);
            else printf("Eiles elementu skaicius : %d \n",sk);
            break;
        case RINK_SPAUSDINK:
            SpausdinkEil(eile,eilValid);
            break;
        case RINK_PATIKRINK:
            error_code = TuscEilCheck(&eile,eilValid);
            if(error_code != 0) printf("ERROR_CODE : %d\n",error_code);
            break;
        }

    }

    return 0; 
}