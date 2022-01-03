#include <iostream>
#include <vector>
#include "List.h"

using namespace std;

const int N = 10;

void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    arr.clear();
}

void recordRightDiagonal(int** matrix, vector<int>& arr)
{
    int i = 0, iIter = 1, j = N, jIter = j;

    while (i < N)
    {
        i = 0, j--, jIter = j;
        while (jIter < N)
        {
            arr.push_back(matrix[i][jIter]);
            i++;
            jIter++;
        }
    }

    i = 0;

    while (i != N)
    {
        j = 0, i++, iIter = i, jIter = j;
        while (iIter < N || j != 0)
        {
            arr.push_back(matrix[iIter][jIter]);
            jIter++;
            iIter++;
        }
    }
    printVector(arr);
}

void recordLeftDiagonal(int** matrix, vector<int>& arr)
{
    int i = 0, iIter = 1, j = -1, jIter = j;

    while (i < N)
    {
        i = 0, j++, jIter = j;
        while (jIter >= 0)
        {
            arr.push_back(matrix[i][jIter]);
            i++;
            jIter--;
        }
    }

    i = 0;

    while (i != N)
    {
        j = N - 1, i++, iIter = i, jIter = j;
        while (iIter < N)
        {
            arr.push_back(matrix[iIter][jIter]);
            jIter--;
            iIter++;
        }
    }
    printVector(arr);
}

void recordCoilMatrix(int** matrix, vector<int>& arr)
{
    int iIter = N / 2;
    int jIter = N / 2;

    int iStep = 1;
    int jStep = 1;

    cout << matrix[iIter][jIter] << " ";
    for (int i = 0; i < N; i++)
    {
        for (int m = 0; m < i; m++) arr.push_back(matrix[iIter += iStep][jIter]);
        for (int k = 0; k < i; k++) arr.push_back(matrix[iIter][jIter += jStep]);
        jStep = -jStep;
        iStep = -iStep;
    }
    for (int k = 0; k < N - 1; k++)
        arr.push_back(matrix[iIter += iStep][jIter]);
    printVector(arr);
}

void recordCoilMatrixS(int** matrix, vector<int>& arr)
{
    int iIter = 0;
    int jIter = -1;

    int iStep = 1;
    int jStep = 1;

    for (int i = N - 1; i >= 0; i--)
    {
        for (int k = -1; k < i; k++) arr.push_back(matrix[iIter][jIter += jStep]);
        for (int m = 0; m < i; m++) arr.push_back(matrix[iIter += iStep][jIter]);
        jStep = -jStep;
        iStep = -iStep;
    }
    printVector(arr);
}

void randSizeMatrix()
{
    int n = rand() % 10 + 2, m = rand() % 10 + 2;
    int** matrix = new int* [n];

    for (int i = 0; i < n; i++)
    {
        cout << "\t" << "\t" << "\t" << "\t" << "    ";
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 100;
            printf("%3d ", matrix[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));
    int** matrix = new int* [N];
    vector<int> arr;

    for (int i = 0; i < N; i++)
    {
        cout << "\t" << "\t" << "\t" << "\t" << "    ";
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = /*rand() % 100*/ i * N + j;
            printf("%3d ", matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    cout << "-----------------------------------------------------1-----------------------------------------------------" << endl;
    recordRightDiagonal(matrix, arr);
    cout << "-----------------------------------------------------2-----------------------------------------------------" << endl;
    recordLeftDiagonal(matrix, arr);
    cout << "-----------------------------------------------------3-----------------------------------------------------" << endl;
    recordCoilMatrix(matrix, arr);
    cout << "-----------------------------------------------------4-----------------------------------------------------" << endl;
    recordCoilMatrixS(matrix, arr);
    cout << "-----------------------------------------------------5-----------------------------------------------------" << endl;
    randSizeMatrix();

    Queue a;
    list* b = new list;
    a.push_back(b);
    try
    {
        /*throw 1;
        throw 2;*/
        a.pop_front();
        a.Next();
    }
    catch (int code)
    {
        if (code == 1)
            cout << endl << "List already empty! (Queue)";
        if (code == 2)
            cout << endl << "Going beyond the boundaries of memory! (Queue)";
    }

    Stack c;
    list* g = new list;
    c.push_front(g);
    try
    {
        /*throw 1;
        throw 2;*/
        c.pop_front();
        c.Next();
    }
    catch (int code)
    {
        if (code == 1)
            cout << endl << "List already empty! (Stack)";
        if (code == 2)
            cout << endl << "Going beyond the boundaries of memory! (Stack)";
    }
}