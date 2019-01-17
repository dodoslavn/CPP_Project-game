#ifndef kreslici_
#define kreslici_

#include "Kreslic.h"

#include "hrac.h"

///tato trieda sa stara o vykreslovanie inventara

class Kinventar : public Kreslic
    {
    private:
        Hrac* m_hrac; ///tato premenna obsahuje ukazatel an hraca ktoreho inventar sa ma vykreslit
    public:
        Kinventar(Hrac* hrac); ///parametricky konstruktor ktori ulozit ukazatel na hraca
        void Kresli(); ///metoda ktora sa stara o samotne vykreslovanie inventara
    };


#endif
