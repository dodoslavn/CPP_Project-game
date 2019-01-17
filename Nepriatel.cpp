#include "Nepriatel.h"

Nepriatel::Nepriatel(std::string meno, int utok, int obrana)
    {
    m_meno = meno;
    m_utok = utok;
    m_obrana = obrana;
    m_zivot = 100;
    }

Nepriatel::Nepriatel(const Nepriatel& vzor)
    {
    m_meno = vzor.m_meno;
    m_utok = vzor.m_utok;
    m_obrana = vzor.m_obrana;
    m_zivot = vzor.m_zivot;
    }

int Nepriatel::getUtok()
    { return m_utok; }

int Nepriatel::getObrana()
    { return m_obrana; }

int Nepriatel::getZivot()
    { return m_zivot; }

std::string Nepriatel::getMeno()
    { return m_meno; }

void Nepriatel::setZivot(int zivot)
    { m_zivot = zivot; }
