#ifndef lok_
#define lok_

#include "Bunka.h"
#include <vector>

///

class Lokacia
    {
    private:
            bool m_farba; ///premenna obsahujuca aky typ lokacie to je
            std::vector<std::vector<Bunka*> > m_matica; ///matica ukazatelov na objekt Bunka
    public:
            Lokacia(); ///bezparametrcky konstruktor
            Lokacia(bool tma); ///konstruktor ktori nastavy aby vsetky Bunky v matici mali atribut tma podla parametra
            Bunka* getBunka(int ix, int y); /// metoda ktora vrati ukazatel na Bunku ktora je na danej suradnici
            void setFarba(bool f); ///metoda ktora nastavy premennu m_farba
            bool getFarba(); ///metoda ktora vrati obsah premennej m_farba
    };

#endif
