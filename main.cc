//
// Created by bdelbreuve on 28/05/18.
//

#include <iostream>
#include "Cube.cc"
#include "Piece.cc"

using namespace std;

int main() {

    Cube cube;

    Piece **tableau = cube.getTableau();
    int face = tableau[0]->getFace();

    cout<< "Main " << face << endl;

    tableau[0]->setFace(BLUE);
    face = tableau[0]->getFace();

    cout<< "Main " << face << endl;






}