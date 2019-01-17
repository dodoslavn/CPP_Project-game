#ifndef zbran_h
#define zbran_h

#include <iostream>

#include "Predmet.h"

class Zbran : public Predmet
    {
    public:
        Zbran(std::string nazov, int sila); //jediny konstruktor pre objekt tiery Zbran, s parametramy nazov a sila zbrane
    };

#endif
