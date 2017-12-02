#include <iostream>
#include "localtypes.h"
#ifdef SINGLE
#include "singlethreadimpl.hpp"
#elif ASY
#include "asyncimpl.hpp"
#endif

using namespace std;
Frame2d<double> g_Points;
const int g_TotalFrames=30;

bool IsInterrupted()
{
    /*
    char choice;
    cout << "CONTINUE? (Y/N): ";
    cin >> choice;
    return choice == 'Y' ? false : (choice == 'y' ? false : true);
    */
    static int hits = 0;
    hits++;
    return hits < g_TotalFrames + 1 ? false : true; 
}

void ConvertFormats();
void Initialize();
int main()
{
    bool finish = false;
    Initialize();
    do
    {
        CalculateAndDump(&g_Points);
        finish = IsInterrupted();
    } while(!finish);

   ConvertFormats();
}

int GetWidth()
{
    return 640;
}

int GetHeight()
{
    return 480;
}

void Initialize()
{
    const int wd = GetWidth();
    const int ht = GetHeight();
    g_Points.resize(ht);
    for (auto & x : g_Points)
    {
        x.resize(wd);
    }
}
