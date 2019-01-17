#ifndef kreslicm_
#define kreslicm_

#include "Kreslic.h"
#include <iostream>
#include <vector>

///trieda ktora sa stara o vykreslenie menu

class Kmenu : public Kreslic
    {
    public:
        Kmenu(); ///bezparametricky konstruktor
        void Kresli(); ///metoda ktora sluzi na vykreslenie menu
    };



#endif
