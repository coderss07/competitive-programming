#include<bits/stdc++.h>

using namespace std;

void floofFill(char a[][10], int i, int j, char tofill, char prevfill)
{
    if (i < 0 || i >= 10 || j < 0 || j > 10)
        return;
    if (a[i][j] != prevfill)
        return;
    a[i][j] = tofill;
    floofFill(a, i - 1, j, tofill, prevfill);
    floofFill(a, i, j - 1, tofill, prevfill);
    floofFill(a, i + 1, j, tofill, prevfill);
    floofFill(a, i, j + 1, tofill, prevfill);
}
int main()
{
    char a[10][10] = {{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                      {'1', '1', '1', '1', '2', '2', '2', '2', '1', '1'},
                      {'1', '1', '1', '1', '2', '1', '1', '2', '1', '1'},
                      {'1', '1', '1', '1', '2', '1', '1', '2', '1', '1'},
                      {'1', '1', '2', '2', '2', '1', '1', '2', '1', '1'},
                      {'1', '1', '2', '2', '1', '1', '1', '2', '1', '1'},
                      {'1', '1', '1', '2', '1', '1', '1', '1', '1', '1'},
                      {'1', '2', '2', '2', '2', '2', '2', '2', '2', '2'},
                      {'1', '1', '1', '1', '1', '1', '1', '1', '1', '2'},
                      {'1', '2', '2', '2', '1', '1', '1', '1', '1', '2'}};
    int r = 1, c = 4;
    floofFill(a, r, c, '#', '2');
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}
