#include "Mpole.h"

Mpole::Mpole(Lokacia* lok, Hrac* hrac, int clokacia)
    {
    m_mapa = lok;
    m_hrac = hrac;
    m_clokacia = clokacia;
    }

int Mpole::klavesa(char key)
    {
    int ret = 0;
    switch (key)
        {
        case 27:
            std::exit(0);
            break;
        case 'w':
            hore();
            break;
        case 's':
            dole();
            break;
        case 'a':
            vlavo();
            break;
        case 'd':
            vpravo();
            break;
        case 'm':
            ret = 1;
            break;
        case 'v':
            zdvihni();
            break;
        case 'b':
            ret = 3;
            break;
        case 'c':
            if(boj()) {ret = 4; }
            break;
        default:
            break;
        }
    objav();
    if (postup() ) { ret = 5; }
    return ret;
    }

void Mpole::hore()
    {

    Pozicia hpoz = m_hrac->getPozicia();
    if (hpoz.y < 9 && m_mapa->getBunka(hpoz.x,hpoz.y+1)->getNepriatel() == NULL ) //hore
        {
        Bunka* bun = m_mapa->getBunka(hpoz.x,hpoz.y+1);
        if (bun->getVolno() )
            { m_hrac->setPozicia( Pozicia(hpoz.x,hpoz.y+1)); }
        }
    }

void Mpole::dole()
    {
    Pozicia hpoz = m_hrac->getPozicia();
    if(hpoz.y > 0 && m_mapa->getBunka(hpoz.x,hpoz.y-1)->getNepriatel() == NULL) //dole
            {
            Bunka* bun = m_mapa->getBunka(hpoz.x,hpoz.y-1);
            if (bun->getVolno() )
                { m_hrac->setPozicia( Pozicia(hpoz.x,hpoz.y-1)); }
            }
    }

void Mpole::vpravo()
    {
    Pozicia hpoz = m_hrac->getPozicia();
    if(hpoz.x < 9 && m_mapa->getBunka(hpoz.x+1,hpoz.y)->getNepriatel() == NULL) //vpravo
            {
            Bunka* bun = m_mapa->getBunka(hpoz.x+1,hpoz.y);
            if (bun->getVolno() )
                { m_hrac->setPozicia( Pozicia(hpoz.x+1,hpoz.y)); }
        }
    }

void Mpole::vlavo()
    {
    Pozicia hpoz = m_hrac->getPozicia();
    if(hpoz.x > 0 && m_mapa->getBunka(hpoz.x-1,hpoz.y)->getNepriatel() == NULL) //vlavo
            {
            Bunka* bun = m_mapa->getBunka(hpoz.x-1,hpoz.y);
            if (bun->getVolno() )
                { m_hrac->setPozicia( Pozicia(hpoz.x-1,hpoz.y)); }
            }
    }

bool Mpole::boj()
    {
    bool retb = false;
    Pozicia hpoz = m_hrac->getPozicia();
    if (hpoz.x > 0) { if ( m_mapa->getBunka(hpoz.x-1,hpoz.y)->getNepriatel() != NULL ) { retb = true; } }
    if (hpoz.y > 0) { if ( m_mapa->getBunka(hpoz.x,hpoz.y-1)->getNepriatel() != NULL ) { retb = true; } }
    if (hpoz.x < 9) { if ( m_mapa->getBunka(hpoz.x+1,hpoz.y)->getNepriatel() != NULL ) { retb = true; } }
    if (hpoz.y < 9) { if ( m_mapa->getBunka(hpoz.x,hpoz.y+1)->getNepriatel() != NULL ) { retb = true; } }

    return retb;
    }

void Mpole::objav()
    {
    m_mapa->getBunka(m_hrac->getPozicia().x,m_hrac->getPozicia().y)->setTma(false);

    if( m_hrac->getPozicia().x < 9 ) {m_mapa->getBunka(m_hrac->getPozicia().x+1,m_hrac->getPozicia().y)->setTma(false); }
    if( m_hrac->getPozicia().x > 0 ) {m_mapa->getBunka(m_hrac->getPozicia().x-1,m_hrac->getPozicia().y)->setTma(false); }
    if( m_hrac->getPozicia().y < 9 ) {m_mapa->getBunka(m_hrac->getPozicia().x,m_hrac->getPozicia().y+1)->setTma(false); }
    if( m_hrac->getPozicia().y > 0 ) {m_mapa->getBunka(m_hrac->getPozicia().x,m_hrac->getPozicia().y-1)->setTma(false); }
    if( m_hrac->getPozicia().x < 9 && m_hrac->getPozicia().y < 9 ) {m_mapa->getBunka(m_hrac->getPozicia().x+1,m_hrac->getPozicia().y+1)->setTma(false); }
    if( m_hrac->getPozicia().x > 0 && m_hrac->getPozicia().y > 0 ) {m_mapa->getBunka(m_hrac->getPozicia().x-1,m_hrac->getPozicia().y-1)->setTma(false); }
    if( m_hrac->getPozicia().x < 9 && m_hrac->getPozicia().y > 0 ) {m_mapa->getBunka(m_hrac->getPozicia().x+1,m_hrac->getPozicia().y-1)->setTma(false); }
    if( m_hrac->getPozicia().x > 0 && m_hrac->getPozicia().y < 9 ) {m_mapa->getBunka(m_hrac->getPozicia().x-1,m_hrac->getPozicia().y+1)->setTma(false); }

    }

void Mpole::zdvihni()
    {
    Pozicia hpoz = m_hrac->getPozicia();
    if (m_mapa->getBunka(hpoz.x,hpoz.y)->getBrnenie() != NULL )
        {
        m_hrac->pridaj(m_mapa->getBunka(hpoz.x,hpoz.y)->getBrnenie());
        Brnenie* br = NULL;
        m_mapa->getBunka(hpoz.x,hpoz.y)->Vloz(br);
        }
    if (m_mapa->getBunka(hpoz.x,hpoz.y)->getZbran() != NULL )
        {
        m_hrac->pridaj(m_mapa->getBunka(hpoz.x,hpoz.y)->getZbran());
        Zbran* br = NULL;
        m_mapa->getBunka(hpoz.x,hpoz.y)->Vloz(br);
        }
    }

bool Mpole::postup()
    {
    Pozicia hpoz = m_hrac->getPozicia();
    if ( m_mapa->getBunka(hpoz.x,hpoz.y)->getPortal() )
        {
        std::vector<Predmet* > inv = m_hrac->getInventar();
        if ( inv.size() > m_clokacia ) { return true; }
        else {return false;}
        }

    }
