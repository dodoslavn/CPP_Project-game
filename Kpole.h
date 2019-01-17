#ifndef kreslicp_
#define kreslicp_

#include "Kreslic.h"

#include "Lokacia.h"

///trieda ktora sa stara o vykreslovanie herneho pola

class Kpole : public Kreslic
    {
    private:
        Lokacia* m_lokacia; ///premenna typu uakzatel na Lokaciu ktora sa prave pouziva
        Hrac* m_hrac; ///premenna osbahujuca ukazatel an hraca
    public:
        Kpole(Lokacia* lokacia, Hrac* hrac); ///parametricky konstruktor ktori parametre ulozi do atributov
        void Kresli(); ///metoda ktora sa stara o vykreslovanie
        void Hraca(Pozicia poz); ///pomocna metoda ktora vykresli harac na pozicii zadanej v parametre
        void Nepriatela(Pozicia poz); ///pomocna metoda ktora vykresli nepriatela na zadanej pozicii
        void Cesta(Pozicia prva, Pozicia druha); ///pomocna metoda ktora vykresli cestu na zadanej pozicii
        void Nic(Pozicia prva, Pozicia druha); ///pomozna metoda ktora vykresli tmu
        void Stena(Pozicia prva, Pozicia druha); ///pomocna metoda ktora vykresli stenu
        void Brnenie(Pozicia poz); ///pomocna metoda ktora vykresli brnenie 
        void Zbran(Pozicia poz); ///pomocna metoda ktora vykresli zbran 
        void portal(Pozicia poz); ///pomocna metoda ktora vykresli miesto portalu
    };


#endif
