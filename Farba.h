#ifndef FARBA_H
#define FARBA_H

#include "GL/gl.h"

///struct ktori sluzi na pracu s farbamy pri vykreslovani

struct Farba{ 
    GLbyte r;
    GLbyte g;
    GLbyte b;

    Farba(const GLbyte r, const GLbyte g, const GLbyte b){
        this->r = r;
        this->g = g;
        this->b = b;
    }

    Farba(){
        this->r = 0;
        this->g = 0;
        this->b = 0;
    }

};



#endif // FARBA_H
