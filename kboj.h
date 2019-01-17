#ifndef KBOJ_H
#define KBOJ_H

#include <string>
#include <iostream>
#include <stdlib.h>

#include <vector>
#include <fstream>

#include "Kreslic.h"
#include "hrac.h"
#include "Nepriatel.h"
#include "Lokacia.h"

#include "Zbran.h"

///tato trieda sa stara o vykreslovanie obrazkovky pri boji

class Kboj : public Kreslic
    {
    private:
        Lokacia* m_lokacia; ///ukazatel na lokaciu ktora sa prave pouziva
        Hrac* m_hrac; ///ukazatel na hraca
    public:
        Kboj(Lokacia* lok, Hrac* hrac); ///parametricky konstruktor ktori ulozi udaje z paramtrov do atributov
        void Kresli(); ///metoda ktora sa stara o samtoen vykreslovanie
        Nepriatel* najdi(); ///pomocna metoda ktora hlada v blizkom okolo hraca nepriatela
    };

#endif // KBOJ_H
