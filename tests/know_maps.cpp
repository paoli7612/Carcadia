#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    ifstream file("maps/all_maps.txt");
    int n;
    file >> n;
    for (int i=0; i<n; i++)
    {
        string title;
        file >> title;
        cout << title << endl;
    }

    return 0;
}