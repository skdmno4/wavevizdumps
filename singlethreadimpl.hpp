#pragma once
#include "localtypes.h"
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const double PI = 3.14159265358979;
double eval(int x, int y, float xDel, float yDel, int t)
{
    double phaseangle = xDel * x + yDel * y;
    return sin(t + phaseangle);
}
void CalculateAndDump(Frame2d<double> *pFrame)
{
    const int ht = pFrame->size();
    const int wd = (*pFrame)[0].size();
    const double xDel = 4*PI/wd;
    const double yDel = 4*PI/ht;
    cout << "Constants: " << xDel << ',' << yDel << '\n';
    static int t = 0;
    t++;
    char flname[40];
    sprintf(flname, "dump_%d.json",t);
    fstream fs;
    fs.open(flname, ios::out);
    fs <<"{";
    for (int y = 0; y < ht; y ++)
    {
        fs <<"{";
        for (int x = 0; x < wd; x ++)
        {
            (*pFrame)[y][x] = eval(x, y, xDel, yDel, t);
            fs << ' ' << (*pFrame)[y][x] << ',';
        }
        fs <<"}\n";
    }
    fs <<"}\n";
    fs.close();
}

void ConvertFormats()
{
    cout << "To be implemented\n";
}
