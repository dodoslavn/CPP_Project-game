#include "Kinventar.h"

Kinventar::Kinventar(Hrac* hrac)
    {
    m_hrac = hrac;
    m_polozky.push_back("X - Zavriet");
    }

void Kinventar::Kresli()
    {
    for (int i = 0; i < m_polozky.size(); i++)
        { Text(m_polozky.at(i), Pozicia(10,200+20*i), Farba(0,100,100) ); }

    Text("Zbran: " + m_hrac->getZbran()->getNazov(), Pozicia(10,250), Farba(0,100,100) );
    Text("Brnenie: " + m_hrac->getBrnenie()->getNazov(), Pozicia(10,250+20), Farba(0,100,100) );


    std::vector<Predmet* > invent = m_hrac->getInventar();
    for ( int i = 0; i < invent.size(); i++)
        { Text(invent.at(i)->getNazov(), Pozicia(200,150+20*i), Farba(0,100,100) ); }

    }
