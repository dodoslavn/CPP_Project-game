
#include "mainwindow.h"

#include "GL/glut.h"
#include <cstdlib>
#include "GL/gl.h"
#include "engine.h"

Engine g_enjin;

void onResize(int w, int h)
    { g_enjin.resize(w,h); }

void onDisplay()
    { g_enjin.display(); }

void onKeyboard(unsigned char key, int x, int y)
    { g_enjin.klavesnica(key); }

int main(int argc, char *argv[])
    {

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Projekt CPP");
    glutDisplayFunc(onDisplay);
    glutReshapeFunc(onResize);
    glutKeyboardFunc(onKeyboard);
    glutMainLoop();

    return 0;
    }


