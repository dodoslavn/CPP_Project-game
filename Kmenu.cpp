#include "Kmenu.h"

Kmenu::Kmenu()
    {
    m_polozky.push_back("ESC - Koniec");
    m_polozky.push_back("V - Nacitaj");
    m_polozky.push_back("C - Uloz");
    m_polozky.push_back("X - Hraj");
    }

void Kmenu::Kresli()
    {
    for (int i = 0; i < m_polozky.size(); i++)
        { Text(m_polozky.at(i), Pozicia(10,200+20*i), Farba(0,100,100) ); }
    }
