#include <iostream>
#include "header.h"

using namespace std;

int main() {

    RobotData robot("C:\\Users\\Jakey\\Dropbox\\Computer Science\\Jakub CS\\poses.txt", "C:\\Users\\Jakey\\Dropbox\\Computer Science\\Jakub CS\\ranges.txt"); // really doesn't seem to like relative filepaths
    Grid grid(50,50,0.2);                                                                                                                                     // change it to an absolute of your own choosing
    Maths m;
    m.setScale(grid.getSize());
    m.calculateData(robot.getX(),robot.getY(),robot.getYaw(),robot.getRanges());
    grid.updateGrid(m.getGridXY());

    //Test Methods
    //grid.printGrid();
    //robot.printRData();
    //robot.printRRanges();

    return 0;
}