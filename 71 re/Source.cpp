#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** d, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** d, const int rowCount, const int colCount, int i, int j);
void Sort(int** d, const int rowCount, const int colCount, int i0, int i1);
void Change(int** d, int row1, int row2, int colCount, int j);
void Calc(int** d, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main()
{
    srand(static_cast<unsigned>(time(NULL)));

    int Low = -31;
    int High = 54;

    int rowCount = 9;
    int colCount = 5;

    int** d = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        d[i] = new int[colCount];

    Create(d, rowCount, colCount, Low, High, 0, 0);
    Print(d, rowCount, colCount, 0, 0);
    Sort(d, rowCount, colCount, 0, 0);
    Print(d, rowCount, colCount, 0, 0);

    int S = 0;
    int k = 0;
    Calc(d, rowCount, colCount, S, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(d, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] d[i];
    delete[] d;

    return 0;
}

void Create(int** d, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i < rowCount)
    {
        if (j < colCount)
        {
            d[i][j] = Low + rand() % (High - Low + 1);
            Create(d, rowCount, colCount, Low, High, i, j + 1);
        }
        else
        {
            Create(d, rowCount, colCount, Low, High, i + 1, 0);
        }
    }
}

void Print(int** d, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << d[i][j];
    if (j < colCount - 1)
        Print(d, rowCount, colCount, i, j + 1);
    else
        if (i < rowCount - 1)
        {
            cout << endl;
            Print(d, rowCount, colCount, i + 1, 0);
        }
        else
            cout << endl << endl;
}


void Sort(int** d, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 < rowCount - 1)
    {
        if (i1 < rowCount - i0 - 1)
        {
            if ((d[i1][0] > d[i1 + 1][0])
                ||
                (d[i1][0] == d[i1 + 1][0] &&
                    d[i1][1] < d[i1 + 1][1])
                ||
                (d[i1][0] == d[i1 + 1][0] &&
                    d[i1][1] == d[i1 + 1][1] &&
                    d[i1][3] > d[i1 + 1][3]))
            {
                Change(d, i1, i1 + 1, colCount, 0);
            }
            Sort(d, rowCount, colCount, i0, i1 + 1);
        }
        else
        {
            Sort(d, rowCount, colCount, i0 + 1, 0);
        }
    }
}

void Change(int** d, int row1, int row2, int colCount, int j)
{
    if (j < colCount)
    {
        int tmp = d[row1][j];
        d[row1][j] = d[row2][j];
        d[row2][j] = tmp;
        Change(d, row1, row2, colCount, j + 1);
    }
}

void Calc(int** d, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (i < rowCount)
    {
        if (j < colCount)
        {
            if (d[i][j] > 0 && !(d[i][j] % 5 == 0))
            {
                S += d[i][j];
                k++;
                d[i][j] = 0;
            }
            Calc(d, rowCount, colCount, S, k, i, j + 1);
        }
        else
        {
            Calc(d, rowCount, colCount, S, k, i + 1, 0);
        }
    }
}
