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
    string name;

public :
    Piece(string name, int face, int haut, int gauche)
    {
        this->gauche = gauche;
        this->haut   = haut;
        this->face   = face;
        this->name   = name;
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

    string getName() {
        return name;
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

    void setName(string name) {
       this->name = name;
    }


};
