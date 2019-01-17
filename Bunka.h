#ifndef nunka_h
#define nunka_h

#include "Zbran.h"
#include "Brnenie.h"
#include "Nepriatel.h"

class Bunka
    {
    private:
        Nepriatel* m_nepriatel; ///ukazatel na objekt triedy Nepriatel ktori vlastni tato bunka
        Zbran* m_zbran; ///ukazatel na objekt triedy zbrane ktori vlastni tato bunka
        Brnenie* m_brnenie; ///ukazatel na objekt triedy Brnenie ktori vlastni tato bunka
        bool m_volno; ///hodnota ci je tato bunka stena alebo chodba
        bool m_tma; /// hodnota ci je tato bunka uz odkryta alebo nie
        bool m_portal; /// hodnota ci tato bunka je prechod do dalsej lokacie
    public:
        Bunka(bool tma); ///konstruktor s parametrom ci je bunka odkryta alebo nie
        void Vloz(Brnenie* brn);  /// metoda na vlozenie ukazatela na objekt Brnenie pre atribut m_brnenie
        void Vloz(Zbran* zbran); /// metoda na vlozenie ukazatela na objekt Zbran pre atribut m_zbran
        void Vloz(bool volno); /// metoda na upravenie ci je dana bunka stenaa lebo cesta
        void Vloz(Nepriatel* nepriatel); /// metoda na vlozenie ukazatela na objekt Nepriatel pre atribut m_nepriatel
        void setPortal(bool portal); /// metoda na nastavenie ci je dana bunka portal, tato hodnota sa uklada do premennej m_portal
        bool getPortal(); ///metoda ktora vracia hodnotu ci je portalom alebo nie, na zaklade premmenej m_portal

        bool getTma(); /// metoda ktora vrati hodtnotu premmenej m_tma
        void setTma(bool tma); /// metoda ktora nastavi premennu m_tma

        bool getVolno(); ///metoda ktora vrati obsah hodnoty m_volno
        Brnenie* getBrnenie(); ///metoda ktora vrati obsah premmenej m_brnenie
        Zbran* getZbran(); /// metoda ktora vrati obsah premennej m_zbran
        Nepriatel* getNepriatel(); ///metoda ktora vrati obsah premmenej m_nepritatel
    };


#endif
