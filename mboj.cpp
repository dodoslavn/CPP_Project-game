#include "mboj.h"

Mboj::Mboj(Lokacia* lok, Hrac* hrac)
    {
    m_hrac = hrac;
    m_lokacia = lok;
    }


int Mboj::klavesa(char key)
    {
    int ret = 0;
    switch (key)
        {
        case 27:
            std::exit(0);
            break;
        case 'x':
            if ( suboj() ) ret = 2;
            else { ret = 1; }
            break;
        case 'c':
            ret = 2;
            break;
        default:
            break;
        }
    return ret;
    }

bool Mboj::suboj()
    {
    Pozicia hpoz = m_hrac->getPozicia();
    Nepriatel* nepr = NULL;
    int x,y;
    if (m_lokacia->getBunka(hpoz.x+1,hpoz.y)->getNepriatel() != NULL)
        { nepr = m_lokacia->getBunka(hpoz.x+1,hpoz.y)->getNepriatel(); x=hpoz.x+1; y=hpoz.y;  }
    if (m_lokacia->getBunka(hpoz.x-1,hpoz.y)->getNepriatel() != NULL)
        { nepr = m_lokacia->getBunka(hpoz.x+1,hpoz.y)->getNepriatel(); x=hpoz.x-1; y=hpoz.y;  }
    if (m_lokacia->getBunka(hpoz.x,hpoz.y+1)->getNepriatel() != NULL)
        { nepr = m_lokacia->getBunka(hpoz.x,hpoz.y+1)->getNepriatel(); x=hpoz.x; y=hpoz.y+1;  }
    if (m_lokacia->getBunka(hpoz.x,hpoz.y-1)->getNepriatel() != NULL)
        { nepr = m_lokacia->getBunka(hpoz.x,hpoz.y-1)->getNepriatel(); x=hpoz.x; y=hpoz.y-1;  }
    if (nepr != NULL)
        {
        int hzivot = m_hrac->getZivot();
        while(hzivot > 0 && nepr->getZivot() > 0)
            {
            hzivot = hzivot - nepr->getUtok() + m_hrac->getBrnenie()->getSila();
            nepr->setZivot( nepr->getZivot() - m_hrac->getZbran()->getSila() );
            }
        if (hzivot < 0) { return false; }
        else { nepr->setZivot(100); nepr = NULL; m_lokacia->getBunka(x,y)->Vloz(nepr); return true; }
        }
    }
