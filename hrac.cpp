#include "hrac.h"

Hrac::Hrac()
    {
    m_brnenie = new Brnenie("Plast",10);
    m_zbran = new Zbran("Mec",20);
    m_zivot = 100;
    m_pozicia = Pozicia(0,0);
    }
Pozicia Hrac::getPozicia()
    {
    return m_pozicia;
    }
void Hrac::setPozicia(Pozicia poz)
    {
    m_pozicia.x = poz.x;
    m_pozicia.y = poz.y;
    }

Zbran* Hrac::getZbran()
     { return m_zbran; }

Brnenie* Hrac::getBrnenie()
     { return m_brnenie; }

int Hrac::getZivot()
     { return m_zivot; }


void Hrac::pridaj(Brnenie* brn)
    {
    if (brn->getSila() > m_brnenie->getSila() )
        { m_brnenie = brn; }
    m_inventar.push_back(brn);
    }

void Hrac::pridaj(Zbran* zbr)
    {
    if (zbr->getSila() > m_zbran->getSila() )
        { m_zbran = zbr; }
    m_inventar.push_back(zbr);
    }

std::vector<Predmet* > Hrac::getInventar()
    { return m_inventar;}
