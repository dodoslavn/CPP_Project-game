#include "Kreslic.h"

Kreslic::Kreslic()
    {

    }

void Kreslic::pis(std::string text)
    {
    m_polozky.push_back(text);
    }


void Kreslic::resize(int w, int h)
    {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1, 1);
    }

void Kreslic::display()
    {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    }


//#######################################################


void Kreslic::Kruh()
    {}

void Kreslic::Stvorec(Pozicia prva, Pozicia druha, Farba farb)
    {
    glColor3b(farb.r,farb.g,farb.b);
    glBegin(GL_TRIANGLE_STRIP);
     glVertex2f(prva.x,prva.y);
     glVertex2f(druha.x,prva.y);
     glVertex2f(prva.x,druha.y);
     glVertex2f(druha.x,druha.y);
    glEnd();
    }

void Kreslic::Text(std::string text, Pozicia poz, Farba farb)
    {
    glColor3f(farb.r,farb.g,farb.b);
    glRasterPos2f(poz.x, poz.y);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text.c_str() );
    }
