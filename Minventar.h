#ifndef mechanikai_
#define mechanikai_

#include "Mechanika.h"

///trieda ktora sa stara o pracu s inventarom

class Minventar : public Mechanika
    {
    public:
        Minventar(); ///konstruktor
        int klavesa(char key); ///metoda ktora sa stara o spracovanie klavesy ked je zobrazeny inventar
    };


#endif
