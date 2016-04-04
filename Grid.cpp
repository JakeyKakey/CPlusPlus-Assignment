//
// Created by Jakey on 16/03/2016.
//

#include "header.h"
#include <iostream>
#include <sys/unistd.h>
#include <w32api/synchapi.h>

using namespace std;


Grid::Grid(int x, int y, double size) {

    gridX = x+2;
    gridY = y+2;
    gridSize = size;
    setUpGrid();
}

Grid::~Grid(){}

void Grid::setUpGrid(){ //defaults all vector values to 0.

    gridMatrix.resize((unsigned long) gridY, vector<int>((unsigned long) gridX));
    
    for (int i = 0; i < gridMatrix.size(); i++) {

        for (int j = 0; j < gridMatrix[0].size(); j++) {

            gridMatrix[i][j] = 0;

        }
    }
}


void Grid::printGrid() {

    // cout << gridMatrix.size() << endl;

    for (int i = gridMatrix.size(); i >= 0; i--) { //flip it upside down

        if (i == 0 || i == gridMatrix.size()) {
            cout << " ";
        } else {
            cout << "| ";
        }

        for (int j = 0; j <= gridMatrix.size(); j++) {

            if (i == 0 or i == gridMatrix.size()) {
                cout << " -";
            } else if (j == gridMatrix.size()) {
                cout << " |";
            } else if (0 <= j && j <= gridX-2 && 0 <= i && i <= gridY-2) {

                if (gridMatrix[i].at(j) != 0) {
                    cout << " " << gridMatrix[i][j];
                } else { cout << "  "; }

            } else { cout << "  "; }

        }

        cout << endl;

    }
}

    void Grid::updateGrid(std::vector<std::vector<int>> XY) {

    int x, y;

    for(int i = 0; i < XY.size(); i++){

        for(int j = 0; j < XY[i].size(); j+=2){ // increments in two's so I can take XY out in pairs

             x = XY[i].at(j);
             y = XY[i].at(j+1);
             addToGrid(x,y);
        }

        printGrid(); // updates per robot position
        Sleep(2000);
        //cout << "NEXT SET" << endl;
    }

  // printGrid(); // prints complete when done
}

void Grid::addToGrid(int x, int y){

    if(gridMatrix[y].at(x) < 9) {  // increases the probability of the obstacle being there from 1 until 9. Double digit values would completely mess up the grid.
        gridMatrix[y].at(x)++;
    }

}

double Grid::getSize(){
    return gridSize;
}