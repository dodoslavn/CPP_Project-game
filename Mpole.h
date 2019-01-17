#ifndef mechanikap_
#define mechanikap_

#include "Mechanika.h"
#include "Lokacia.h"
#include "hrac.h"
#include "Pozicia.h"
#include "Nepriatel.h"

#include "Kreslic.h"
#include "Kpole.h"
#include "Kmenu.h"
#include "Kinventar.h"

///trieda ktora sa stara o mechaniku herenho pola

class Mpole : public Mechanika
    {
    private:
        Hrac* m_hrac; ///premenna obsahujuca uakzatel na hraca
        Lokacia* m_mapa; ///premenna obsahujuca ukazatel na lokaciu ktora sa pouziva
        int m_clokacia; ///premenna ktora urcuje ktora lokacia sa pouziva 
        void hore(); ///metoda ktora spracuva posun hraca nahor
        void dole(); ///metoda ktora spracuva posun hraca nadol
        void vpravo(); ///metoda ktora spracuva posun hraca vrpavo
        void vlavo(); ///metoda ktora spracuva posun rhaca vlavo
    public:
        Mpole(Lokacia* lok, Hrac* hrac, int clokacia); ///pamatetricky konstruktor
        int klavesa(char key); ///metoda ktora spracuva 
        bool boj(); ///metoda ktora hlada vokoli hraca nepraitela
        void objav(); ///metoda ktora odkryva okolie od tmy
        void zdvihni(); ///metoda ktora vezme predmet z lokacie
        bool postup(); ///
    };


#endif
