//
// Created by bdelbreuve on 30/05/18.
//

#include <iostream>
#include <string>

#include <GL/gl.h>
#include <GL/glut.h>

#import "Piece.cc"

using namespace std;

#define WHITE 1
#define BLUE 2
#define RED 3
#define ORANGE 4
#define GREEN 5
#define YELLOW 6

class Cube
{
private:
    Piece *tableau[27];
    Piece *save[27];
    Piece *faceUne[9];
    Piece *faceDeux[9];
    Piece *faceTrois[9];
    Piece *faceQuatre[9];
    Piece *faceCinq[9];
    Piece *faceSix[9];
    // Piece *save[9];

public:
    Cube()
    {
        int index = 0;
        string name;
        //creation des pieces
        for(float z=0.0; z<3; z++)
        {
            for (float y = 0.0; y <3 ; ++y)
            {
                for (float x = 0.0; x <3 ; ++x) {
                    name = "piece"+index;
                    tableau[index] = new Piece(name, WHITE,RED,BLUE,GREEN,ORANGE,YELLOW,x,y,z);
                    index++;
                }
            }

        }
        for (int i=0; i<9; i++)
        {
            faceUne[i] = tableau[i];
            faceDeux[i] = tableau[3*i + 1];
            faceCinq[i] = tableau[3*(i+1)];
            faceSix[i] = tableau[27-i];
        }
        faceTrois[0] = tableau[8];
        faceTrois[1] = tableau[9];
        faceTrois[2] = tableau[10];
        faceTrois[3] = tableau[15];
        faceTrois[4] = tableau[16];
        faceTrois[5] = tableau[17];
        faceTrois[6] = tableau[24];
        faceTrois[7] = tableau[25];
        faceTrois[8] = tableau[26];
        faceQuatre[0] = tableau[0];
        faceQuatre[1] = tableau[1];
        faceQuatre[2] = tableau[2];
        faceQuatre[3] = tableau[9];
        faceQuatre[4] = tableau[10];
        faceQuatre[5] = tableau[11];
        faceQuatre[6] = tableau[19];
        faceQuatre[7] = tableau[19];
        faceQuatre[8] = tableau[20];
    }


    virtual ~Cube()
    {
        for(int i=0 ; i<27 ; i++)
        {
            delete  tableau[i];
        }
    }

    Piece** getTableau()
    {
        return this->tableau;
    }

    void rotation(int face, int sens)
    {
        int i;
        int test;
        int sauvegarde[27][3];
        //cout<<"fonction rotation"<<endl;
        /*
        for(i=0;i<27;i++)
        {
            save[i]=tableau[i];
        }
        */
        for(i=0;i<27;i++)
        {
            sauvegarde[i][0]=tableau[i]->getFace();
            sauvegarde[i][1]=tableau[i]->getHaut();
            sauvegarde[i][2]=tableau[i]->getGauche();
        }


        switch(face)
        {
            //WHITE
            case 1:
            {
                tableau[0]->setFace(sauvegarde[6][0]);
                tableau[0]->setHaut(7-sauvegarde[6][2]);
                tableau[0]->setGauche(sauvegarde[6][1]);

                tableau[1]->setFace(sauvegarde[3][0]);
                tableau[1]->setHaut(7-sauvegarde[3][2]);
                tableau[1]->setGauche(sauvegarde[3][1]);

                tableau[2]->setFace(sauvegarde[0][0]);
                tableau[2]->setHaut(7-sauvegarde[0][2]);
                tableau[2]->setGauche(sauvegarde[0][1]);

                tableau[3]->setFace(sauvegarde[7][0]);
                tableau[3]->setHaut(7-sauvegarde[7][2]);
                tableau[3]->setGauche(sauvegarde[7][1]);

                tableau[4]->setFace(sauvegarde[4][0]);
                tableau[4]->setHaut(7-sauvegarde[4][2]);
                tableau[4]->setGauche(sauvegarde[4][1]);

                tableau[5]->setFace(sauvegarde[1][0]);
                tableau[5]->setHaut(7-sauvegarde[1][2]);
                tableau[5]->setGauche(sauvegarde[1][1]);

                tableau[6]->setFace(sauvegarde[8][0]);
                tableau[6]->setHaut(7-sauvegarde[8][2]);
                tableau[6]->setGauche(sauvegarde[8][1]);

                tableau[7]->setFace(sauvegarde[5][0]);
                tableau[7]->setHaut(7-sauvegarde[5][2]);
                tableau[7]->setGauche(sauvegarde[5][1]);

                tableau[8]->setFace(sauvegarde[2][0]);
                tableau[8]->setHaut(7-sauvegarde[2][2]);
                tableau[8]->setGauche(sauvegarde[2][1]);

                break;
            }
                //BLUE
            case 2:
            {
                tableau[0]->setFace(7-sauvegarde[18][1]);
                tableau[0]->setHaut(sauvegarde[18][0]);
                tableau[0]->setGauche(sauvegarde[18][2]);

                tableau[3]->setFace(7-sauvegarde[9][1]);
                tableau[3]->setHaut(sauvegarde[9][0]);
                tableau[3]->setGauche(sauvegarde[9][2]);

                tableau[6]->setFace(7-sauvegarde[0][1]);
                tableau[6]->setHaut(sauvegarde[0][0]);
                tableau[6]->setGauche(sauvegarde[0][2]);

                tableau[9]->setFace(7-sauvegarde[21][1]);
                tableau[9]->setHaut(sauvegarde[21][0]);
                tableau[9]->setGauche(sauvegarde[21][2]);

                tableau[12]->setFace(7-sauvegarde[12][1]);
                tableau[12]->setHaut(sauvegarde[12][0]);
                tableau[12]->setGauche(sauvegarde[12][2]);

                tableau[15]->setFace(7-sauvegarde[3][1]);
                tableau[15]->setHaut(sauvegarde[3][0]);
                tableau[15]->setGauche(sauvegarde[3][2]);

                tableau[18]->setFace(7-sauvegarde[24][1]);
                tableau[18]->setHaut(sauvegarde[24][0]);
                tableau[18]->setGauche(sauvegarde[24][2]);

                tableau[21]->setFace(7-sauvegarde[15][1]);
                tableau[21]->setHaut(sauvegarde[15][0]);
                tableau[21]->setGauche(sauvegarde[15][2]);

                tableau[24]->setFace(7-sauvegarde[6][1]);
                tableau[24]->setHaut(sauvegarde[6][0]);
                tableau[24]->setGauche(sauvegarde[6][2]);

                break;
            }
                //RED
            case 3:
            {
                tableau[6]->setFace(sauvegarde[24][2]);
                tableau[6]->setHaut(sauvegarde[24][1]);
                tableau[6]->setGauche(7-sauvegarde[24][0]);

                tableau[7]->setFace(sauvegarde[15][2]);
                tableau[7]->setHaut(sauvegarde[15][1]);
                tableau[7]->setGauche(7-sauvegarde[15][0]);

                tableau[8]->setFace(sauvegarde[6][2]);
                tableau[8]->setHaut(sauvegarde[6][1]);
                tableau[8]->setGauche(7-sauvegarde[6][0]);

                tableau[15]->setFace(sauvegarde[25][2]);
                tableau[15]->setHaut(sauvegarde[25][1]);
                tableau[15]->setGauche(7-sauvegarde[25][0]);

                tableau[16]->setFace(sauvegarde[16][2]);
                tableau[16]->setHaut(sauvegarde[16][1]);
                tableau[16]->setGauche(7-sauvegarde[16][0]);

                tableau[17]->setFace(sauvegarde[7][2]);
                tableau[17]->setHaut(sauvegarde[7][1]);
                tableau[17]->setGauche(7-sauvegarde[7][0]);

                tableau[24]->setFace(sauvegarde[26][2]);
                tableau[24]->setHaut(sauvegarde[26][1]);
                tableau[24]->setGauche(7-sauvegarde[26][0]);

                tableau[25]->setFace(sauvegarde[17][2]);
                tableau[25]->setHaut(sauvegarde[17][1]);
                tableau[25]->setGauche(7-sauvegarde[17][0]);

                tableau[26]->setFace(sauvegarde[8][2]);
                tableau[26]->setHaut(sauvegarde[8][1]);
                tableau[26]->setGauche(7-sauvegarde[8][0]);

                break;
            }
                //ORANGE
            case 4:
            {
                tableau[0]->setFace(sauvegarde[18][2]);
                tableau[0]->setHaut(sauvegarde[18][1]);
                tableau[0]->setGauche(7-sauvegarde[18][0]);

                tableau[1]->setFace(sauvegarde[9][2]);
                tableau[1]->setHaut(sauvegarde[9][1]);
                tableau[1]->setGauche(7-sauvegarde[9][0]);

                tableau[2]->setFace(sauvegarde[0][2]);
                tableau[2]->setHaut(sauvegarde[0][1]);
                tableau[2]->setGauche(7-sauvegarde[0][0]);

                tableau[9]->setFace(sauvegarde[19][2]);
                tableau[9]->setHaut(sauvegarde[19][1]);
                tableau[9]->setGauche(7-sauvegarde[19][0]);

                tableau[10]->setFace(sauvegarde[10][2]);
                tableau[10]->setHaut(sauvegarde[10][1]);
                tableau[10]->setGauche(7-sauvegarde[10][0]);

                tableau[11]->setFace(sauvegarde[1][2]);
                tableau[11]->setHaut(sauvegarde[1][1]);
                tableau[11]->setGauche(7-sauvegarde[1][0]);

                tableau[18]->setFace(sauvegarde[20][2]);
                tableau[18]->setHaut(sauvegarde[20][1]);
                tableau[18]->setGauche(7-sauvegarde[20][0]);

                tableau[19]->setFace(sauvegarde[11][2]);
                tableau[19]->setHaut(sauvegarde[11][1]);
                tableau[19]->setGauche(7-sauvegarde[11][0]);

                tableau[20]->setFace(sauvegarde[2][2]);
                tableau[20]->setHaut(sauvegarde[2][1]);
                tableau[20]->setGauche(7-sauvegarde[2][0]);

                break;
            }
                //GREEN
            case 5:
            {
                tableau[2]->setFace(sauvegarde[8][1]);
                tableau[2]->setHaut(7-sauvegarde[8][0]);
                tableau[2]->setGauche(sauvegarde[8][2]);

                tableau[5]->setFace(sauvegarde[17][1]);
                tableau[5]->setHaut(7-sauvegarde[17][0]);
                tableau[5]->setGauche(sauvegarde[17][2]);

                tableau[8]->setFace(sauvegarde[26][1]);
                tableau[8]->setHaut(7-sauvegarde[26][0]);
                tableau[8]->setGauche(sauvegarde[26][2]);

                tableau[11]->setFace(sauvegarde[5][1]);
                tableau[11]->setHaut(7-sauvegarde[5][0]);
                tableau[11]->setGauche(sauvegarde[5][2]);

                tableau[14]->setFace(sauvegarde[14][1]);
                tableau[14]->setHaut(7-sauvegarde[14][0]);
                tableau[14]->setGauche(sauvegarde[14][2]);

                tableau[17]->setFace(sauvegarde[23][1]);
                tableau[17]->setHaut(7-sauvegarde[23][0]);
                tableau[17]->setGauche(sauvegarde[23][2]);

                tableau[20]->setFace(sauvegarde[2][1]);
                tableau[20]->setHaut(7-sauvegarde[2][0]);
                tableau[20]->setGauche(sauvegarde[2][2]);

                tableau[23]->setFace(sauvegarde[11][1]);
                tableau[23]->setHaut(7-sauvegarde[11][0]);
                tableau[23]->setGauche(sauvegarde[11][2]);

                tableau[26]->setFace(sauvegarde[20][1]);
                tableau[26]->setHaut(7-sauvegarde[20][0]);
                tableau[26]->setGauche(sauvegarde[20][2]);

                break;
            }
                //yellow
            case 6:
            {
                tableau[18]->setFace(sauvegarde[24][0]);
                tableau[18]->setHaut(7-sauvegarde[24][2]);
                tableau[18]->setGauche(sauvegarde[24][1]);

                tableau[19]->setFace(sauvegarde[21][0]);
                tableau[19]->setHaut(7-sauvegarde[21][2]);
                tableau[19]->setGauche(sauvegarde[21][1]);

                tableau[20]->setFace(sauvegarde[18][0]);
                tableau[20]->setHaut(7-sauvegarde[18][2]);
                tableau[20]->setGauche(sauvegarde[18][1]);

                tableau[21]->setFace(sauvegarde[25][0]);
                tableau[21]->setHaut(7-sauvegarde[25][2]);
                tableau[21]->setGauche(sauvegarde[25][1]);

                tableau[22]->setFace(sauvegarde[22][0]);
                tableau[22]->setHaut(7-sauvegarde[22][2]);
                tableau[22]->setGauche(sauvegarde[22][1]);

                tableau[23]->setFace(sauvegarde[19][0]);
                tableau[23]->setHaut(7-sauvegarde[19][2]);
                tableau[23]->setGauche(sauvegarde[19][1]);

                tableau[24]->setFace(sauvegarde[26][0]);
                tableau[24]->setHaut(7-sauvegarde[26][2]);
                tableau[24]->setGauche(sauvegarde[26][1]);

                tableau[25]->setFace(sauvegarde[23][0]);
                tableau[25]->setHaut(7-sauvegarde[23][2]);
                tableau[25]->setGauche(sauvegarde[23][1]);

                tableau[26]->setFace(sauvegarde[20][0]);
                tableau[26]->setHaut(7-sauvegarde[20][2]);
                tableau[26]->setGauche(sauvegarde[20][1]);

                break;
            }
            default:
                cout<<"Erreur fonction rotation (numero de face en argument inconnu)"<<endl;
        }
    }

    char* conversionIntCouleur(int face)
    {
        switch(face)
        {
            case 1:
                return "WHITE";
                break;
            case 2:
                return "BLUE";
                break;
            case 3:
                return "RED";
                break;
            case 4:
                return "ORANGE";
                break;
            case 5:
                return "GREEN";
                break;
            case 6:
                return "YELLOW";
                break;
            default:
                cout<<"Erreur fonction conversion IntCouleur"<<endl;
        }
    }
    void melange()
    {
        srand(time(NULL));
        for (int j = 1; j < 4; j++)
        {
            int rotRand = rand()%4;
            for (int i = 0; i < rotRand; i++)
            {
                this->rotation(WHITE,1);
                cout<<"------------Rotation de la face BLANCHE---------"<<endl;
            }
            rotRand = rand()%4;
            for (int i = 0; i < rotRand; i++)
            {
                this->rotation(BLUE,1);
                cout<<"------------Rotation de la face BLEUE---------"<<endl;
            }
            rotRand = rand()%4;
            for (int i = 0; i < rotRand; i++)
            {
                this->rotation(RED,1);
                cout<<"------------Rotation de la face ROUGE---------"<<endl;
            }
            rotRand = rand()%4;
            for (int i = 0; i < rotRand; i++)
            {
                this->rotation(ORANGE,1);
                cout<<"------------Rotation de la face ORANGE---------"<<endl;
            }
            rotRand = rand()%4;
            for (int i = 0; i < rotRand; i++)
            {
                this->rotation(GREEN,1);
                cout<<"------------Rotation de la face GREEN----------"<<endl;
            }
            rotRand = rand()%4;
            for (int i = 0; i < rotRand; i++)
            {
                this->rotation(YELLOW,1);
                cout<<"------------Rotation de la face YELLOW--------"<<endl;
            }
        }
    }

    void affichage()
    {
        int face,gauche,haut;
        for(int i=0;i<27;i++)
        {
            face=tableau[i]->getFace();
            haut=tableau[i]->getHaut();
            gauche=tableau[i]->getGauche();
            cout<<"Piece "<<i<<" face:"<<conversionIntCouleur(face)<<" haut:"<<conversionIntCouleur(haut)<<" gauche:"<<conversionIntCouleur(gauche);
            cout<<" arriere:"<<conversionIntCouleur(7-face)<<" bas:"<<conversionIntCouleur(7-haut)<<" droite:"<<conversionIntCouleur(7-gauche)<<endl;
        }
    }



};
