#ifndef hrac_h
#define hrac_h

#include <iostream>
#include <vector>
#include "Predmet.h"
#include "Pozicia.h"
#include "Brnenie.h"
#include "Zbran.h"

///trieda ktora definuje vlastnosti hraca

class Hrac
    {
    private:
        std::string m_meno; ///premenna obsahujuca meno hraca
        std::vector<Predmet* > m_inventar;  ///premenna typu vektor predmetov ktora obsahuje vsetky predemty ktore hrac anzbieral
        Pozicia m_pozicia; ///pozicia na ktorej sa hrac nachadza
        int m_zivot; ///zivot hraca
        Brnenie* m_brnenie; ///premenna typu ukazatel an objekt Brnenie, ktore hrac prave teraz pouziva
        Zbran* m_zbran; ///premenna typu ukazatel na objekt Zbran, ktoru hrac prave teraz pouziva
    public:
        Hrac(); ///bezparametricky konstruktor, iny nieje potrebny
        Pozicia getPozicia(); ///metoda ktora vracia poziciu an ktorej sa hrac nachadza
        void setPozicia(Pozicia poz); ///metoda ktora nastavuje premennu m_pozicia
        Zbran* getZbran(); ///metoda ktora vracia ukazatel na objekt Zbran ktory hrac pouziva
        Brnenie* getBrnenie(); ///meotda ktora vracia ukazatel na objekt Brnenie ktory hrac pouziva
        int getZivot(); ///metoda ktora vracia premennu m_zivot
        void pridaj(Zbran* zbran); ///metoda ktora prida no vektora m_inventar objekt predany v parametre, a pokial je lepsi ako objekt v premennej m_zbran tak ho nahradi
        void pridaj(Brnenie* brn); ///metoda ktora prida no vektora m_inventar objekt predany v parametre, a pokial je lepsi ako objekt v premennej m_brnenie tak ho nahradi
        std::vector<Predmet*> getInventar(); ///metoda ktora vrati celi vektor predemtov
    };


#endif
