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

    int getX()
    {
        return this->x;
    }

    int getY()
    {
        return this->y;
    }

    int getHaut()
    {
        return this->haut;
    }

    int getGauche()
    {
        return this->gauche;
    }

    int getZ()
    {
        return this->z;
    }


};
