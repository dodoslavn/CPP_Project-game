#ifndef predmet_h
#define predmet_h

#include <iostream>

class Predmet
    {
    protected:
        std::string m_nazov; ///nazov predmetu (brnenia alebo zbrane)
		int m_sila; ///sila predmetu (brnenie alebo zbran)
    public:
		Predmet(); ///konstruktor ktori sa nikdy nepouzije
        std::string getNazov(); ///metoda vracia atribut m_nazov 
        int getSila(); ///metoda vracia atribut m_sila
    };


#endif
