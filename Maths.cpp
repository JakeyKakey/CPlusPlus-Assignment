
#define _USE_MATH_DEFINES
#include "header.h"
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

Maths::Maths(){}
Maths::~Maths(){}


double Maths::radConvert(int degrees){

    return degrees * (M_PI / 180);

}

void Maths::calculateData(vector<double> x, vector<double> y, vector<int> yaw, vector<std::vector<double>> ranges){

    int offset; 
    int totalAngle;
    int tempX, tempY;
    for (int i = 0; i < x.size(); i++){

        vector<int> temp;
                    
                    for (int j = 0; j < ranges[i].size(); j++){

                        offset = (j * 45); // since sensors are spaces evenly apart by 45 degrees, this automatically calculates the offset, 0*45=0, 1*45=45, 2*45=90 etc
                        totalAngle = offset + yaw.at(i); 
                        tempX = calculateX(x.at(i),radConvert(totalAngle),ranges[i].at(j));
                        tempY = calculateY(y.at(i),radConvert(totalAngle),ranges[i].at(j));

                        if(ranges[i].at(j) < 2.5){
                            //cout << ranges[i].at(j) << endl;
                              if(tempX > 0 && tempY > 0 && tempX < 50 && tempY < 50){
                                  temp.push_back(tempX);                                // It's easier to push back X and Y to the same vector and just extract in pairs afterwards
                                  temp.push_back(tempY);                               // than it is to store separate X/Y values in an awkward 3D vector.
                                  //cout << tempX << ", " << tempY << endl;
                               }
                        }
                    }

        gridXY.push_back(temp); //

    }

}

int Maths::calculateX(double rX, double angle, double range){

    rX = rX/scale; range = range/scale;
    int result = floor(rX + range * cos(angle)); // technically the double to int cast would automatically do a floor()-like
    return result;                               //  round down anyway, but better safe than sorry.

}

int Maths::calculateY(double rY, double angle, double range){

    rY = rY/scale; range = range/scale;
    int result = floor(rY + range * sin(angle)); // see right above
    return result;

}

vector<vector<int>> Maths::getGridXY() {
    return gridXY;
}

void Maths::setScale(double s){
    scale = s;
}