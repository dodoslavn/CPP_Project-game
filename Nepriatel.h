#ifndef nepr_h
#define nepr_h

#include <iostream>

///trieda ktora definu nepriatela

class Nepriatel
    {
    private:
        std::string m_meno; ///meno nepriatela
		int m_utok; ///sila nepraitela
		int m_obrana; ///obraan nepraitela
        int m_zivot; ///velkost zivota nepriatela
    public:
        Nepriatel(std::string meno, int utok, int obrana); ///parametrcky konstruktor
		int getUtok(); ///metoda ktora vrati utok nepraitela
		int getObrana(); ///metoda ktora vracia obranu
        int getZivot(); ///metoda ktora varcia zivot
        std::string getMeno(); ///metoda ktora vracia meno nepriatela
        void setZivot(int zivot); ///metoda ktora upravuje zivot 
        Nepriatel(const Nepriatel& vzor); ///kopirovaci konstruktor
    };


#endif
