#include <iostream>

using namespace std;

int main()
{
    const int WIDTH = 4, HEIGHT = 2;
    int mat[HEIGHT][WIDTH];

    // Metto tutto a 0
    for (int y=0; y<HEIGHT; y++)
        for (int x=0; x<WIDTH; x++)
            mat[y][x] = 0;

    mat[1][1] = 7;

    // Stampo
    for (int y=0; y<HEIGHT; y++){
        for (int x=0; x<WIDTH; x++)
            cout << mat[y][x] << " ";
        cout << endl;
    }

    return 0;
}