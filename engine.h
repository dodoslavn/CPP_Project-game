#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "hrac.h"
#include "Pozicia.h"
#include "Farba.h"
#include "Lokacia.h"
#include "Nepriatel.h"

#include "Kreslic.h"
#include "Kpole.h"
#include "Kmenu.h"
#include "Kinventar.h"
#include "kboj.h"

#include "Mechanika.h"
#include "Mpole.h"
#include "Mmenu.h"
#include "Minventar.h"
#include "mboj.h"

#include "Predmet.h"
#include "Zbran.h"
#include "Brnenie.h"


class Engine
    {
    private:
        void zmena(int x);
        void lokacie();
        void prepni(int x);
        Hrac* m_hrac;
        Kreslic* m_kreslic;
        Mechanika* m_mechanika;
        std::vector<Lokacia* > m_lokacie;
        int m_cisloLokacie;
        std::vector<std::string > zoznam;
    public:
        Engine();
        void klavesnica(char key);
        void resize(int w, int h);
        void display();
    };

#endif // ENGINE_H
