#ifndef mechanikam_
#define mechanikam_

#include <iostream>
#include <cstdlib>

#include "Mechanika.h"


#include "Kreslic.h"
#include "Kpole.h"
#include "Kmenu.h"
#include "Kinventar.h"

///trieda ktora sa stara o mechaniku hlavneho menu

class Mmenu : public Mechanika
    {
    public:
        Mmenu(); ///konstruktor
        int klavesa(char key); ///metoda ktora sa stara o spracovanie klavesy ktora sa stlacila
        void dole(); ///metoda ktora sa stara o posun hore
        void hore(); ///metoda ktora sa stara o posun dole
        void potvrd(); ///metoda ktora sa stara o potvrdenie
    };


#endif
