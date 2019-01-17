#include "kboj.h"

Kboj::Kboj(Lokacia* lok, Hrac* hrac)
    {
    m_lokacia = lok;
    m_hrac= hrac;
    }

void Kboj::Kresli()
    {
    if ( najdi() != NULL)
        {
        Nepriatel* nep = najdi();
        Text("Hrac", Pozicia(200,200), Farba(0,100,100) );
        Text("Zbran: " + m_hrac->getZbran()->getNazov(), Pozicia(200,200-25), Farba(0,100,100) );
        Text("Brnenie: " + m_hrac->getBrnenie()->getNazov(), Pozicia(200,200-50), Farba(0,100,100) );
        Text("Zivot: " + m_hrac->getZivot(), Pozicia(200,200-75), Farba(0,100,100) );

        Text("Nepriatel ", Pozicia(500,200), Farba(0,100,100) );
        Text( nep->getMeno(), Pozicia(500,200-25), Farba(0,100,100) );

        Text("X - Zautoc ", Pozicia(10,200), Farba(0,100,100) );
        Text("C - Utec", Pozicia(10,200-25), Farba(0,100,100) );
        }

    }

Nepriatel* Kboj::najdi()
    {
    Pozicia hpoz = m_hrac->getPozicia();
    if (m_lokacia->getBunka(hpoz.x+1,hpoz.y)->getNepriatel() != NULL)
        { return m_lokacia->getBunka(hpoz.x+1,hpoz.y)->getNepriatel(); }
    if (m_lokacia->getBunka(hpoz.x-1,hpoz.y)->getNepriatel() != NULL)
        { return m_lokacia->getBunka(hpoz.x-1,hpoz.y)->getNepriatel(); }
    if (m_lokacia->getBunka(hpoz.x,hpoz.y+1)->getNepriatel() != NULL)
        { return m_lokacia->getBunka(hpoz.x,hpoz.y+1)->getNepriatel(); }
    if (m_lokacia->getBunka(hpoz.x,hpoz.y-1)->getNepriatel() != NULL)
        { return m_lokacia->getBunka(hpoz.x,hpoz.y-1)->getNepriatel(); }
    return NULL;
    }

