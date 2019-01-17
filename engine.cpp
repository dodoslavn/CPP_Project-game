#include "engine.h"

Engine::Engine()
    {
    m_cisloLokacie = 0;
    lokacie();

    m_hrac = new Hrac();
    m_kreslic = new Kmenu();
    m_mechanika = new Mmenu();
    }

void Engine::klavesnica(char key)
    {
    int x = m_mechanika->klavesa(key);
    if (x != 0) { zmena(x); }
    m_kreslic->Kresli();
    glutSwapBuffers();
    }

void Engine::resize(int w, int h)
    { m_kreslic->resize(w,h); }

void Engine::display()
    { m_kreslic->display(); }

void Engine::zmena(int x)
    {
    switch (x)
        {
        case 1:
            prepni(1);
            break;
        case 2:
            prepni(2);
            break;
        case 3:
            prepni(3);
            break;
        case 4:
            prepni(4);
            break;
        case 5:
            prepni(5);
            break;
        default:
            break;
        }
    }

void Engine::lokacie()
    {
    std::ifstream subor1, subor2;
    std::string mapa, bunka, pom, nepMeno, nepSila, nepObr;
    std::vector<Nepriatel*> nepr;
    std::vector<Zbran*> zbra;
    std::vector<Brnenie*> brn;
    bool farba, tma;
    int c = 0;



    subor1.open( "conf/p.txt" );
    for (int i = 0; i < 5; i++)
            {
            subor1 >> nepObr;
            subor1 >> nepSila;
            subor1 >> nepMeno;
            nepr.push_back(new Nepriatel(nepMeno,atoi(nepSila.c_str()),atoi(nepObr.c_str())));
            }
    subor1.close();

    subor1.open( "conf/z.txt" ); c = 0;
    for (int i = 0; i < 2; i++)
            {
            subor1 >> nepSila;
            subor1 >> nepMeno;
            zbra.push_back(new Zbran(nepMeno,atoi(nepSila.c_str())));
            }
    subor1.close();

    subor1.open( "conf/b.txt" ); c = 0;
    for (int i = 0; i < 2; i++)
            {
            subor1 >> nepSila;
            subor1 >> nepMeno;
            brn.push_back(new Brnenie(nepMeno,atoi(nepSila.c_str())));
            }
    subor1.close();

    for (int i = 0; i < 10; i++)
        {  m_lokacie.push_back( new Lokacia() ); }



    subor1.open("conf/mapy.txt");
    for (int i = 0; i < 2; i++)
        {
        subor1 >> mapa;
        if (subor2.is_open()) {subor2.close();}
        subor2.open( mapa.c_str() );

        subor2 >> pom; if (pom != "0") { tma = true; }
        subor2 >> pom; if (pom != "0") { m_lokacie.at(i)->setFarba(true); }
        for (int y = 9; y >= 0; y--)
            {
            for (int x = 0; x < 10; x++)
                {
                subor2 >> bunka;
                m_lokacie.at(i)->getBunka(x,y)->setTma(tma);
                if (bunka != "9")
                    {
                    m_lokacie.at(i)->getBunka(x,y)->Vloz(true);
                    if ( atoi(bunka.c_str()) < 5 )
                        {  m_lokacie.at(i)->getBunka(x,y)->Vloz(nepr.at(atoi(bunka.c_str() )));}
                    if ( atoi(bunka.c_str()) < 15 && atoi(bunka.c_str() ) > 10 )
                        {  m_lokacie.at(i)->getBunka(x,y)->Vloz(brn.at(atoi(bunka.c_str() -10 )));}
                    if ( atoi(bunka.c_str()) > 20 && atoi(bunka.c_str() ) < 50 )
                        {  m_lokacie.at(i)->getBunka(x,y)->Vloz(zbra.at(atoi(bunka.c_str() ) -20));}
                    if ( bunka == "7"  )
                        {  m_lokacie.at(i)->getBunka(x,y)->setPortal(true);}
                    }
                }
            }
        }
    }

void Engine::prepni(int x)
    {
    if (m_kreslic != NULL) { delete m_kreslic; }
    if (m_mechanika != NULL) { delete m_mechanika; }
    switch (x)
        {
        case 1:
            m_kreslic = new Kmenu();
            m_mechanika = new Mmenu();
            break;
        case 2:
            m_kreslic = new Kpole(m_lokacie.at(m_cisloLokacie), m_hrac);
            m_mechanika = new Mpole(m_lokacie.at(m_cisloLokacie), m_hrac, m_cisloLokacie);
            break;
        case 3:
            m_kreslic = new Kinventar(m_hrac);
            m_mechanika = new Minventar();
            break;
        case 4:
            m_kreslic = new Kboj(m_lokacie.at(m_cisloLokacie), m_hrac);
            m_mechanika = new Mboj(m_lokacie.at(m_cisloLokacie), m_hrac);
            break;
        case 5:
            m_cisloLokacie++;
            m_kreslic = new Kpole(m_lokacie.at(m_cisloLokacie), m_hrac);
            m_mechanika = new Mpole(m_lokacie.at(m_cisloLokacie), m_hrac,m_cisloLokacie);
            m_hrac->setPozicia(Pozicia(0,0));
            break;
        default:
            break;
        }
    display();
    }
