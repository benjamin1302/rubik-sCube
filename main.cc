//
// Created by bdelbreuve on 28/05/18.


#include <iostream>
#include "Cube.cc"
#include "Piece.cc"

#include <GL/gl.h>
#include <GL/glut.h>

#import "affichage.cpp"


// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){

    //  Initialize GLUT and process user parameters
    glutInit(&argc,argv);
    //  Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Create window
    glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
    glutCreateWindow("test Cube");

    //  Enable Z-buffer depth test
    glEnable(GL_DEPTH_TEST);

    // Callback functions
    glutDisplayFunc(drawCube);
    glInit();
    glutSpecialFunc(specialKeys);

    //  Pass control to GLUT for events
    glutMainLoop();

    //  Return to OS

    return 0;

}