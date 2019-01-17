#ifndef poz_h
#define poz_h

///struct definujuci poziciu

struct Pozicia
    {
    int x;
    int y;

    Pozicia(const int x, const int y)
        {
        this->x = x;
        this->y = y;
        }

    Pozicia()
        {
        this->x = 0;
        this->y = 0;
        }

    };
#endif
