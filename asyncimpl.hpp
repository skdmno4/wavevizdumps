#pragma once
#include <future>
#include <cmath>
#include <fstream>
#include <vector>
#include "localtypes.h"
using namespace std;

const double PI = 3.14159265358979;
void ConvertFormats()
{
    cout << "To be implemented\n";
}
double eval(int x, int y, float xDel, float yDel, int t)
{
    double phaseangle = xDel * x + yDel * y;
    return sin(t + phaseangle);
}
void roweval(vector <double> *pRow, int y, float xDel, float yDel, int t)
{
    for (uint32 i = 0; i < pRow->size(); i++)
    {
        (*pRow)[i] = eval(i, y, xDel, yDel, t);
    }
}
void CalculateAndDump(Frame2d<double> *pFrame)
{
    vector<std::future<void>> ftr;
    const int ht = pFrame->size();
    const int wd = (*pFrame)[0].size();
    const double xDel = 4*PI/wd;
    const double yDel = 4*PI/ht;
    static int t = 0;
    t++;
    char flname[40];
    sprintf(flname, "dump_asy_%d.json",t);
    fstream fs;
    fs.open(flname, ios::out);
    for (int y = 0; y < ht; y ++)
    {
        vector<double> *pRow = &(*pFrame)[y];
        ftr.push_back(std::async(roweval, pRow, y, xDel, yDel, t));
    }
    for (auto &f : ftr)
    {
        f.get();
    }

    fs <<"{";
    for (int y = 0; y < ht; y ++)
    {
        fs <<"{";
        for (int x = 0; x < wd; x ++)
        {
            fs << ' ' << (*pFrame)[y][x] << ',';
        }
        fs <<"}\n";
    }
    fs.close();
}
