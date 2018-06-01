//
// Created by bdelbreuve on 30/05/18.
//

#include <iostream>
#include <string>
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
    int face ;

public:
    Cube()
    {
        string name;
        for(int i=0; i<27 ;i++)
        {
            name = "piece"+i;

            tableau[i] = new Piece(name, WHITE,RED,BLUE);

            cout<<tableau[i]->getFace()<<endl;

        }
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

    void rotation( Piece *tableau, Piece p )
    {

    }
};



