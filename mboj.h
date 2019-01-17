#ifndef MBOJ_H
#define MBOJ_H

#include "Mechanika.h"
#include "hrac.h"
#include "Nepriatel.h"
#include "Lokacia.h"
#include "Pozicia.h"

///trieda ktora sa stara o mechaniku boja

class Mboj : public Mechanika
    {
    private:
        Hrac* m_hrac; ///premenna osbahujuca uakzatel na hraca
        Lokacia* m_lokacia; ///premenna obsahujuca uakzatel na lokaciu ktora sa prave pouziva
    public:
        Mboj(Lokacia* lok, Hrac* hrac); /// parametricky konstruktor
        int klavesa(char key); ///metoda ktora sa vola z Enginu pre spracovanie stlacenej klavesy
        bool suboj(); ///metoda ktora sa stara o samotny suboj
    };

#endif // MBOJ_H
