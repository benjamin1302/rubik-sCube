#include <iostream>
#include <string>

using namespace std;
// Object : Piece
// Action ; définit les piece qui compoose le cube
class Piece {
private:
    int x;
    int y;
    int z;
    int haut;
    int gauche;

public :
    Piece(int x, int y, int z, int haut, int gauche)
    {
        this->gauche = gauche;
        this->haut   = haut;
        this->x      = x;
        this->y      = y;
        this->z      = z;
    }

    //  GETTERS  \\

    int getHaut() const {
        return haut;
    }

    int getGauche() const {
        return gauche;
    }

    int getZ() const {
        return z;
    }

    int getY() const {
        return y;
    }

    // SETTERS \\

    void setX(int x) {
        Piece::x = x;
    }

    void setY(int y) {
        Piece::y = y;
    }

    void setZ(int z) {
        Piece::z = z;
    }

    void setHaut(int haut) {
        Piece::haut = haut;
    }




};
