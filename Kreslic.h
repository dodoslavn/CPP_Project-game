#ifndef kreslic_
#define kreslic_

#include <iostream>
#include "GL/glut.h"
#include <cstdlib>
#include "GL/gl.h"

#include <GL/freeglut.h>

#include "Pozicia.h"
#include "Farba.h"
#include "Lokacia.h"
#include "hrac.h"

///hlavna metoda ktora sa stara o vykreslovanie

class Kreslic
    {
    protected:
            int m_velkost, pom ; ///premenna ktora sa zadefinuje v konstruktore ktora urcuje velkost vsetko co sa vykresluje a pomocna premenna pom ktora sa pouziva vsade
            Lokacia* m_lokacia; ///premenna typu ukazatel an objekt triedy Lokacia ktora sa prave pouziva
            Lokacia* m_mapa; ///premenna typu ukazatel an objekt triedy Lokacia ktora sa prave pouziva
            std::vector<std::string> m_polozky; ///vektor strungov ktore obsahuju polozky pre vykreslenie legendy

            void Kruh(); ///metoda ktora sa stara o vykreslenie kruhu
            void Stvorec(Pozicia prva, Pozicia druha, Farba farb); ///metoda ktora sa stara o vykreslenie stvorca
            void Text(std::string text, Pozicia poz, Farba farb); ///metoda ktora sa stara o vykreslenie textu
    public:
            Kreslic(); ///bezparametrcky konstruktor
            void resize(int w, int h); ///metoda ktora riesi zmenu velkosti ukna
            void display(); ///metoda ktora sa stara o vykreslenie toho co sa prave zapisalo an vykreslenie
            virtual void Kresli() = 0; ///abstraktna metoda ktora sluzi na vykreslenie toho daneho prostredia
            void pis(std::string); ///pomozna metoda ktora vypise text 
    };


#endif
