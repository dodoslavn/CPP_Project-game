#ifndef mechanika_
#define mechanika_

#include "Pozicia.h"
#include "hrac.h"

#include "Kreslic.h"
#include "Kpole.h"
#include "Kmenu.h"
#include "Kinventar.h"

///treida ktora sa stara o celu mechaniku hry

class Mechanika
    {
    private:
        Kreslic* m_kreslic; ///premenna obsahujuca ukazatel an kreslic
    public:
        Mechanika(); //konstrutkor
        virtual int klavesa(char key) = 0;  ///abstarktna metoda ktora sa stara o spracovanie stlacenia klavesy
    };


#endif
