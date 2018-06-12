#include <GL/gl.h>
#include <GL/glut.h>
#import "Cube.cc"



// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

Cube cube;


void associateColor(int couleur)
{
    glClearColor(0.0,0.0,0.0,0.0);

    switch (couleur)
    {
        case 1:
            glColor3f(1.0,1.0,1.0);
            break;
        case 4:
            glColor3f(1.0,0.5,0.0);
            break;
        case 3:
            glColor3f(1.0,0.0,0.0);
            break;
        case 5:
            glColor3f(0.0,1.0,0.0);
            break;
        case 2:
            glColor3f(0.0,0.0,1.0);
            break;
        case 6:
            glColor3f(1.0,1.0,0.0);
            break;
    }
}
// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {

    //  Right arrow - increase rotation by 5 degree
    if (key == GLUT_KEY_RIGHT)
    {
        if(rotate_y<0)
            rotate_y = -1;
        rotate_x =0;
        rotate_y += 1;
        cout<<"droite : x : "<<rotate_x<<"y : "<<rotate_y<<" z :"<<rotate_z<<endl;
    }
    else if (key == GLUT_KEY_LEFT)
    {
        if(rotate_y>0)
            rotate_y = -1;
        rotate_x =0;
        rotate_y -= 1;

        cout<<"gauche : x : "<<rotate_x<<"y : "<<rotate_y<<" z : "<<rotate_z<<endl;
    }

    else if (key == GLUT_KEY_UP)
    {
        if(rotate_x<0)
            rotate_x = -1;
        rotate_y = 0;
        rotate_x += 1;
        cout<<"haut : x : "<<rotate_x<<"y : "<<rotate_y<<" z : "<<rotate_z<<endl;
        cube.rotation(3,1);
        cube.affichage();
    }

    else if (key == GLUT_KEY_DOWN)
    {
        if(rotate_x>0)
            rotate_x = 1;
        rotate_y=0;
        rotate_x -= 1;
        cout<<"bas : x : "<<rotate_x<<" y : "<<rotate_y<<" z : "<<rotate_z<<endl;

    }

    //  Request display update
    glutPostRedisplay();

}



void glInit (void)
{
    glEnable (GL_DEPTH_TEST | GL_COLOR_MATERIAL);             //Active la profondeur
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL | GL_LINE);
    // GL_FILL = remplit les polygones
    glShadeModel(GL_SMOOTH); // modèle d'illumination GL_FLAT
    glDepthFunc(GL_LEQUAL); // gestion du Z-Buffer : GL_LESS GL_LEQUAL GL_ALWAYS
    // G L_EQUAL GL_GREATER GL_NOTEQUAL GL_GEQUAL

    // init de la matrice de projection
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // init à la matrice identité
    gluPerspective(45.0f, // angle d'ouverture de la caméra
                   500/500, // ratio de la fenêtre
                   0.1f,2000.0f); // distance min et max de la scène
    // init de la matrice de vue*/

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // init à la matrice identité
    gluLookAt( 10.0f, 10.0f, 10.0f, // position oeil
               0.0f,0.0f,0.0f, // point regardé
               0.0f,1.0f,0.0f); // vecteur haut
}

void drawCube(){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    Piece **tableau = cube.getTableau();



    // Rotate when user changes rotate_x and rotate_y


    for(int cptK=0;cptK<27;cptK++){


        GLfloat x=tableau[cptK]->getX();
        GLfloat y=tableau[cptK]->getY();
        GLfloat z=tableau[cptK]->getZ();

        int couleurHaut    = tableau[cptK]->getHaut();
        int couleurFace    = tableau[cptK]->getFace();
        int couleurGauche  = tableau[cptK]->getGauche();
        int couleurDroite  = tableau[cptK]->getDroite();
        int couleurBas     = tableau[cptK]->getBas();
        int couleurArriere = tableau[cptK]->getArriere();

        // face du dessus  (rouge)
        glBegin(GL_QUADS);
        associateColor(couleurHaut);
        glVertex3f(x-0.95,y,z-0.95);    // A
        glVertex3f(x-0.95,y,z);      // B
        glVertex3f(x,y,z);        // C
        glVertex3f(x,y,z-0.95);      // D
        glEnd();

        // E (x-1, y-1, z)
        // F (x,y-1,z )
        // G(x,y-1,z-1 )
        // H(x-1,y-1,z-1 )

        //face de gauche  (bleu )
        glBegin(GL_QUADS);
        associateColor(couleurGauche);
        glRotated( 0.5, 0.0, 0.0, 1.0 );
        glVertex3f(x-0.95,y,z);    // B
        glVertex3f(x,y,z);      // C
        glVertex3f(x,y-0.95,z);    // E
        glVertex3f(x-0.95,y-0.95,z);  // F
        glEnd();

        //face CDGF
        glBegin(GL_QUADS);
        associateColor(couleurFace);
        glVertex3f(x,y,z); // C
        glVertex3f(x,y,z-0.95); //D
        glVertex3f(x,y-0.95,z-0.95); //G
        glVertex3f(x,y-0.95,z);   //F
        glEnd();

        //face ABEH
        glBegin(GL_QUADS);
        associateColor(couleurArriere);
        glVertex3f(x-0.95,y,z-0.95);    // A
        glVertex3f(x-0.95,y,z);      // B
        glVertex3f(x-0.95,y-0.95,z);    // E
        glVertex3f(x-0.95,y-0.95,z-0.95);  // H
        glEnd();

        //face ADGH
        glBegin(GL_QUADS);
        associateColor(couleurDroite);
        glVertex3f(x-0.95,y,z-0.95);    // A
        glVertex3f(x,y,z-0.95);      // D
        glVertex3f(x,y-0.95,z-0.95 );   //G
        glVertex3f(x-0.95,y-0.95,z-0.95);  // H
        glEnd();

        //face EFGH
        glBegin(GL_QUADS);
        associateColor(couleurBas);
        glVertex3f(x-0.95,y-0.95,z);    // E
        glVertex3f(x,y-0.95,z );     // F
        glVertex3f(x,y-0.95,z-0.95 );   //G
        glVertex3f(x-0.95,y-0.95,z-0.95);  // H
        glEnd();



    }

    glRotatef( rotate_x, 2.0, 0.0, 0.0 );
    //glRotatef( rotate_z, 0.0, 0.0, 2.0 );
    glRotatef( rotate_y, 0.0, 2.0, 0.0 );


    //dessiner un repere
    glPushMatrix();
    glScalef(30,30,30);
    glBegin(GL_LINES);
    glColor3ub(0,0,255); //axe X en bleu
    glVertex3d(0,0,0);
    glVertex3d(1,0,0);
    glColor3ub(0,255,0); //axe Y en vert
    glVertex3d(0,0,0);
    glVertex3d(0,1,0);
    glColor3ub(255,0,0); //axe Z en rouge
    glVertex3d(0,0,0);
    glVertex3d(0,0,1);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
    //glutPostRedisplay();
}