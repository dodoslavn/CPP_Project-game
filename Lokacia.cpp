#include "Lokacia.h"

Lokacia::Lokacia()
        {
        std::vector<Bunka*> pom;
        pom.resize(10,NULL);
        for(int i = 0; i < 10; i++)
            { m_matica.push_back(pom); }

        for(int x = 0; x < 10; x++)
            {
            for(int y = 0; y < 10; y++)
                { m_matica.at(x).at(y) = new Bunka(false); }
            }
        }

Bunka* Lokacia::getBunka(int x, int y)
        { return m_matica.at(x).at(y); }

void Lokacia::setFarba(bool f)
    { m_farba = f; }

bool Lokacia::getFarba()
    { return m_farba; }
