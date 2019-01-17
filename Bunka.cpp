#include "Bunka.h"



Bunka::Bunka(bool tma)
    {
    m_nepriatel = NULL;
    m_brnenie = NULL;
    m_zbran = NULL;
    m_volno = false;
    m_tma = tma;
    m_portal = false;
    }


void Bunka::Vloz(Nepriatel* nep)
    {
    m_nepriatel = nep;
    }

Nepriatel* Bunka::getNepriatel()
    { return m_nepriatel; }

Brnenie* Bunka::getBrnenie()
    { return m_brnenie; }

Zbran* Bunka::getZbran()
    { return m_zbran; }

void Bunka::Vloz(Brnenie* brn)
    { m_brnenie = brn;}

void Bunka::Vloz(Zbran* zbran)
    { m_zbran = zbran; }

void Bunka::Vloz(bool volno)
    { m_volno = volno; }

bool Bunka::getVolno()
    { return m_volno; }

void Bunka::setTma(bool tma)
    { m_tma = tma; }

bool Bunka::getTma()
    { return m_tma; }

void Bunka::setPortal(bool portal)
    { m_portal = portal; }

bool Bunka::getPortal()
    { return m_portal; }
