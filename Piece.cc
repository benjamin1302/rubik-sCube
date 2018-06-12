#include <iostream>
#include <string>

using namespace std;

#define WHITE 1
#define BLUE 2
#define RED 3
#define ORANGE 4
#define GREEN 5
#define YELLOW 6

// Object : Piece
// Action ; définit les piece qui compoose le cube
class Piece {
private:
    int haut;
    int gauche;
    int face;
    int droite;
    int arriere;
    int bas;
    float x;
    float y;
    float z;
    string name;

public :
    Piece(string name,
          int face, int haut, int gauche,int droite,int bas,int arriere, float x, float y, float z
    )
    {
        this->gauche = gauche;
        this->haut   = haut;
        this->face   = face;
        this->droite = 7-gauche;
        this->bas = 7-haut;
        this->arriere = 7-face;
        this->name   = name;
        this->x      = x;
        this->y      = y;
        this->z      = z;

    }

    //  GETTERS  \\

    int getHaut() const {
        return haut;
    }

    int getGauche()  {
        return gauche;
    }

    int getFace()
    {
        return this->face;
    }
    int getBas() const {
        return bas;
    }

    int getDroite()  {
        return droite;
    }

    int getArriere()
    {
        return this->arriere;
    }

    string getName() {
        return name;
    }

    float getX()
    {
        return this->x;
    }

    float getY()
    {
        return this->y;
    }

    float getZ()
    {
        return this->z;
    }


    // SETTERS \\

    void setGauche(int gauche) {
        this->gauche = gauche;
    }

    void setFace(int face) {
        this->face = face;
    }

    void setHaut(int haut) {
       this->haut = haut;
    }

    void setDroite(int droite) {
        this->droite = droite;
    }

    void setArriere(int arriere) {
        this->arriere = arriere;
    }

    void setBas(int bas) {
        this->bas = bas;
    }

    void setName(string name) {
       this->name = name;
    }





};
