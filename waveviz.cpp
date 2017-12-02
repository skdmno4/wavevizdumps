#include <iostream>
#include "localtypes.h"
#include "singlethreadimpl.hpp"

using namespace std;
Frame2d<double> g_Points;

bool IsInterrupted()
{
    char choice;
    cout << "CONTINUE? (Y/N): ";
    cin >> choice;
    return choice == 'Y' ? false : (choice == 'y' ? false : true);
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
