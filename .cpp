#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void vvod(vector<vector<int>>& vec, int m)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            vec[i][j] = rand() % m;
    }
}

void vyvod(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << ' ';

        cout << endl;
    }
    cout << endl;
}

void work(vector<vector<int>> matr, int n) {
    int temp1 = 0, temp2 = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (int i = 0; i < matr.size(); i++) {
        for (int j = 0; j < matr[i].size(); j++) {
            if (i == j && temp1 < matr[i][j]) {
                temp1 = matr[i][j];
                x1 = i;
                y1 = j;
            }
        }
        for (int j = matr[i].size(); j > 0; j--) {
            if (i == j && temp2 < matr[i][j]) {
                temp2 = matr[i][j];
                x2 = i;
                y2 = j;
            }
        }
    }

    if (temp1 > temp2) {
        matr[x1][y1] = matr[(n - 1) / 2][(n - 1) / 2];
        matr[(n - 1) / 2][(n - 1) / 2] = temp1;
    }
    else {
        matr[x2][y2] = matr[(n - 1) / 2][(n - 1) / 2];
        matr[(n - 1) / 2][(n - 1) / 2] = temp2;
    }

    vyvod(matr);
}



int main() {
    srand(time(NULL));
    int n = 5;
    vector<vector<int>> matr(n, vector<int>(n));
    vvod(matr, 100);
    vyvod(matr);
    work(matr, n);


    return 0;
}