#pragma once
#include <vector>
#include "cell.h"
#include <iostream>

using namespace std;
class Matrix
{
public:
    Matrix(int n);
    int n;
    std::vector<std::vector<Cell>> container;
    void dotMul(Matrix m);
    void findMin(int index);//0���У�1���У�2��Ϊ���ǵ�
    void print();
    void findZero();
};

int countZero(vector<Cell> ls);
void cover(vector<Cell> &ls);