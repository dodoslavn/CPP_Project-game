#include "Kpole.h"

Kpole::Kpole(Lokacia* lokacia, Hrac* hrac)
    {
    m_lokacia = lokacia;
    m_hrac = hrac;

    m_polozky.push_back("ESC - Koniec");
    m_polozky.push_back("V - Zdvihni");
    m_polozky.push_back("B - Inventar");
    m_polozky.push_back("C - Suboj");
    m_polozky.push_back("M - Menu");
    m_polozky.push_back("A - Vlavo");
    m_polozky.push_back("D - Vpravo");
    m_polozky.push_back("S - Dole");
    m_polozky.push_back("W - Hore");
    }

void Kpole::Kresli()
    {
    int odsadenie = 200;
    int velkostKocky = 50;

    for (int i = 0; i < m_polozky.size(); i++)
        { Text(m_polozky.at(i), Pozicia(10,200+20*i), Farba(0,100,100) ); }

    for(int x = 0; x < 10; x++)
        {
        for(int y = 0; y < 10; y++)
            {
            if ( m_lokacia->getBunka(x,y)->getTma() )
                { Nic(Pozicia(velkostKocky*x+odsadenie,velkostKocky*y),Pozicia(velkostKocky+velkostKocky*x+odsadenie,velkostKocky+velkostKocky*y));}
            else
                {
                if ( m_lokacia->getBunka(x,y)->getVolno() )
                    {
                    Cesta(Pozicia(velkostKocky*x+odsadenie,velkostKocky*y),Pozicia(velkostKocky+velkostKocky*x+odsadenie,velkostKocky+velkostKocky*y));
                    if ( m_lokacia->getBunka(x,y)->getNepriatel() != NULL )
                        { Nepriatela(Pozicia(x*velkostKocky+(velkostKocky/2)+odsadenie,y*velkostKocky+(velkostKocky/2))); }
                    else if ( m_lokacia->getBunka(x,y)->getBrnenie() != NULL )
                        { Brnenie(Pozicia(x*velkostKocky+(velkostKocky/2)+odsadenie,y*velkostKocky+(velkostKocky/2))); }
                    else if ( m_lokacia->getBunka(x,y)->getZbran() != NULL )
                        { Zbran(Pozicia(x*velkostKocky+(velkostKocky/2)+odsadenie,y*velkostKocky+(velkostKocky/2))); }
                    else if ( m_lokacia->getBunka(x,y)->getPortal() )
                        { portal(Pozicia(x*velkostKocky+(velkostKocky/2)+odsadenie,y*velkostKocky+(velkostKocky/2))); }
                    }
                else
                    { Stena(Pozicia(velkostKocky*x+odsadenie,velkostKocky*y),Pozicia(velkostKocky+velkostKocky*x+odsadenie,velkostKocky+velkostKocky*y));}
                }
            }
        }
    Hraca(Pozicia(m_hrac->getPozicia().x*velkostKocky+(velkostKocky/2)+odsadenie,m_hrac->getPozicia().y*velkostKocky+(velkostKocky/2)));
    }

void Kpole::Hraca(Pozicia poz)
    {
    Stvorec(Pozicia(poz.x+10,poz.y+10),Pozicia(poz.x-10,poz.y-10),Farba(50,100,100));
    }

void Kpole::Nepriatela(Pozicia poz)
    { Stvorec(Pozicia(poz.x+10,poz.y+10),Pozicia(poz.x-10,poz.y-10),Farba(120,0,0)); }

void Kpole::Brnenie(Pozicia poz)
    { Stvorec(Pozicia(poz.x+10,poz.y+10),Pozicia(poz.x-10,poz.y-10),Farba(0,120,0)); }

void Kpole::Zbran(Pozicia poz)
    { Stvorec(Pozicia(poz.x+10,poz.y+10),Pozicia(poz.x-10,poz.y-10),Farba(0,0,120)); }

void Kpole::Nic(Pozicia prva, Pozicia druha)
    { Stvorec(Pozicia(prva.x,prva.y),Pozicia(druha.x,druha.y),Farba(0,0,0)); }

void Kpole::Cesta(Pozicia prva, Pozicia druha)
{
    if (m_lokacia->getFarba()) {Stvorec(Pozicia(prva.x,prva.y),Pozicia(druha.x,druha.y),Farba(100,127,127)); }
    else {Stvorec(Pozicia(prva.x,prva.y),Pozicia(druha.x,druha.y),Farba(127,127,127)); }
}

void Kpole::portal(Pozicia poz)
    { Stvorec(Pozicia(poz.x+10,poz.y+10),Pozicia(poz.x-10,poz.y-10),Farba(100,100,0)); }

void Kpole::Stena(Pozicia prva, Pozicia druha)
    {
    int medzera = 5;
    if (m_lokacia->getFarba())
        {
        Stvorec(Pozicia(prva.x,prva.y),Pozicia(druha.x,druha.y),Farba(20,50,50)); //okraj
        Stvorec(Pozicia(prva.x+medzera,prva.y+medzera),Pozicia(druha.x-medzera,druha.y-medzera),Farba(70,70,70));
        }
    else
        {
        Stvorec(Pozicia(prva.x,prva.y),Pozicia(druha.x,druha.y),Farba(50,70,70)); //okraj
        Stvorec(Pozicia(prva.x+medzera,prva.y+medzera),Pozicia(druha.x-medzera,druha.y-medzera),Farba(70,70,70));
        }
    }

