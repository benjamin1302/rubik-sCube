//
// Created by bdelbreuve on 30/05/18.
//

#include <iostream>
#include <string>
#import "Piece.cpp"

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
    Piece *faceUne[9];
    Piece *faceDeux[9];
    Piece *faceTrois[9];
    Piece *faceQuatre[9];
    Piece *faceCinq[9];
    Piece *faceSix[9];

public:
    Cube()
    {
        string name;
        for(int i=0; i<27 ;i++)
        {
            name = "piece"+i;

            tableau[i] = new Piece(name, WHITE,RED,BLUE);

            //cout<<tableau[i]->getFace()<<endl;

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
        Piece* save[9];


        switch(face)
        {
            case 1:
            {

                for(i=0;i<9;i++)
                {
                    save[i]=faceUne[i];
                }


                //int save;
                //save=tableau[6]->getHaut();
                tableau[0]->setFace(save[6]->getFace());
                tableau[0]->setHaut(7-save[6]->getGauche());
                tableau[0]->setGauche(save[6]->getHaut());



                break;
            }


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

    void affichage()
    {
        int face,gauche,haut;
        for(int i=0;i<27;i++)
        {
            face=tableau[i]->getFace();
            haut=tableau[i]->getHaut();
            gauche=tableau[i]->getGauche();
            cout<<"Piece "<<i<<" face:"<<conversionIntCouleur(face)<<" haut:"<<conversionIntCouleur(haut)<<" gauche:"<<conversionIntCouleur(gauche)<<endl;
        }
    }

};


