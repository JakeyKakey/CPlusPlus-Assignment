//
// Created by Jakey on 16/03/2016.
//

#ifndef JAKUB_CS_HEADER_H
#define JAKUB_CS_HEADER_H

#include <vector>
#include <fstream>
#include <string>

class RobotData {

private:
    std::vector<double> robotX;
    std::vector<double> robotY;
    std::vector<int> robotYaw;
    std::vector<std::vector<double>> sensorRange;
    std::string pos, ran;

    void readRobot();
    void readSensors();

public:
    RobotData(std::string, std::string);
    ~RobotData();

    void printRData();
    void printRRanges();

    std::vector<double> getX();
    std::vector<double> getY();
    std::vector<std::vector<double>> getRanges();
    std::vector<int> getYaw();

};

class Maths{

private:
    std::vector<std::vector<int>> gridXY;
    double scale;
    double radConvert(int);
    int calculateX(double, double, double);
    int calculateY(double, double, double);

public:
    Maths();
    ~Maths();
    void calculateData(std::vector<double>, std::vector<double>, std::vector<int>, std::vector<std::vector<double>>);
    std::vector<std::vector<int>> getGridXY();

    void setScale(double s);
};

class Grid {

private:
    int gridY, gridX;
    double gridSize;
    std::vector<std::vector<int>> gridMatrix;
    void setUpGrid();
public:
    Grid(int,int,double);
    ~Grid();
    void updateGrid(std::vector<std::vector<int>>);
    void addToGrid(int,int);
    void printGrid();

    double getSize();
};

#endif //JAKUB_CS_HEADER_H
