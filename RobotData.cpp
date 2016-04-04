//
// Created by Jakey on 16/03/2016.
//


#include <fstream>
#include <iostream>


#include "header.h"


using namespace std;

// Constructors and Destructors

RobotData::RobotData(string a, string b) {
    //filepaths
    pos = a;
    ran = b;
    //cout << "Robot created" << endl;
    readRobot();
    readSensors();
}

RobotData::~RobotData(){}

// Setters and Getters

vector<double> RobotData::getY() {
    return robotY;
}
vector<vector<double>> RobotData::getRanges() {
    return sensorRange;
}
vector<int> RobotData::getYaw() {
    return robotYaw;
}
vector<double> RobotData::getX() {
    return robotX;
}

// File Reading
void RobotData::readRobot(){

    double rX, rY;
    int rYaw;
    ifstream fileRead;
    fileRead.open(pos, ifstream::in);

    if(!fileRead.is_open()) {
        cout << endl << "Failed to open file " << endl;
        return;
    }


    while(!fileRead.eof()){

        if (fileRead.eof()){ break; } // skips the additional redundant loop cycle at the end of the file

        fileRead >> rX >> rY >> rYaw;
        // cout << rX << " " << rY << " " << rYaw << endl;
        robotX.push_back(rX);
        robotY.push_back(rY);
        robotYaw.push_back(rYaw);

    }

    fileRead.close();

}
void RobotData::readSensors(){

    double s1, s2, s3, s4, s5, s6, s7, s8;
    ifstream fileRead;
    fileRead.open(ran, ifstream::in);

    if(!fileRead.is_open()) {
        cout << endl << "Failed to open file " << endl;
        return;
    }

    while(!fileRead.eof()) {

        vector<double> temp;

        if (fileRead.eof()){ break; } // skips the additional redundant loop cycle at the end of the file

        fileRead >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8;
        //cout << s1 << " " << s2 << " " << s3 << " "  << s4 << " "  << s5 << " "  << s6 << " " << s7 << " "  << s8 << endl;
        temp.push_back(s1);
        temp.push_back(s2);
        temp.push_back(s3);
        temp.push_back(s4);
        temp.push_back(s5);
        temp.push_back(s6);
        temp.push_back(s7);
        temp.push_back(s8);
        sensorRange.push_back(temp);
    }

    fileRead.close();

}

// Testing
void RobotData::printRData() {

    for (int i = 0; i < robotX.size(); i++){

        cout << robotX.at(i) << " " << robotY.at(i) << " " << robotYaw.at(i) << endl;

    }

}
void RobotData::printRRanges() {

    for (int i = 0; i < sensorRange.size(); i++) {

        for (int j = 0; j < sensorRange[i].size(); j++) {

            cout << sensorRange[i][j] << " ";

        }

        cout << endl;

    }

}